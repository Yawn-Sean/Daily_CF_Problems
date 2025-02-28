"""
思路：切入点一开始考虑的是 3 个的和， 分析和去了， 最后过程用来模拟。 结果就是，不出意外的没过

错误分析： 
三个数取中位数，和有三种情况， 3， 2， 1， 0。
加上当前位， 不需要改变的情况是 3 + 1， 2 + 1， 1 + 0， 0 + 0
需要改变的情况是， 1 + 1，2 + 0。 即两个1中间是0， 两个0中间是1.
前两种都是1， 后两种是0

羊神切入点是交替数组长度
"""
#python代码：
n = int(input())
a = list(map(int, input().split()))

def op(l, r):
    global cnt
    cnt = max(cnt, r - l - 1 >> 1)
    for j in range(l, l + r >> 1):
        a[j] = a[l]
    for j in range(l + r >> 1, r):
        a[j] = a[r - 1]

cnt = 0
l = 0
for i in range(1, n):
    if a[i] == a[i - 1]:
        op(l, i)
        l = i
op(l, n)

print(cnt)
print(*a)
