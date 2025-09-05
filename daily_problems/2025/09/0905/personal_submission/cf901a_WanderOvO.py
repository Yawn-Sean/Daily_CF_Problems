"""
某个深度的点只有 1 个，显然不会有多种搞法
某个深度的点有多个，假如其上一个深度的点只有 1 个，那么也没什么花样
如果上一个深度的点有多个，则可以有很多连法了
"""

h = int(input())
a = list(map(int, input().split()))

ok = True
for i in range(h + 1):
    if i + 1 <= h:
        if a[i + 1] > 1 and a[i] > 1:
            ok = False
            break

if ok:
    print("perfect")
else:
    print("ambiguous")
    last_idx = 0
    res1 = []
    for i in range(h + 1):
        for j in range(a[i]):
            res1.append(last_idx)
        last_idx += a[i]
    print(*res1)
    i = 0
    while i < len(res1):
        j = i
        while j < len(res1) and res1[j] == res1[i]:
            j += 1
        if j == i + 1:
            i = j
            continue

        if j + 1 < len(res1) and res1[j + 1] == res1[j]:
            res1[j + 1] = res1[j] - 1
            break
        i = j
    print(*res1)

