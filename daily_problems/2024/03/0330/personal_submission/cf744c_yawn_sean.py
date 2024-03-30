def main():
    n = II()
    cnt_r = [0] * (1 << n)
    cnt_b = [0] * (1 << n)

    cost_r = []
    cost_b = []

    for i in range(n):
        c, r, b = LI()
        
        if c == 'R':
            cnt_r[1 << i] = 1
        else:
            cnt_b[1 << i] = 1
        
        cost_r.append(int(r))
        cost_b.append(int(b))

    for msk in range(1 << n):
        x = msk & -msk
        cnt_r[msk] = cnt_r[msk - x] + cnt_r[x]
        cnt_b[msk] = cnt_b[msk - x] + cnt_b[x]

    dp = [[-1] * (1 << n) for _ in range(128)]
    dp[0][0] = 0

    for i in range(128):
        for msk in range(1 << n):
            if dp[i][msk] != -1:
                
                for j in range(n):
                    if msk >> j & 1 == 0:
                        n_msk = msk | (1 << j)
                        n_saved = i + min(cnt_r[msk], cost_r[j])
                        dp[n_saved][n_msk] = max(dp[n_saved][n_msk], dp[i][msk] + min(cnt_b[msk], cost_b[j]))

    sum_r = sum(cost_r)
    sum_b = sum(cost_b)

    total_spent = 10 ** 9
    for i in range(128):
        if dp[i][-1] != -1:
            total_spent = min(total_spent, max(sum_r - i, sum_b - dp[i][-1]))

    print(n + total_spent)