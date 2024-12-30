# Submission Link: https://codeforces.com/contest/1131/submission/269801962
def main():
    n = II()
    ends = list(range(n))
    nex = [-1] * n
    union = [-1] * n

    def find_head(x):
        p = x
        while union[p] >= 0:
            p = union[p]
        while x != p:
            union[x], x = p, union[x]
        return p

    def merge(x, y):
        x = find_head(x)
        y = find_head(y)
        if union[x] > union[y]: x, y = y, x
        union[x] += union[y]
        union[y] = x
        nex[ends[x]] = y
        ends[x] = ends[y]

    for _ in range(n - 1):
        u, v = GMI()
        merge(u, v)

    ans = [find_head(0)]
    for _ in range(n - 1):
        ans.append(nex[ans[-1]])

    print(' '.join(str(x + 1) for x in ans))