# Submission link: https://codeforces.com/contest/1482/submission/301310969
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m = MII()
        ars = [None] * m
        for i in range(m):
            k, *ars[i] = MII()
        
        cnt = [0] * (n + 1)
        ans = [0] * m
        
        v = 0
        for i in range(m):
            ans[i] = ars[i][0]
            cnt[ans[i]] += 1
            if cnt[ans[i]] > cnt[v]:
                v = ans[i]
        
        ma_freq = m - m // 2
        for i in range(m):
            if ans[i] == v and cnt[v] > ma_freq and len(ars[i]) > 1:
                ans[i] = ars[i][1]
                cnt[v] -= 1

        if cnt[v] <= ma_freq:
            outs.append('YES')
            outs.append(' '.join(map(str, ans)))
        else:
            outs.append('NO')

    print('\n'.join(outs))