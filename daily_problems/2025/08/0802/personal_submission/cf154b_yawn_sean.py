# Submission link: https://codeforces.com/contest/154/submission/331964414
def main():
    n, m = MII()
    
    prime_factor = list(range(n + 1))
    
    for i in range(2, n + 1):
        if prime_factor[i] == i:
            for j in range(i, n + 1, i):
                prime_factor[j] = i
    
    status = [0] * (n + 1)
    prime_note = [[] for _ in range(n + 1)]
    
    outs = []
    
    for _ in range(m):
        c, x = LI()
        x = int(x)
        
        if c == '-':
            if status[x]:
                outs.append('Success')
                status[x] = 0
            else:
                outs.append('Already off')
        
        else:
            if status[x]:
                outs.append('Already on')
            else:
                prs = []
                v = x
                while v > 1:
                    p = prime_factor[v]
                    while v % p == 0:
                        v //= p
                    prs.append(p)
                
                conflict = -1
                for p in prs:
                    while prime_note[p] and status[prime_note[p][-1]] == 0:
                        prime_note[p].pop()
                    
                    if prime_note[p]:
                        conflict = prime_note[p][-1]
                
                if conflict != -1:
                    outs.append(f'Conflict with {conflict}')
                else:
                    status[x] = 1
                    for pr in prs:
                        prime_note[pr].append(x)
                    outs.append('Success')
    
    print('\n'.join(outs))