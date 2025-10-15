# Submission link: https://codeforces.com/contest/1183/submission/304633923
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        
        cnt = [0] * (n + 1)
        cnt1 = [0] * (n + 1)
        
        for _ in range(n):
            a, f = MII()
            cnt[a] += 1
            if f: cnt1[a] += 1
        
        st_range = [i for i in range(n + 1) if cnt[i]]
        st_range.sort(key=lambda x: -cnt[x])
        
        ans0 = 0
        ans1 = 0
        
        pt = 0
        hpq = []
        for i in range(n, 0, -1):
            while pt < len(st_range) and cnt[st_range[pt]] >= i:
                heappush(hpq, -cnt1[st_range[pt]])
                pt += 1
            
            if hpq:
                ans0 += i
                ans1 += fmin(i, -heappop(hpq))
        
        outs.append(f'{ans0} {ans1}')

    print('\n'.join(outs))