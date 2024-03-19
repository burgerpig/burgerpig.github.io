## II. Notes from <CPP Programming Language 4th>

### 1. Introductions

#### 1.1 Basics

brackets can also be used to initialize parameters in the constructor.

```c++
class Test {
public:
	double *ele;
    int s;
    Test(int x): ele {new double[x]}, s(x) {}
};
```

- functions defined in a class are **inlined by default.**
- **const** secifiers for the functions in class means the function do not modify the objects.

```c++
class Test{
	void func() const {}
}
```

- enum 没用过

```c++
enum class Color {Red, Yellow, Blue};
// plain enum, is an integer intrinsically
enum Shape {trapezoid, rhombus, parallelogram};
```

- 惊呆，`+=`operator返回的是left-value

```c++
T &operator+=(T)
```

the following code is legal

```c++
int a = 0;
(a+=3)++;
```

- 在作用域结束时，调用destructor

```c++
// 
int main(){
    Test t2;
    {
        Test t1;
        // for t1, ~Test() is called here
    }
    
    // for t2, ~Test() is called here
}
```

- RAII(Resource Acquisition is Initilization): acquiring resources in a constructor, and releasing them in a destructor.
- `std::initializer_list<T>`, used for const bracket-list parameters in constructor.

```C++
template<class T>
struct S
{
    std::vector<T> v;
 
    S(std::initializer_list<T> l) : v(l)
    {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
};

void func() {
    //...
    S<int> s = {1, 2, 3, 4, 5};
}

```

- **abstract class and pure virtual function**
  - 对于virutal function = 0, 代表纯虚函数，it denotes that those class derived from the base must implement this function.
  - 有虚函数的类，就是abstract class. 
  - create an object of abstrct class is **illegal**.

```c++
class Container {
public:
	virtual double &operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
}
```

- derivatives有三种形式，public, private, protected, default is private inheritance.
  - 下表中，意思是对于某一种inheritance type，Base class的某一种成员变量，在Derived class中的属性。
  - Protected access modifier is similar to that of private access modifiers, the difference is that the class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class. protected，派生类可见，其他不可见。
  - 派生类可访问基类的public and protected variable. The visibility to Base class members are not affected by the inheritance type.

| inheritance type        | public    | private | protected |
| ----------------------- | --------- | ------- | --------- |
| Base's public member    | public    | private | protected |
| Base's private member   | private   | private | private   |
| Base's protected member | protected | private | private   |

```C++
class Derived : public Base {
//...
}
```

- friend 友元, is a class or a function that can access private or protected member of the class.

```C++
class Test {
	friend class Friend;
    friend void func(Test);
};

void func(Test t){
    
}

class Friend {
    
};
```

- virtual function 多态的原理：virtual function table. **Notice:** one vtab for one class, not for one object!
  - a virtual destrcutor is essential for an abstract class because an object of a derived class is usually manipulated through the interface provided by its abstract bas class. In pariticular, it may be deleted through a pointer to a base class, avoiding memory leaks.

- unique_str 智能指针 TODO补充
  - `make_unique<T>()`

##### Copy and Move

- copy assignment: 定义operator = 

  ```c++
  T &T::operator=(const T &t){
  	return *this;
  }
  ```

- copy constructor

  ```c++
  T::T(const T&t){
  	//
  }
  ```

  - 注意：a copy constructor and a copy asignemnt for a class X are typically declared to take an argument of type **const X&**

  - 注意：在初始化的时候使用=，实际调用的是copy constructor，否则才是copy assignment.

  - ```c++
    T t2 = t; // call T::T(const T&t)
    T t3;
    t3 = t;// call T &T::operator=(const T&t)
    ```

- move constructor

  ```c++
  class T {
      int size;
      int *ele;
  	T(T &&t): size(t.size), ele(t.ele) {}
  };
  ```

- move assignment (c++11)

  - 如果只定义move assignment，不定义copy constructor, `T t2 = t;`会报错。因为编译器自动把copy constructor删掉了。

  ```c++
  T& operator=(T&& t){
  	
  }
  ```

  - `&&` 参数指的是 **rvalue reference** , which is a reference to which we can bind a rvalue.
  - move constructor does **not** take a const argument, 因为move constuctor definitely change the parameter by moving members from it.
  - 注意，这里要区分清楚copy/move assignment。
  - a move operation is applied when an **rvalue** reference is used as an initializer or as the right hand side of an assignment. 注意，是rvalue. 所以使用的时候，要搭配`std::move`.(c++11) 
    - `std::move`: convert a value to an rvalue.

  ```c++
  Vector t1;
  
  Vector t2 = t1;// copy constructor
  t2 = t1; // copy assignment
  Vector t3(t1); // copy constructor
  Vector t4;
  t4 = std::move(t1); //move assignment
  Vector t5(std::move(t1)); // move constructor
  ```

  - 有一个奇怪现象，return 对象，没有调用move 或者copy，查了下是编译器优化了(RVO技术c++11)

