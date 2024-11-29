# Submission link: https://codeforces.com/contest/119/submission/293574116
def main():
    n, m, k = MII()

    ls = []
    rs = []
    cs = []

    for _ in range(m):
        l, r, c = MII()
        ls.append(l)
        rs.append(r)
        cs.append(c)

    st_range = sorted(range(m), key=lambda x: -cs[x])

    def f(cnt, idx, num):
        return (cnt * m + idx) * 101 + num

    dp = [-1] * (n * m * 101)
    prev = [-1] * (n * m * 101)

    for i in range(m):
        x = st_range[i]
        for num in range(rs[x] - ls[x] + 1):
            dp[f(0, x, num)] = ls[x] + num
        
        for j in range(i):
            y = st_range[j]
            if cs[x] == cs[y]: break
            
            for cnt in range(n - 1):
                for num in range(rs[y] - ls[y] + 1):
                    omsk = f(cnt, y, num)
                    if dp[omsk] != -1:
                        nnum = num + ls[y] - k - ls[x]
                        if 0 <= nnum <= rs[x] - ls[x]:
                            msk = f(cnt + 1, x, nnum)
                            if dp[omsk] + nnum + ls[x] > dp[msk]:
                                dp[msk] = dp[omsk] + nnum + ls[x]
                                prev[msk] = omsk
                        
                        if (num + ls[y]) % k == 0:
                            nnum = (num + ls[y]) // k - ls[x]
                            if 0 <= nnum <= rs[x] - ls[x]:
                                msk = f(cnt + 1, x, nnum)
                                if dp[omsk] + nnum + ls[x] > dp[msk]:
                                    dp[msk] = dp[omsk] + nnum + ls[x]
                                    prev[msk] = omsk

    ans = -1
    end_msk = -1

    for idx in range(m):
        for num in range(rs[idx] - ls[idx] + 1):
            if dp[f(n - 1, idx, num)] > ans:
                ans = dp[f(n - 1, idx, num)]
                end_msk = f(n - 1, idx, num)

    if ans == -1:
        print('NO')
    else:
        print('YES')
        outs = []
        while end_msk != -1:
            idx, num = end_msk // 101 % m, end_msk % 101
            outs.append(f'{idx + 1} {ls[idx] + num}')
            end_msk = prev[end_msk]
        print('\n'.join(outs))