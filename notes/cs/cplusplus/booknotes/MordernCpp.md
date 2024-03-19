# Notes from Effective modern Cpp

This book is generally c++11 and c++14.

- rvalue, lvalue. A useful heuristic to determine whether an expression is an lvalue is to ask if you can take its address. If you can, it typically is. If you can’t, it’s usually an rvalue. 

```cpp
class Widget {
   public:
Widget(Widget&& rhs); // rhs is an lvalue, though it has
     ...                        // an rvalue reference type
   };
```

- In this note,`rhs` stands for right hand side and `lhs` stands for left hand side, as the author specified. Also, he abbreviates “constructor” as *ctor* and “destructor” as *dtor*.

#### Item1. template type deduction

```cpp
template<typename T> 
void f(ParamType param);

f(expr);
```

- Three conditions, `ParamType`:

  - 1) reference or pointer, but not a universal referrence.

    - ```cpp
      template<typename T>
      void f(const T& p);
      const int x = 2;
      const int &r = x;
      f(r); // void f<int>(const int &)
      ```

    - 注意：reference-ness is ignored during type deduction! 比如上面r类型是const int reference，但是T推导结果是const int, `p`类型是const int &.

    - 同理，如果`template <typename T>void f(const T *p)`，T在推导的时候，也不会带上参数的`*`

  - 2. universal reference

    - ```cpp
      template<typename T>
      void f(T&& p);
      
      int x = 0;
      const int rx = x;
      const int &px = rx;
      f(x);		// void f<int &>(int &)
      f(move(x)); // void f<int>(int &&)
      f(123);		// void f<int>(int &&)
      f(rx);		// void f<const int &>(const int &)
      f(px);		// void f<const int &>(const int &)
      ```

    - related to reference collapse书本上的rule:

      - If *expr* is an lvalue, both T and *ParamType* are deduced to be lvalue references. That’s doubly unusual. First, it’s the only situation in template type deduction where T is deduced to be a reference. Second, although *ParamType* is declared using the syntax for an rvalue reference, its deduced type is an lvalue reference.
      - If *expr* is an rvalue, the “normal” (i.e., Case 1) rules apply.

    3. neither a pointer or reference

    - ```cpp
      template<typename T>
      void f(T param); // param is now passed by value
      int x = 0;
      const int rx = x;
      const int &px = rx;
      f(x);		// void f<int>(int)
      f(move(x)); // void f<int>(int)
      f(123);		// void f<int>(int)
      f(rx);		// void f<int>(int)
      f(px);		// void f<int>(int)
      ```

    - 注意，这里又个地方比较巧妙。推导类型的时候，是by-value地去掉对应的const, reference, volatile等修饰符。比如上面的例子，传入的都是value，修饰value的对应的关键字都被去掉。

    - 但是，一个特殊情况是，如果传入`const int *p = &x; f(p);`，那么将被推导为：`void f<const int *> (const int *)`，因为在这里，pointer本身是一个指向常量的value。而这个value 本身的type就带有const。

    - 如何理解？考虑另一种情况`const int * const p = &x;`，这个是常量指针指向常量int。那么第二个const是value的修饰符。所以这里被省略，推导为`void f<const int *>(const int *)`

- What about array?

  - If an array is passed to a by-value parameter template function, the type will be deducted to pointer

    - ```cpp
      template<typename T>
      void f(T p);
      
      const int arr[] = {0,1,2,3};
      f(arr); // void f<const int *>(const int *)
      ```

  - but If pass it to by-reference, something peculiar happens.

    - ```cpp
      template<typename T>
      void f(T &p);
      
      const int arr[] = {0,1,2,3,4,5};
      f(arr); void f<const int [6]>(const int (&)[6]);
      ```

    - It provides us the ability to declare the reference to array, therefore, we can deduce the len of the array by templates

      - ```cpp
        template<typename T, std::size_t N>
        constexpr std::size_t lens(T (&p)[N]) noexcept{
        	return N;
        }
        ```

- function arguments?

  - behave like arrays. When pass to by-value template function(`void f(T x)`), the argument decays to pointer-to-function. When pass it to by-reference function(`void f(T &x)`), the argument decays to reference-to-function;

##### Summary

- During template type deduction, arguments that are references are treated as non-references, i.e., their reference-ness is ignored.
- When deducing types for universal reference parameters, lvalue arguments get special treatment.
- When deducing types for by-value parameters, const and/or volatile arguments are treated as non-const and non-volatile.
- During template type deduction, arguments that are array or function names decay to pointers, unless they’re used to initialize references.

#### Item2. `auto` 

When a variable is declared using auto, auto plays the role of T in the template, and the type specifier for the variable acts as *ParamType*.

和template类似，auto是`T`，具体类型是param type.

除了一种例外情况：When an auto–declared variable is initialized with a

braced initializer, the deduced type is an instantiation of `std::initializer_list`. But if the corresponding template is passed the same initializer, type deduction fails, and the code is rejected:

