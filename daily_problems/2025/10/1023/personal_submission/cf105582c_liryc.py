'''
https://codeforces.com/gym/105582/submission/345752536
'''
# 二分+换零钱问题
def solve(n: int, m_min: int, m_max: int, a: list[list[int]]) -> int:
    dp = [0] * 10001
    def check(k):
        nonlocal n, m_min, m_max, a, dp
        OK, FAIL = 0, 1
        if k == 0:
            return OK
        for i in range(10001):
            dp[i] = 0
        
        dp[0] = 1
        
        for i in range(n):
            m, c = a[i][0], a[i][1] // k
            
            for j in range(m):
                upper_bound = -1
                for x in range(j, 10001, m):
                    if dp[x]:
                        upper_bound = pmax(upper_bound, x + c * m)
                    if x <= upper_bound:
                        dp[x] = 1
        for i in range(m_min, m_max + 1):
            if dp[i]:
                return OK
        return FAIL
    
    return bisect_right(range(1000001), 0, key=check) - 1
