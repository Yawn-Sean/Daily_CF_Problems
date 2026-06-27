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
    total=sum(a)
    if n==1:
        print(total)
    else:
        print(total^(total-a[-1])^(total-a[0])^(total-a[0]-a[-1]))