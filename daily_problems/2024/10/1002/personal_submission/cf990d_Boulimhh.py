n, a, b = map(int,input().split())
if a>1 and b>1: print("NO"); exit()
if 2<=n<=3 and a == b == 1: print("NO"); exit()
print("YES")

if b == 1:
    adj = [[0]*n for i in range(n)]
    conn = n
    for i in range(n):
        if conn == a: break
        adj[i][i+1] = adj[i+1][i] = 1
        conn-= 1
        if conn == a: break
elif a == 1:
    adj = [[1]*n for i in range(n)]
    conn = n
    for i in range(n): adj[i][i] = 0
    for i in range(n):
        if conn == b: break
        adj[i][i+1] = adj[i+1][i] = 0
        conn-= 1
        if conn == b: break

for row in adj:
    print(*row, sep='')