```cpp
auto x = {1};
// x is std::initializer_list<int>
```

- if you want to pass bracket parameters to template function ,use this:

```cpp
template<typename T>
void f(std::initializer_list<T> initList);
f({ 11, 23, 9 });// T is deduced to `int`
```

- But if `auto` is used as return type or parameters of lambda function, the initializer_list deduction won't work.

```cpp
auto createInitList() {
	return { 1, 2, 3 }; 
    // error: can't deduce type // for { 1, 2, 3 }
}

std::vector<int> v;

auto resetV = [&v](const auto& newValue) { v = newValue; };
// C++14

resetV({ 1, 2, 3 }); // error! can't deduce type
                              // for { 1, 2, 3 }
```

##### Summary

• `auto` type deduction is usually the same as template type deduction, but auto type deduction assumes that a braced initializer represents a `std::initializer_list`, and template type deduction doesn’t.

• `auto` in a function return type or a lambda parameter implies template type deduction, not `auto` type deduction.

#### Item3: `decltype`

- `decltype` typically parrots back the exact type of the name or expression you give it. 不会去掉const 等
- the primary use for decltype is declaring function templates where the function’s return type depends on its parameter types.

- 所以`decltype`和`auto`以及`template`的逻辑不一样。decltype会带上所有的已知的declared type.

- 通过一个例子一步一步了解：

```cpp
template<typename Container, typename Index> auto authAndAccess(Container& c, Index i)
  -> decltype(c[i])
{
  authenticateUser();
  return c[i];
}
```

- 在c++11，通过`->`声明放回的类型。在c++14，可以省略trailing return type

```c++
template<typename Container, typename Index> auto authAndAccess(Container& c, Index i)
{
  authenticateUser();
// C++14; not quite correct
return c[i]; // return type deduced from c[i] 
}
```

这里有一个问题，通过`c[i]`推导auto类型，推导成了Cointainer包含的T类型。并不是lvalue. 解决方法：

```cpp
template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container& c, Index i)
{
  authenticateUser();
  return c[i];
}
```

- 这是因为，decltype会带上所有reference-ness.

- 但还有一个问题，c无法接受右值。只能处理左值。所以，进一步，利用universal reference特性：

```cpp
template<typename Container, typename Index> 
decltype(auto) 
authAndAccess(Container&& c, Index i);
// c is now a universal reference
```

- 最后，要加上`std::forward`避免拷贝

```cpp
template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i)
{
  authenticateUser();
	return std::forward<Container>(c)[i]; 
}
```

- 另外一个要注意的，如果decltype接受了左值表达式，那么decltype会识别为左值引用。

```cpp
int x = 0;
decltype(x) a = x;// a is int
decltype((x)) b = x; // b is int&
```

- 因为`(x)`是表达式expr，并且是lvalue，所以，通过这种特性，这两个函数返回的不一样

```cpp
decltype(auto) f1() {
	int x = 0; ...
	return x;// decltype(x) is int, so f1 returns int
}
decltype(auto) f2() {
	int x = 0;
	...
	return (x); 
    // decltype((x)) is int&, so f2 returns int&
}
```

##### Summary

- decltype almost always yields the type of a variable or expression **without** any modifications.

- For lvalue expressions of type T other than names, decltype always reports a type of **T&**
- C++14 supports decltype(auto), which, like auto, deduces a type from its initializer, but it performs the type deduction using the decltype rules.

#### Item 4: view deduced types

- runtime

```cpp
std::cout << typeid(y).name() << '\n';
```

- compile time, use compiler output

```cpp
template<typename T>       // declaration only for TD;
class TD;                  // TD == "Type Displayer"
```

```cpp
TD<decltype(x)> xType;     // elicit errors containing
TD<decltype(y)> yType;     // x's and y's types

/*error: aggregate 'TD<int> xType' has incomplete type and cannot be defined
error: aggregate 'TD<const int *> yType' has incomplete type and cannot be defined
*/

```

#### Item5: 尽量用`auto`

- an auto variable need to be initialized.

- 比如std::vector的`std::vector<int>::size_type`，用auto n = nums.size()更好

- the key part of a `std::unordered_map` is `const`, so the type of `std::pair` in the hash table (which is what a `std::unordered_map` is) isn’t `std::pair<std::string, int>`, it’s `std::pair <*const* std::string, int>`.
  - 里面存的居然是const string
  - 所以这时候，要用auto进行for-loop`for(const auto &p: m){}`
  - 如果用显示声明：`for(const std::pair<std::string, int> &p: m){}`, p 的string不是const，会导致每次循环都掉用一次拷贝函数。

#### Item6

- `std::vector<bool>::reference` is an example of a *proxy class*: a class that exists for the purpose of emulating and augmenting the behavior of some other type. 
-  “Invisible” proxy types can cause auto to deduce the “wrong” type for an ini‐ tializing expression.
  - 对于`vector<bool>`，要特别注意。它的`[]` operator返回的是自定义的reference类型。这里和其他的`vector<T>的[]`返回的`T&`不一样，这里有点奇怪，todo

