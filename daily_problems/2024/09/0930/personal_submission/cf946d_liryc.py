'''
https://codeforces.com/contest/946/submission/283794421
946D
2024/9/30 Y1
1800
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m, k = map(int, input().split())
    a = [input() for _ in range(n)]
    return n, m, k, a

def solve(n, m, k, a):
    dp = [0] * (k + 1)
    ans = 0
    for s in a:
        idxs = [i for i in range(m) if s[i] == '1']
        l = len(idxs)
        
        if l > 0:
            saved = [0] * (l + 1)
            v = idxs[-1] - idxs[0] + 1
            
            ans += v
            saved[l] = v
            
            for i in range(l):
                for j in range(i, l):
                    saved[l - (j - i + 1)] = max(saved[l - (j - i + 1)], v - (idxs[j] - idxs[i] + 1))
            
            for i in range(k, 0, -1):
                for j in range(l + 1):
                    if i < j: break
                    dp[i] = max(dp[i], dp[i - j] + saved[j])
    return ans - dp[k]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
