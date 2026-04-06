# Submission link: https://codeforces.com/gym/106457/submission/369971318
def main(): 
    d = {
        'X': 0,
        'P': 1,
        'I': 2
    }
    
    def query(x, y):
        print('?', x, y, flush=True)
        return d[I()]
    
    n, t, b = MII()
    
    ans = [[0] * (n + 1) for _ in range(n + 1)]
    l, r = t, t
    
    for i in range(1, n + 1):
        ans[1][i] = query(1, i)
        ans[n][i] = query(n, i)
        if ans[1][i]:
            l = fmin(l, i)
            r = fmax(r, i)
    
    for i in range(2, n):
        ans[i][l] = query(i, l)
        
        if ans[i][l]:
            while l > 1:
                l -= 1
                ans[i][l] = query(i, l)
                if ans[i][l] == 0:
                    l += 1
                    break
        else:
            while l < n:
                l += 1
                ans[i][l] = query(i, l)
                if ans[i][l]:
                    break
        
        ans[i][r] = query(i, r)
        
        if ans[i][r]:
            while r < n:
                r += 1
                ans[i][r] = query(i, r)
                if ans[i][r] == 0:
                    r -= 1
                    break
        else:
            while r > 1:
                r -= 1
                ans[i][r] = query(i, r)
                if ans[i][r]:
                    break
        
        for j in range(l + 1, r):
            ans[i][j] = 2
    
    print('!', sum(sum(x) for x in ans) - 2, end='')