def main():
    n = II()
    nums = LGMI()

    saved = [[n] * (n + 1) for _ in range(8)]

    for i in range(n - 1, -1, -1):
        if i < n - 1:
            for j in range(8):
                saved[j][i] = saved[j][i+1]
        saved[nums[i]][i] = i

    def process():
        for i in range(8):
            for j in range(n):
                if next_pos[i][j] < n:
                    next_pos[i][j] = saved[i][next_pos[i][j] + 1]

    next_pos = [saved[i][:] for i in range(8)]

    ans = len(set(nums))

    for cnt in range(1, n + 1):
        dp = [[n] * (1 << 8) for _ in range(9)]
        dp[0][0] = -1
        
        for cur_cnt in range(9):
            for msk in range(1 << 8):
                
                if dp[cur_cnt][msk] < n:
                    for i in range(8):
                        
                        if msk >> i & 1 == 0:
                            p = next_pos[i][dp[cur_cnt][msk] + 1]
                            if p < dp[cur_cnt][msk | (1 << i)]:
                                dp[cur_cnt][msk | (1 << i)] = p
                            
                            if p < n:
                                np = saved[i][p+1]
                                if np < dp[cur_cnt + 1][msk | (1 << i)]:
                                    dp[cur_cnt + 1][msk | (1 << i)] = np
                    
                    if msk == 255:
                        ans = max(ans, cnt * 8 + cur_cnt)
        process()

    print(ans)
