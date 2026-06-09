# Submission link: https://codeforces.com/gym/105383/submission/377875506
def main():
    n = II()
    p1 = LGMI()
    p2 = LGMI()
    
    p = [0] * n
    for i in range(n):
        p[p1[i]] = p2[i]
    
    fen = FenwickTree(n)
    notes = []
    rev_pairs = 0
    
    for x in p:
        notes.append(fen.rsum(x + 1, n - 1))
        rev_pairs += notes[-1]
        fen.add(x, 1)
    
    if rev_pairs % 2:
        print('No')
    else:
        rev_pairs //= 2
        
        q = list(range(n))
        
        for i in range(n):
            if rev_pairs < notes[i]:
                q[:i] = sorted(q[:i], key=lambda x: p[x])
                p[:i] = sorted(p[:i])
                
                for j in range(rev_pairs):
                    p[i - j], p[i - j - 1] = p[i - j - 1], p[i - j]
                    q[i - j], q[i - j - 1] = q[i - j - 1], q[i - j]
                
                break
            else:
                rev_pairs -= notes[i]
        
        print('Yes')
        print(' '.join(str(x + 1) for x in q))
        print(' '.join(str(x + 1) for x in p))