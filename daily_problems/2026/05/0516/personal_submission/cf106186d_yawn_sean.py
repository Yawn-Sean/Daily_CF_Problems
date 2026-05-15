# Submission link: https://codeforces.com/gym/106186/submission/374605786
def main():  
    M = 10 ** 5 + 5
    pr = [1] * M
    pr[0] = 0
    pr[1] = 0
    
    for i in range(2, M):
        if pr[i]:
            for j in range(2 * i, M, i):
                pr[j] = 0
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v1 = LII()
        v2 = LII()
        
        c1 = [0] * (n + 1)
        c2 = [0] * (n + 1)
        
        for x in v1:
            c1[x] += 1
        
        for x in v2:
            c2[x] += 1
        
        for i in range(1, n + 1):
            for j in range(2 * i, n + 1, i):
                c1[i] += c1[j]
                c2[i] += c2[j]
        
        c = [x * y for x, y in zip(c1, c2)]
        
        for i in range(n, 0, -1):
            for j in range(2 * i, n + 1, i):
                c[i] -= c[j]
        
        ans = 0
        for i in range(n + 1):
            if pr[i]:
                ans += c[i]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))