# Submission link: https://codeforces.com/contest/332/submission/311728257
def main():
    n, p, k = MII()
    v1 = []
    v2 = []

    for _ in range(n):
        a, b = MII()
        v1.append(a)
        v2.append(b)

    st_range = sorted(range(n), key=lambda x: -v2[x] * 10 ** 9 + v1[x])

    # 选择 st_range 的一个长度为 p 的子序列，前面 k 个是遵守，产生白头发
    # 所以到 n - k 前的任务都能作为子序列产生白头发

    d = defaultdict(list)
    rnd = random.getrandbits(30)

    for i in range(n - (p - k)):
        idx = st_range[i]
        d[v1[idx] + rnd].append(idx)

    ans = []
    used = [0] * n

    for v in sorted(d, reverse=True):
        for idx in d[v]:
            if len(ans) < k:
                ans.append(idx)
                used[idx] = 1

    # 在没选的后缀中选择不满意度最高的 p - k 个

    start = 0
    for i in range(n - 1, -1, -1):
        idx = st_range[i]
        if used[idx]:
            start = i + 1
            break

    d = defaultdict(list)
    for i in range(start, n):
        idx = st_range[i]
        d[v2[idx] + rnd].append(idx)

    for v in sorted(d, reverse=True):
        for idx in d[v]:
            if len(ans) < p:
                ans.append(idx)

    print(*(x + 1 for x in ans))