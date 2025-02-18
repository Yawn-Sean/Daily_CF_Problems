def main():
    n, k = MII()
    res = LII()
    que = defaultdict(list)
    for i, j in enumerate(res):
        que[j].append(i)
    val = [0] * (1 + k)

    def check(l, r):
        if r == n - 1 or l == 0:
            return -1
        if res[l - 1] == res[r + 1]:
            return -2
        return -1

    for i in range(1, k + 1):
        ln = len(que[i])
        start = end = 0
        for j in range(1, ln):
            if que[i][j] == que[i][end] + 1:
                end = j
            else:
                val[i] += check(que[i][start], que[i][end])
                start = end = j
        val[i] += check(que[i][start], que[i][end])
    mi = min(val)
    for i in range(1, k + 1):
        if val[i] == mi:
            return i


tt = 1
for ii in range(tt):
    print(main())
