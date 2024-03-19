## Binary Search





# Tree

- use preorder and postorder to construct the original binary tree

  - locate the second value of preorder in postorder, suppose it index i. And 0 to i is the left tree.

  - non-iterative way, todo

  - ```java
    class Solution {
        public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
            Deque<TreeNode> stack = new ArrayDeque<>();
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < postorder.length; i++) {
                map.put(postorder[i], i);
            }
            TreeNode node = new TreeNode(preorder[0]);
            TreeNode root = node;
            for (int i = 1; i < preorder.length; i++) {
                TreeNode n = new TreeNode(preorder[i]);
                while (map.get(preorder[i]) >= map.get(node.val)) {
                    node = stack.pop();
                }
                if (node.left == null) {
                    node.left = n;
                } else {
                    node.right = n;
                }
                stack.push(node);
                node = n;
            }
            return root;
        }
    }
    ```

# Graph

- basic: use `queue` to BFS, `stack` to DFS

- use in-degree to detect directed graph's self-loop. leetcode 207.
- to detect an undirected graph's self loop.
  - **number of nodes == edges + 1**
    - this criteria exclude the circumstance of that self loop in total.
  - The remaining thing to do is to judge whether all nodes are connected.
    - Use visited and BFS to traverse the graph, the judge whether all nodes are connected.

#### Iterative method

##### DFS template

```c++
vector<vector<int>> ans;
vector<int> temp;
void dfs(int cur, vector<int>& nums) {
    if (cur == nums.size()) {
        // 判断是否合法，如果合法判断是否重复，将满足条件的加入答案
        if (isValid() && notVisited()) {
            ans.push_back(temp);
        }
        return;
    }
    // 如果选择当前元素
    temp.push_back(nums[cur]);
    dfs(cur + 1, nums);
    temp.pop_back();
    // 如果不选择当前元素
    dfs(cur + 1, nums);
}
```

对于特定的条件，考虑优化如何选择当前元素。比如引入判断条件，是否**选择**当前元素或者**不选择**当前元素。例子：Leetcode 491 increasing subsequence

```c++
 void helper(vector<vector<int>> &result, vector<int> &nums, vector<int> &cur, int i, int prev){
    if(i == nums.size()){
        if(cur.size() >= 2) 
            result.push_back(cur);
        return;
    }
    if(nums[i] >= prev) {
        cur.push_back(nums[i]);
        helper(result, nums, cur, i + 1, nums[i]);
        cur.pop_back();
    }
    if(nums[i] != prev){
        helper(result, nums, cur, i + 1, prev);
    }
}
```

##### Hierholzer Algorithm

Find Euler Path in a connected graph, the algorithm:

1) start from beginning node, do DFS

2) delete the path after moving on the path

3) if no where to go, add the node to the stack

4) pop the stack, and the order of the popping is the answer

```c++
void dfs(Node *cur) {
	while(has some where to go) {
		Node *next_node = get_next_node(cur);
		delete_path(cur, next_node);
		dfs(next_node);
	}
    result.push_back(cur);
}
```

#### Finding a self cycle of a directed graph

- **Method 1: in-degree method**

A brilliant way to detect self cycle: first initialize a queue containing all nodes with zero in-degree. Start with this queue, do a BFS search. Every time we arrive at one node, delete the edges with previous node, and add the node to the queue if the in-degree is zero again. Record the number of nodes we have been added to the queue. Once the BFS is done, if the number of vertex equals to the nodes added to the queue, then no self cycle exists.

