"""
思路： dp还是不咋会，而且之前也没做过类似题目，所以看这道题代码费了点时间。 分析一下。

left表示左边的先吃了， right表示右边的先吃了。 

初始的时候：

left 第一个没左边， 所以是两边都饿着的状态。

right 表示右边先吃了， 所以第一个是有一个吃饱的状态。

在遍历每个 i 的时候：

left 的最大值 ：
1、 （i - 1）是左边先吃， i 也是左边先吃， 所以是只有一个吃饱。 
2、 （i - 1）是右边先吃， 也就是 i 先吃。 所以 i 吃的时候 i - 1 还没吃， i + 1 也没吃， 两边都饿着。

right 的最大值：
1、 （i - 1）是右边先吃， i 吃的时候也是右边（i + 1）先吃， 所以只有一个吃饱。
2、 （i - 1) 是左边先吃， i 是右边先吃， 那么 i 吃的时候 i + 1， i - 1 都吃饱了， 所以两个吃饱。

因为右边先吃的情况下， 最后一个没得右边， 所以返回 left 的值。
"""
#python代码：
n = int(input())
a0 = list(map(int, input().split())) # 相邻的野兔都饿
b1 = list(map(int, input().split())) # 邻野兔中正好有一只吃饱
c2 = list(map(int, input().split())) # 相邻两只野兔都吃饱

left, right = a0[0], b1[0]
for i in range(1, n):
    left, right = max(left + b1[i], right + a0[i]), max(left + c2[i], right + b1[i])
print(left)