```cpp
template <typename _Alloc>
class vector<bool, _Alloc>: ... {
	reference
	operator[](size_type __n){...}
}
```

- The explicitly typed initializer idiom forces auto to deduce the type you want it to have.

  - ```cpp
    int index = d * c.size();
    auto index = static_cast<int>(d * c.size());
    //the second one is a better coding habit
    ```

## Chapter 3

#### Item7: `{}` and `()`

- Compilers’ determination to match braced initializers with constructors taking `std::initializer_lists` is so strong, it prevails even if the best-match `std::initializer_list constructor` can’t be called.

```cpp
class Widget {
   public:
     Widget(int i, bool b); // as before
     Widget(int i, double d); // as before
	Widget(std::initializer_list<bool> il); // element type is now bool
    ... 	
};
Widget w{10, 5.0};// no implicit conversion funcs
// error! requires narrowing conversions
```

- calling vector is differnt with `()` and `{}`

```cpp
std::vector<int> v1(10, 20); // use non-std::initializer_list // ctor: create 10-element
                                 // std::vector, all elements have
                                 // value of 20
std::vector<int> v2{10, 20}; // use std::initializer_list ctor: // create 2-element std::vector,
                                 // element values are 10 and 20
```

- 总的来说，就是花括号优先去匹配`initializer_list`

#### Items8: use `nullptr`

#### Items9: use alias rather than `typedef`

- Besides a more precise outlooking, there are technical reasons to use alias rather than typedef
  - In particular, alias declarations may be templatized (in which case they’re called *alias templates*), while typedefs cannot.

```cpp
template<typename T>
using myAllocList = std::list<T, MyAlloc<T>>;
```

- some type traits conversion

```cpp
std::remove_const<T>::type    // yields T from const T
std::remove_reference<T>::type   // yields T from T& and T&&
std::add_lvalue_reference<T>::type // yields T& from T
```

- if we use alias, we can remove the `::type` at the end of the previous code.

```cpp
std::remove_const_t<T>
```

##### SUmmarys

-  typedefs don’t support templatization, but alias declarations do.
- Alias templates avoid the “::type” suffix and, in templates, the “typename” prefix often required to refer to typedefs.
- C++14 offers alias templates for all the C++11 type traits transformations. (`remove_const_t`)

#### Item 10: scoped enums

```cpp
enum class Status : std::uint32_t {
};
```

- you can inherit from different base types for different enumerators.

##### Other Items:

- use `noexcept` if a function won't raise an exception
- use `constexpr` if value is determined during compilation
- declare `overide`
- use `=delete`

#### Items 17: move copy construct, assignment

```cpp
Base(Base&&) = default;
Base& operator=(Base&&) = default;
Base(const Base&) = default;
Base& operator=(const Base&) = default;
```

- assignment: return an rvalue.
- move: use rvalue reference as parameter.

## Smart pointer

#### Item 18: `unique_ptr`

- std::unique_ptr embodies *exclusive ownership* semantics. 

#### Item 19: `shared_ptr`

- **std::shared_ptr****s are twice the size of a raw pointer**, because they internally contain a raw pointer to the resource as well as a raw pointer to the resource’s reference count.2
- **Increments and decrements of the reference count must be atomic**, because there can be simultaneous readers and writers in different threads. For example, a std::shared_ptr pointing to a resource in one thread could be executing its destructor (hence decrementing the reference count for the resource it points to), while, in a different thread, a std::shared_ptr to the same object could be copied (and therefore incrementing the same reference count). Atomic opera‐ tions are typically slower than non-atomic operations, so even though reference counts are usually only a word in size, you should assume that reading and writ‐ ing them is comparatively **costly**. 原子加法，所以慢。

- 但是：copying requires incrementing the reference count, but moving doesn’t.

- shared_ptr有control block，控制一些reference number 之类的

  - 建议用make_shared初始化shared_ptr。但是make_shared没法自定义删除函数

  - 不要用pointer初始化shared_ptr,比如：

    - ```cpp
      auto p = new A();
      shared_ptr<A> sp1(p);
      shared_ptr<A> sp2(p);// dangerous
      ```

    - 这样sp1和sp2用的是不同的control block，也就是`sp1.use_count()`和sp2是一样的。最后释放的时候，p会被delete两次。

  - 如果非得用raw pointer to initialize shared_ptr，put it in the constructor。比如下面，这样sp1和sp2就是共享这个reference block。

    - ```cpp
      shared_ptr<A> sp1(new A());
      shared_ptr<A> sp2(sp1);

  - 另外，如果用`std::move`，使得`sp1`变为右值。要小心sp1此时不再引用原来的资源。也会产生问题。

    - ```cpp
      shared_ptr<A> sp1(new A());
      shared_ptr<A> sp2(std::move(sp1));// move constructor
      ```

    - 