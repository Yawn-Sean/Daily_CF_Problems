"""
problem url   : https://codeforces.com/problemset/problem/990/D
submission url: https://codeforces.com/contest/990/submission/283994207
"""

n, a, b = MII() 
if n == a == b == 1: 
    exit(print("YES\n0"))
if (a != 1 and b != 1) or (a == b == 1 and n <= 3): 
    exit(print("NO"))
adj = [[0] * n for _ in range(n)]
m = max(a, b)
for i in range(n - m):
    adj[i][i + 1] = adj[i + 1][i] = 1 
if a == 1: 
    for i in range(n):
        for j in range(n):
            if i == j: continue 
            adj[i][j] ^= 1
print("YES")
print('\n'.join(''.join(str(y) for y in x) for x in adj))
