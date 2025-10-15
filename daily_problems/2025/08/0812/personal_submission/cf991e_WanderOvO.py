"""
n 中每个数码必须在 m 中出现过，且 m 中某个数码的出现次数不超过 n 中数码的出现次数
且 m 不能以 0 开头
考虑先排非 0 的数，再插空
使用一个 dfs，枚举非 0 的数在 m 中出现的次数
到 dfs 终点之后，求非 0 这部分的方案数，然后枚举 0 的个数，再求带上 0 之后的方案数，累加到答案中
如何算 0 的插入方案？
先枚举 0 的最左边有几个数，假设是 cnt1 个，假设有 cnt2 个 0，则还剩下 cnt2 个空，每个空的数字个数 >= 0，需要总共放 cnt1 个
即 x1 + ... + xcnt2 = cnt1 的非负整数解个数，所以为 C(cnt1 + cnt2 - 1, cnt2 - 1)
"""

num = int(input())
cnt = [0 for _ in range(10)]
while num > 0:
    cnt[num % 10] += 1
    num //= 10

choose_cnt = [0 for _ in range(10)]
res = 0
fact = [1 for _ in range(20)]
for i in range(1, 20):
    fact[i] = fact[i - 1] * i
c = [[0 for _ in range(20)] for _ in range(20)]
c[0][0] = 1
for i in range(1, 20):
    c[i][0] = 1
    for j in range(1, i + 1):
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1]

def dfs(u):
    global choose_cnt
    global res
    if u == 10:
        s = 0
        contribution = 1
        for i in range(1, 10):
            s += choose_cnt[i]
        contribution *= fact[s]
        for i in range(1, 10):
            contribution //= fact[choose_cnt[i]]
        if cnt[0] == 0:
            res += contribution

        for i in range(1, s + 1):
            cnt1 = s - i
            for cnt2 in range(1, cnt[0] + 1):
                res += contribution * c[cnt1 + cnt2 - 1][cnt2 - 1]
        return

    if cnt[u] == 0:
        choose_cnt[u] = 0
        dfs(u + 1)
    else:
        for i in range(1, cnt[u] + 1):
            choose_cnt[u] = i
            dfs(u + 1)
            choose_cnt[u] = 0

dfs(1)
print(res)
