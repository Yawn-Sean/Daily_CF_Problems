# Submission link: https://codeforces.com/gym/105427/submission/359337912
def main(): 
    n, k = MII()
    vals = [k + 1]
    cnt = [1]
    
    while vals[-1] < n and len(vals) < k:
        vals.append(vals[-1] * k + 1)
        cnt.append(cnt[-1] * k + 1)
    
    ans = fmax(n - vals[-1], 0)
    n -= ans
    
    for i in range(len(vals) - 1, -1, -1):
        x, n = divmod(n, vals[i])
        ans += x * cnt[i]
    
    print(ans)