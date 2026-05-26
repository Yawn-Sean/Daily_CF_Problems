'''
https://codeforces.com/gym/105437/submission/376166738
'''
def solve(n: int, m: int, ra: list[int]) -> int:
    dp = [0] * (m + 2)
    df = [0] * (m + 2)
    x = 0  
    for r in ra:
        if r == 0:
            c = 0
            for s in range(x + 1):
                c += df[s]
                dp[s] += c
                df[s] = 0  
            df[x + 1] = 0  
            for s in range(x + 1, 0, -1):
                if dp[s - 1] > dp[s]:
                    dp[s] = dp[s - 1]
            x += 1
        elif r > 0: 
            if r <= x:
                df[0] += 1
                df[x - r + 1] -= 1
        else: 
            req = -r
            if req <= x:
                df[req] += 1
                df[x + 1] -= 1
    c = 0
    ans = 0
    for s in range(x + 1):
        c += df[s]
        dp[s] += c
        if dp[s] > ans:
            ans = dp[s]
    return ans