```c++
Vector f(){
	Vector t;
	return t;
}
```

- `delete` 关键字，禁止使用某类成员函数，包括构造函数

##### Templates

- 实现了`begin` and `end` 后，即可使用`for-loop` 遍历

```c++
template<typename T>
T *begin(Vector<T> &t){ return &x[0];}
template<typename T>
T *end(Vector<T> &t){ return x.begin() + x.size();}

void f(){
    //...
    Vector<string> &vs;
    for (auto &s: vs) {
        //...
    }
}
```

- 利用templates修饰函数，可以实现针对不同类型的功能，比如`std::accumulate`的一个简单实现。

```cpp
template<typename Container, typename Value>
Value sum(const Container &c, Value init) {
    for (auto x: c) { init += x}
    return init;
}
```

- function object, **functor**，有点类似回调函数。
  - **predicate**: is something taht we can invoke to reutrn true or false
  - function objects used to specify the meaning of key operations of a general algorithm are often referred to as **policy objects**

```cpp
template<typename T>
class IsNil {
public:
    // 意思是可以当成函数调用的对象
    bool operator()(T x) {
        return x == 0.;
    }
};

template<typename C, typename P>
int for_all(C &c, P p){ 
    int cnt = 0;
    for (auto x: c) {
        if (p(x)) cnt++;
    }
    return cnt;
}

void main(){
    IsNil<double> judge;
    Vector t;
    for_all(t, judge);
}
```

- defining policy object's class is inconvenient. We can use **lambda expression** to replace it.

```cpp
for_all(vec, [](double x){return x != 0.;})
```

- 对于lambda expression
  - [&] 表示capture list， 表示local names will be passed by reference.
  - [&x] 表示只capture x这一个局部变量，并且是以reference形式
  - [=] capture all local names used by value
  - [=x], generate a copy of x

- **variadics**,Variadic Templates, can accept any arguments you care to give them

```cpp
template<typename T>
void g(){cout << T << "\n";}
    
template<typename T, typename... Tail>
void func(T head, Tail... tail) {
    g(head);
    func(tail...);
}
void func(){}
```

variadic templates, 把第一个typename和剩下的区分.ellipsis `...`可以表示：the rest of the arguments. 上面的这个例子，其实就是递归处理每一个type的过程。

- `template<>`

  - `template<>` tells the compiler that a template specialization follows, specifically a **full specialization**.

  - 特殊化template的意思。

  - ```c++
    template<class T>
    class A{
      // general implementation
    };
    
    template<>
    class A<int>{
      // special implementation for ints
    };
    ```

  - 

- **alias** 别名

  - `using`(c++11) 和 typedef(c++98) 功能差不多, using更强大
    - `using type_t = int;`
    - `typedef int type_t;`
    - 函数别名：
      - `typedef void (*f_t)(int, int);`
      - `using f_t = void (*)(int, int);`
  - `using`支持**模版别名**

  ```c++
  template<typename Key, typename Val>
  class Map{};
  
  template<typename Val>
  using String_map = Map<string, Value>;
  
  String_map<int> m;
  ```

#### 1.2 Containers and Algorithms

- I/O, `istream`, `ostream`, we can define our own streams. 这个不是定义在类内，直接定义为函数。牛逼了。`istream`也是类似

  ```c++
  ostream &operator<<(ostream &os, const Vector &t) {
  	for (auto x: t) {
  		os << x << " ";
  	}
  	os << "\n";
  }
  ```


- `using` 可以用来使用其他类的constructors

```c++
template<typename T>
class Vec : public std::vector<T> {
public:
	using vector<T>::vector;
}
```

- `std::map` 是红黑树
- `std::unordered_map`是hashtable
- 一些container

