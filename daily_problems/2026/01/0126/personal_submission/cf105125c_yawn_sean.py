# Submission link: https://codeforces.com/gym/105125/submission/359724711
def main(): 
    n, m = MII()
    cnt = [0] * (n * m + 1)
    for x in MII():
        cnt[x] += 1
    
    vals = []
    for i in range(n * m + 1):
        for j in range(cnt[i]):
            vals.append(i)
    
    for i in range(n * m):
        cnt[i + 1] += cnt[i]
    
    outs = []
    
    for i in range(1, n + 1):
        start = -1
        cur = i
        ans = []
        
        for _ in range(m):
            start += cur
            ans.append(vals[start])
            cur = fmin(cur, start - cnt[vals[start] - 1] + 1)
    
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))