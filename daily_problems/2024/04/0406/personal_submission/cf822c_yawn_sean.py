# Submission link: https://codeforces.com/contest/822/submission/255169048
def main():
    n, x = MII()
    left = [Counter() for _ in range(2 * 10 ** 5 + 1)]
    right = [Counter() for _ in range(2 * 10 ** 5 + 1)]

    for _ in range(n):
        l, r, c = MII()
        if r - l + 1 not in left[l] or left[l][r-l+1] > c:
            left[l][r-l+1] = c
        if r - l + 1 not in right[r] or right[r][r-l+1] > c:
            right[r][r-l+1] = c

    ans = inf
    cur = Counter()
    for i in range(2 * 10 ** 5):
        
        for v in right[i]:
            if v not in cur or cur[v] > right[i][v]:
                cur[v] = right[i][v]

        for v in left[i+1]:
            if x - v in cur:
                ans = min(ans, cur[x-v] + left[i+1][v])

    print(ans if ans < inf else -1)