| class              | comment                                     |
| ------------------ | ------------------------------------------- |
| std::vector<T>     | a variable-size vector                      |
| list<T>            | a doubly-linked list                        |
| forward_list<T>    | a singly-linked list                        |
| deque              | a double-ended queue                        |
| set                | a set                                       |
| multiset           | a set in which a value can occur many times |
| map                | a associative array                         |
| multimap           | a map in which a key can occur many times   |
| unordered_map      | a map using a hashed lookup                 |
| unordered_multimap | a multimap using a hashed lookup            |
| unordered_set      | a set using a hashed lookup                 |
| unordered_multiset | a multiset using a hashed lookup            |

- **Algorihtms**
  - `unique`: 删除相邻同样的元素
  - `unqiue_copy`
  - `back_inserter`
  - `find_all`, 找到所有
  - 等
- Stream Iterator
  - 什么骚操作。

```cpp
ostream_iterator<string> oo {std::cout};
*oo = "Hello\n"; //  meaning cout << "Hello\n";
```

- predicates

  - 用于find_if等函数, 用functor和lambda expression都可以

  - ```cpp
    find_if(m.begin(), m.end(), Greater_Than{42});
    find_if(m.begin(), m.end(), [](const pair<string, int>& r){return r.second > 42;});
    ```

- `back_inserter`，放回一个container的末尾iterator，可以用来末尾插入数据

```c++
fill_n(back_inserter(v), 3, -1);
```

#### 1.3 Concurrency and Utilities

- sharing data
  - mutex: mutual exclusion object

```c++
mutex m;
void f(){
    unique_lock<mutex> lck{m}; // acquire mutex
    sh+=1;
    // release mutex implicitly
}
```

- timer

```c++
using namespace std::chrono;
auto t0 = high_resolution_clock::now();
auto t1 = high_resolution_clock::now();
duration_cast<nanoseconds>(t1-t0).count();// ns
```

- contional variable
  - let a thread to wait for another, by waiting for some condition

```c++
void consumer() {
    while(true){
        unique_lock<mutex> lck{mmutex};
        while(mcond.wait(lck)); // wait and release lock
        
        auto m = mqueue.front(); //get message
        mqueue.pop();
        lck.unlock();
        // process message
    }
}

void producer(){
    while(true){
        Message m;
        // fill message
        unique_lock<mutex> lck{mmutex};
        mqueue.push(m);
        mcond.notify_one();
    }// release lock at the end of while scope
}
```

- future and promise. 没听过
  - enable a transfer of a value between two tasks without explicit use of a lock.
  - `future<X> fx`, we can get a value from a future, by `X v = fx.get()`
    - if value if unavailable, thread is blocked until it arrives.
  - `promise<X> px`, call `set_value()`or `set_exception()` to match `future`'s get.
- `packaged_task`, 有点抽象，不知有什么用
- `async`
  - 同步计算。returns a future
- `numeric_limts` from `<limits>`, 可以放回一些limit值
  - `numeric_limits<float>::min()`
- `decltype()` is a builtin function, returns the declared type of its arguments.可以放在template
- regular expression
  - `regex pat("pattern")`
  - `regex_search(line, matches, pat)`
- random number
  - `<random>`

### 2. Types and Declarations

`wchar_t`大char

`constexpr` evaluate at compile time

- Fields, 在操作系统实验中见过这个语法, 指定位数，减少内存占用

```C++
struct PPN {
	unsigned int PFN : 22;
	int: 3;
	un- signed int CCA : 3;
	bool nonreachabl : 1;
};
```

- cast
  - run-time checked conversion `dynamic_cast<type>(expr)`
  - compile-time checked conversion `static_cast<type>(expr)`
  - unchecked conversion `reinterpret_cast<type>(expr)`
  - const conversion `const_cast<type>(expr)`
- alignment of type
  - `alignof(type)`
- `constexpr` is usually better for const
- **literal type**
  - 可以参与编译器运算的对象
  - constructor需要用constexpr修饰
  - literal 就是普通的常量，比如1，3.14, "ab"等

#### smart pointer

- `auto_ptr`, `unique_ptr`, `shared_ptr`, `weak_ptr`

`auto_ptr` is deprecated

`unique_ptr` make sure that one object can be referred by one pointer.

```C++
unique_ptr<T> p1 = make_unique<T>();
cout << p1.get() << endl;//0xaddress1

unique_ptr<T> p2 = std::move(p1);
cout << p1.get() << endl;// 0
cout << p2.get() << endl;// 0xaddress1

```

`shared_ptr` enables an object being referred by mulpile pointers, and meanwhile counting the numbers of pointers. use `p.use_count()` to check the referring number.

`weak_ptr` doesn't get involved in the counting procedure of `shared_ptr` when they are pointing to the same object.