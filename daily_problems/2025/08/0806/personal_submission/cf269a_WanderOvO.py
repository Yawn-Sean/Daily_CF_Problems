"""
2^k 的盒子能放 4 个 2^(k - 1) 的盒子
假设有 cnt 个 2^k 的盒子，我们令 cnt = (cnt + 3) / 4，直到 cnt 变成 1，记录一下这个盒子的型号
"""

n = int(input())
res = 0
for i in range(n):
    k, cnt = map(int, input().split())
    size = k
    if cnt == 1:
        res = max(res, size + 1)
        continue

    while cnt != 1:
        size += 1
        cnt = (cnt + 3) // 4
    res = max(res, size)
print(res)
