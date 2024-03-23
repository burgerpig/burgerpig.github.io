## 链表

- 注意，链表需要善用dumbo节点

## 双向双指针

LC2824, LC 16

- 核心在于，使用数组的有序的性质去解题

- 滑动窗口：209，3，713，2958，2730，1004，
  - TODO：2962，2302，1658
- 当数组有单调性，则可以使用双指针

## 二分法

- 开区间：`i = 0, j = n-1`
  - 每次判断，注意，`j + 1`都是>=target的数，或者数组长度（所有都小于）；i-1一定是<target的数
  - 循环不变量
- 半开半闭区间：`i=0, j=n`
- 全开区间，`i=-1,j=n `
- 注意>, >=, <, <=的转换
  - \>等价于>=x+1
  - <等价于找到>=x的那个数的(x)-1
  - <=等价于>=x+1的数的-1.32

## 回溯

- 三个问题：
  - 当前处理方式
  - 下一个子问题
  - 边界条件
- 回溯->记忆化->dp

## 41 First missing positive number

对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1,N+1] 中。

- 如果是N+2，那说明1~N+1都出现了，和长度为N矛盾

## 240 Search a 2D Matrix

![Picture1.png](https://pic.leetcode-cn.com/6584ea93812d27112043d203ea90e4b0950117d45e0452d0c630fcb247fbc4af-Picture1.png)

This is actually a sorted binary tree. fuck.

Today is my 29th birthday.

Currently, I am stuck with two strange thing in my throat. On my left side, there is a fish bone, and on the right side, there is a crust chicken wing skin. This is so strange and awkward. And I am feeling very painful, frustrated, and scared. I am scared about being like this king of situation for a very long time. It is very consuming for my life. It affects my study and work so much.  

Life's nature is torturing and enduring. This is the motto I believed strongly 5 years ago, when I were looking for a job after graduation. And today, I feel something different. Life is pain, and moreover, it is privately, even on the perspective of your wife or husband. Your can not realize other's pain totally, no matter how much you acclaimed you love the other people. It is sad, but it's truth.

Things are so unsure right now. The throat, the pain, the HK plan. I don't know what it might turn into, what the condition will become. But I know, life still goes on, and keeps moving. What branches will the decision tree go to is a problem of probability. All I can do is grasp the present, pray for tomorrow. 

2024.3.19