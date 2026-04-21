# Submission link: https://codeforces.com/gym/106494/submission/371953263
def main():
    n = II()
    ls = LII()
    rs = LII()
    
    idx = ls.index(max(ls))
    ans = [0] * n
    
    total = 0
    for i in range(n):
        if i != idx:
            ans[i] = fmin(rs[i], ls[idx])
            total += ans[i]
        else: ans[i] = ls[i]
    
    if total >= ls[idx]: print(*ans)
    else: print(-1)