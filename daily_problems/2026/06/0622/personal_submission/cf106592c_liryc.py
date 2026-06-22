'''
https://codeforces.com/gym/106592/submission/379776358
'''
def solve(n: int, k: int, a: list[int]) -> str:      
    re = sum(a) - n
    if re == 0:
        return ' '.join(map(str, a))
    
    si = list(sorted(range(k), key=lambda i: ~a[i]))
    ans = [0] * k
    
    h = a[si[0]]
    
    for i in range(k):
        c = i + 1  
        nv = a[si[i + 1]] if i + 1 < k else 0
        
        d = h - nv
        maxr = d * c
        
        if re >= maxr:
            re -= maxr
            h = nv
        else:
            q, r = divmod(re, c)
            for idx in range(c):
                ans[si[idx]] = h - q - (1 if idx < r else 0)
            for idx in range(c, k):
                ans[si[idx]] = a[si[idx]]
            break
    return ' '.join(map(str, ans))
