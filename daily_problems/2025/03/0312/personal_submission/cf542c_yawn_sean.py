# Submission link: https://codeforces.com/contest/542/submission/310182597
def main():
    n = II()
    ar = LGMI()

    ans, mi = 1, 0

    for i in range(n):
        vis = [-1] * n
        vis[i] = 0
        
        cur = i
        while True:
            ncur = ar[cur]
            if vis[ncur] != -1:
                ans = math.lcm(ans, vis[cur] + 1 - vis[ncur])
                mi = fmax(mi, vis[ncur])
                break
            vis[ncur] = vis[cur] + 1
            cur = ncur

    res = ans
    while res < mi:
        res += ans

    print(res)