[Leetcode 207 Course Schedule]([Course Schedule - LeetCode](https://leetcode.com/problems/course-schedule/description/))

```C++
// numCourses: number of nodes
// prerequisites: direct edges, [[from, to], [from, to]]
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indeg(numCourses, 0);
    vector<list<int>> map(numCourses, list<int>());
    for (auto const &p : prerequisites) {
        indeg[p[1]]++;
        map[p[0]].push_back(p[1]);
    }

    deque<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indeg[i] == 0)
            q.push_back(i);
    }

    int visit = q.size();
    while (!q.empty()) {

        int vertex = q.front();
        q.pop_front();
        for (int nex : map[vertex]) {
            indeg[nex]--;
            if (indeg[nex] == 0) {
                visit++;
                q.push_back(nex);
            }
        }
    }

    return visit == numCourses;
}
```

- **Method 2: using iterative method with visited array**

Use visited array to label the vertexes that have been visited, use a stack_label array to label the current path.

```C++

class Graph {
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // Used by isCyclic()
    bool isCyclicUtil(int v, bool visited[], bool* rs);
 
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[],
                         bool* recStack)
{
    if (visited[v] == false) {
        // Mark the current node as visited
        // and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this
        // vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]
                && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
 
    // Remove the vertex from recursion stack
    recStack[v] = false;
    return false;
}
 
// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited
    // and not part of recursion stack
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
        if (!visited[i]
            && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
```

#### Detecting a self cycle of an undirected graph

sample logic as directed graph, use visited as a label array.

```C++

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
 
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}
 
// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{
 
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++) {
 
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}
 
```

# Max Heap

- In C++, just use `priority_queue` as max heap, as for min heap, use `priority_queue<int, vector<int>, greater<int>> pq `



 堆分为最大堆和最小堆。最大堆定义：一个二叉树，每个节点的值大于其子节点。最小堆相反。

一般用数组来表示堆，当然，用树，链表都可以，想怎么来怎么来。

数组d，有n个节点，其中一些下标定义：

1）`d[k]`的子节点为`d[2*k+1]`和`d[2*k+2]`，当然这里的`2*k+1`和`2*k+2`都得小于`n`

2）最后一个父节点的位置：`d[n/2-1]`

3）`d[k]`节点的父节点的位置`d[(k-1)/2]`

有了如上的坐标索引，就能有定义一些堆的操作。下面的例子都以最大堆为例。

### 一、堆的建立：

一个数组初始化为堆，需要分为从下至上，然后从上至下。

从下至上指的是，从最下面一个父节点开始，遍历节点到根节点。回顾最大堆的性质：每一个节点，都比其子节点要大，也就是说，每一棵子树的最大节点是根节点。那么从最后一层开始，一直调整到最顶层，就保证了每棵子树都是最大堆。

那如何调整某棵子树？我们从上至下调整。

特殊的，我们先定义，如果一棵树只含有一个节点，那么这棵树也为最大堆。

我们假设当前节点为`d[k]`处在第`i`层，由于我们是从下至上遍历的子树，**所以当前节点的左右子树已经满足最大堆的条件**。

如果满足`d[k] > d[2*k+1]`且`d[k] > d[2*k+2]`，即可以保证`d[k]`为根节点的堆也是最大堆。

所以，我们取`d[2*k+1]`和`d[2*k+2]`的更大者，和`d[k]`交换，这样就能保证上面的不等式。比如`d[2*k+1] > d[2*k+2]`，那么交换`d[k]`和`d[2*k+1]`，然后令`k = 2*k+1`，也就是向下递归这个过程，直到遇到叶子节点位置。

代码如下：

```cpp
void top_down(vector<int> &nums, int k){
    int n = nums.size();
    k = 2 * k + 1;
    while(k < n){
        if(k + 1 < n && nums[k + 1] > nums[k])
            k++;
        if(nums[k] > nums[(k - 1) / 2])
            swap(nums[k], nums[(k - 1) / 2]);
        else
            break;
        k = 2 * k + 1;
    }
}

void buildheap(vector<int> &nums){
    int n = nums.size();
    //bottom up
    for(int i = n / 2 - 1; i >= 0; i--){
        top_down(nums, i);
    }
}
```

### 二、堆的插入

建立好了堆，需要往堆里插入数据，思路和构建堆是一样的。在数组末尾插入了一个元素，也要想办法把当前的数组调整为最大堆。末尾插入元素后，最后一个父节点构成的子树就不一定是最大堆了，所以需要从最后一个父节点开始进行调整。把新插入的元素一直往上和父节点交换位置，直到父节点大于新插入的值为止，这样就能保证堆被调整为最大堆。

证明：

假设新插入元素为`d[n-1]`。叶子节点就是最大堆。

假设新插入的元素替换到第`k`层的时候，由新插入的元素构成的子树为最大堆。此时新插入的元素位置为`d[m]`

那么到`k-1`层的时候，`d[(m-1)/2]`为`d[m]`的父节点，假设`d[q]`为`d[m]`的兄弟节点，那么必然有`d[(m-1)/2] > d[q]`。

如果`d[(m-1)/2] < d[m]`，交换`d[m]`和`d[(m-1)/2]`，则`d[(m-1)/2]`根节点的子树为最大堆。如果`d[(m-1)/2] > d[m]`，不交换，则已经是最大堆。数学归纳法知得证。

代码：

```cpp
void heapinsert(vector<int> &nums, int x){
    nums.push_back(x);
    int i = nums.size() - 1;
    int parent = (i - 1) / 2;
    while(parent >= 0 && i != 0){
        if(nums[parent] < nums[i])
            swap(nums[parent], nums[i]);
        else
            break;
        i = parent;
        parent = (i - 1) / 2;
    }
}
```

### 三、删除堆顶

删除堆顶操作为：把堆顶元素和最后一个元素互换，然后弹出最后一个元素。再把当前堆调整为最大堆。

由于堆顶此时变成了最后一个元素，不一定是最大值，所以从第一个元素开始，进行从上到下的调整。

```cpp
void heapdelete(vector<int> &nums){
    nums[0] = nums.back();
    nums.pop_back();
    top_down(nums, 0);
}
```

### 四、堆的应用。

由于从堆中可以O(1)的时间找到最大值或者最小值，这个特性能够解决很多问题。比如K个有序链表的合并，排序算法等等。

下面举堆排序为例：

1）输入一个乱序数组，先调整为堆

2）把堆顶弹出，相当于删除堆顶，和数组末尾元素交换，这时待处理的数组长度减1

3）从第一个元素进行top_down操作调整堆

4）循环2-3，待处理的子数组长度为0时候，原数组变为有序。

时间复杂度O(nlog(n))（每次调整堆O(logn)，调整n次）

```cpp
void fixdown(vector<int> &nums, int k, int n){
    k = 2 * k + 1;
    while(k < n){
        if(k + 1 < n && nums[k + 1] > nums[k])
            k++;
        if(nums[k] > nums[(k - 1) / 2])
            swap(nums[k], nums[(k - 1) / 2]);
        else
            break;
        k = 2 * k + 1;
    }
}

void buildheap(vector<int> &nums){
    int n = nums.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        fixdown(nums, i, n);
    }
}

void heapsort(vector<int> &nums){
    buildheap(nums);

    for(int i = 0; i < n; i++){
        swap(nums[0], nums[n - i - 1]);
        fixdown(nums, 0, n - i - 1);
    }
}
```

