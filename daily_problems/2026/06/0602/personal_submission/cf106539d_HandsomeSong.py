import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
    return input().strip()
t=II()
for _ in range(t):
    n,m=MII()
    print(min(n,m//2+1))