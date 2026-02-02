'''
https://codeforces.com/gym/104758/submission/361106275
'''
# 单调栈 ref from LC42 接雨水
def solve(n: int, a: list[int]) -> int:
    dq = deque()
    dp = [0] * n 
    max_water = 0
    for i, h in enumerate(a): 
        if h > 0:
            water, d = 0, 0
            while dq: 
                i0, h0 = dq[-1], a[dq[-1]]
                water += (pmin(h, h0) - d) * (i - i0 - 1)
                d = h0
                if h0 >= h: 
                    break 
                else:
                    dq.pop()
                    if dq: 
                        water += dp[i0]
            dp[i] = water
            max_water = pmax(max_water, water)

            while dq and a[dq[-1]] == h: 
                i0 = dq.pop()
                dp[i] += dp[i0]

            dq.append(i)

    return max_water
