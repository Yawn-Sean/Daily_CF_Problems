# Submission link: https://codeforces.com/gym/106523/submission/375221514
def main():
    M = 10 ** 5 + 5
    pr = list(range(M))
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range(i, M, i):
                pr[j] = i
    
    q = II()
    
    cur = [0] * M
    to_multiply = []
    
    outs = []
    
    for _ in range(q):
        t, x = MII()
        
        if t == 1:
            while x > 1:
                if cur[pr[x]] == 0:
                    to_multiply.append(pr[x])
                cur[pr[x]] += 1
                x //= pr[x]
        
        elif t == 2:
            new_to_multipy = []
            for v in to_multiply:
                cur[v] *= x
                if cur[v] < 20:
                    new_to_multipy.append(v)
            
            to_multiply = new_to_multipy
        
        else:
            cnt = Counter()
            while x > 1:
                cnt[pr[x]] += 1
                x //= pr[x]
            
            flg = True
            
            for x in cnt:
                if cnt[x] > cur[x]:
                    flg = False
            
            outs.append('Yes' if flg else 'No')
    
    print('\n'.join(outs))