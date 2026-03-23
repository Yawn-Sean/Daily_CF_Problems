# Submission link: https://codeforces.com/gym/102154/submission/367897021
def main(): 
    n = II()
    perm = LGMI()
    
    ops = []
    help_perm = list(range(n))
    
    def op(l, r):
        ops.append(f'{l + 1} {r + 1}')
        half = (r - l + 1) // 2
        vals = []
        for i in range(half):
            vals.append(help_perm[l + i + half])
            vals.append(help_perm[l + i])
        for i in range(l, r + 1):
            help_perm[i] = vals[i - l]
    
    for _ in range(500):
        l = random.randint(0, n - 1)
        r = random.randint(0, n - 1)
        
        if (r - l) % 2:
            if l > r: l, r = r, l
            op(l, r)
    
    for i in range(n - 1, -1, -1):
        for j in range(i):
            if help_perm[j] == perm[i]:
                cur = j
                while cur != i:
                    v = fmin(cur + 1, i - cur)
                    op(cur - v + 1, cur + v)
                    cur += v
    
    ops.reverse()
    
    print(len(ops))
    print('\n'.join(ops))