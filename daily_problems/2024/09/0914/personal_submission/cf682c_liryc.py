'''
https://codeforces.com/contest/682/submission/281086389
682C
2024/9/14 Y1
1600
(ref) DP, Tree
'''

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))

    edge = [0]
    tree = [[] for _ in range(n)]

    for i in range(1, n):
        p, c = map(int, input().split())
        edge.append(c)
        tree[p - 1].append(i)

    dp = [0] * n

    stk = [0]
    ans = 0

    while stk:
        u = stk.pop()
        ans += 1
        
        for v in tree[u]:
            dp[v] = max(0, dp[u]) + edge[v]
            if dp[v] <= nums[v]:
                stk.append(v)
    print(n - ans)