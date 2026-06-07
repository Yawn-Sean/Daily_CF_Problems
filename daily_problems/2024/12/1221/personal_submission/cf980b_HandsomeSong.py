import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,k=MII()
res=[['.' for _ in range(n)] for _ in range(4)]
print("YES")
mid=n//2
if k%2:
    res[1][mid]='#'
    k-=1
for r in [1,2]:
    for c in range(1,mid):
        if k>=2:
            res[r][c]=res[r][n-1-c]='#'
            k-=2
if k>0:
    res[1][mid]=res[2][mid]='#'
    k-=2
for row in res:
    print(''.join(row))