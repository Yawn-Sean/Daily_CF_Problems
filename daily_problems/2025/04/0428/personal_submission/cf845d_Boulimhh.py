"""
问题出在了超车的处理上

一开始不太懂超了车 和 通过可以超车标志这两步应该怎么更新

速度用栈模拟就行

"""
# python 代码
n = int(input())
_, speed = map(int, input().split())
limit = []
overtaking = 0

res = 0
for _ in range(n - 1):
    a = list(map(int, input().split()))
    if a[0] == 1:
        speed = a[1]
        while limit and limit[-1] < speed:
            res += 1
            limit.pop()
    elif a[0] == 2:
        res += overtaking
        overtaking = 0
    elif a[0] == 3:
        if a[1] < speed: res += 1
        else: limit.append(a[1])
    elif a[0] == 4:
        overtaking = 0
    elif a[0] == 5:
        limit.clear()
    else:
        overtaking += 1
print(res)
