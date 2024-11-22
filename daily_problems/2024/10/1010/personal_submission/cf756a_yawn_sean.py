# Submission link: https://codeforces.com/contest/756/submission/285099357
def main():
    n = II()
    perm = LGMI()
    nums = LII()

    vis = [0] * n
    cnt = 0
    for i in range(n):
        if not vis[i]:
            while not vis[i]:
                vis[i] = 1
                i = perm[i]
            cnt += 1

    print((cnt if cnt > 1 else 0) + (sum(nums) - 1) % 2)
