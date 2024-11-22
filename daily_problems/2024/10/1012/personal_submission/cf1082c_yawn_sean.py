# Submission link: https://codeforces.com/contest/1082/submission/285394865
def main():
    n, m = MII()

    tmp = [[] for _ in range(m + 1)]
    for _ in range(n):
        x, y = MII()
        tmp[x].append(y)

    vals = [0] * (n + 1)
    for i in range(m + 1):
        tmp[i].sort(reverse=True)
        cur = 0
        for j in range(len(tmp[i])):
            cur += tmp[i][j]
            if cur > 0: vals[j + 1] += cur

    print(max(vals))