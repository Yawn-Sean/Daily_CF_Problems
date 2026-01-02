# Submission link: https://codeforces.com/gym/104770/submission/356131449
def main(): 
    n, m, k = MII()
    deg = [0] * (n + 1)
    outs = []
    
    for _ in range(m + k):
        u, v = MII()
        deg[u] ^= 1
        deg[v] ^= 1
        if u > 1 and v > 1:
            outs.append(f'1 {u} {v}')
    
    if max(deg): print('NO')
    else:
        print('YES')
        print(len(outs))
        print('\n'.join(outs))