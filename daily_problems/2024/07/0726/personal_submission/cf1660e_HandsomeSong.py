import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
def I():
    return input().strip()
t=II()
for _ in range(t):
    n_str = I()
    while not n_str:
        n_str = I()
    n = int(n_str)
    cnt=[0]*n
    for i in range(n):
        s=I()
        for j in range(n):
            if s[j]=='1':
                cnt[(i-j)%n]+=1
    print(sum(cnt)+n-max(cnt)*2)
