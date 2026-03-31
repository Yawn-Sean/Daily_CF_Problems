
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
    

n,q=MII()
grid=[LII() for _ in range(n)]
saved=[[n*n+1]*(n*n+1)for _ in range(n)]

for i in range(n):
    for j in range(n):
        for k in range(n):
            if i+k>=n or j+k>=n:
                break
            saved[k][grid[i][j]]=min(saved[k][grid[i][j]],grid[i+k][j+k])

for i in range(n):
    for j in range(n * n - 1, -1, -1):
        saved[i][j] = min(saved[i][j], saved[i][j + 1])

for _ in range(q):
    a,b=MII()
    for i in range(n-1,-1,-1):
        if saved[i][a]<=b:
            print((i+1)**2)
            break