"""
学习新思路， 前缀和的另一种表示。 

数组存每个前缀和的出现位置， 下标表示前缀和， 值代表位置。

"""
#python代码：
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    pref = [-n] * (2 * n + 1) # 存每个前缀和的出现位置
    cur = 0
    pref[0] = 0
    for i in range(n):
        cur += 1 if a[i] == 1 else -1
        pref[cur] = i + 1  #下标表示前缀和， 值代表位置。
    cur = 0
    ma = pref[0]
    for i in range(2 * n - 1, n - 1, -1):
        cur += 1 if a[i] == 1 else -1
        ma = max(ma, pref[-cur] + 2 * n - i)
    print(2 * n - ma)
