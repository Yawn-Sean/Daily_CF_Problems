"""
思路：交换前一半数组的最后一个， 和后一半数组的第一个， 可以让次数 + 2

加上最开始的1次调用， 是奇数次调用。 如果次数是偶数, 输出 -1 。

新学知识点：global的应用， 以及 print(*a if k == 0 else -1)会运行报错， 要把条件语句分开写才能过

"""
#python代码：
n, k = map(int, input().split())
a = list(range(1, n + 1))

def unmerge(l, r):
    global k
    if k == 0 or l + 1 == r:
        return
    mid = l + r >> 1
    k -= 1
    a[mid - 1], a[mid] = a[mid], a[mid - 1]
    unmerge(l, mid)
    unmerge(mid, r)
if k % 2 == 0:
    print(-1)
else:
    k //= 2
    unmerge(0, n)
    if k == 0:
        print(*a)
    else:
        print(-1)
