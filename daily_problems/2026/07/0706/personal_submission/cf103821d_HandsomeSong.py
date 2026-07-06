import sys
input = sys.stdin.readline
def II():
    return int(input())
t=II()
for _ in range(t):
    n=II()
    k=int((n+1)**0.5)
    if k*k!=n+1:
        print(-1)
    else:
        print(k-1)
        print(*range(1,k))