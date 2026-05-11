import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n=II()
    a=LII()
    mn=min(a[1:-1])
    if a[0]<mn and a[-1]<mn:
        print('YES')
    else:
        print('NO')