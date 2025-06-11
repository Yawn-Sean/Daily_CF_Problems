# Submission link: https://codeforces.com/contest/682/submission/281054098
def main():
    n = II()
    nums = LII()

    edge = [0]
    tree = [[] for _ in range(n)]

    for i in range(1, n):
        p, c = MII()
        edge.append(c)
        tree[p - 1].append(i)

    dp = [0] * n

    stk = [0]
    ans = 0

    while stk:
        u = stk.pop()
        ans += 1
        
        for v in tree[u]:
            dp[v] = fmax(0, dp[u]) + edge[v]
            if dp[v] <= nums[v]:
                stk.append(v)

    print(n - ans)