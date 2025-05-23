# Submission link: https://codeforces.com/contest/818/submission/320840324
def main():
    n, m = MII()
    nums = LGMI()

    vis = [-1] * (n + 1)
    ans = [-1] * n

    for i in range(1, m):
        pos = nums[i - 1]
        step = (nums[i] - nums[i - 1] - 1) % n + 1
        
        if vis[step] != -1 and vis[step] != pos: exit(print(-1))
        if ans[pos] != -1 and ans[pos] != step: exit(print(-1))

        vis[step] = pos
        ans[pos] = step

    pt = 1

    for i in range(n):
        if ans[i] == -1:
            while vis[pt] != -1:
                pt += 1
            ans[i] = pt
            vis[pt] = i

    print(' '.join(map(str, ans)))