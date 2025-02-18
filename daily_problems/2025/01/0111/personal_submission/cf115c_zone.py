n, m = MII() 
g = [I() for _ in range(n)]

vr = [-1] * n 
vc = [-1] * m 

for i in range(n):
    for j in range(m):
        if g[i][j] != '.':
            r = (j & 1) ^ (g[i][j] in '12')
            c = (i & 1) ^ (g[i][j] in '14')

            if vr[i] == -1: vr[i] = r 
            if vc[j] == -1: vc[j] = c 

            if vr[i] != r or vc[j] != c: exit(print(0))

mod = 10 ** 6 + 3 
print(pow(2, vr.count(-1) + vc.count(-1), mod))
