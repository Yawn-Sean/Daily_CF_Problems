import sys
import math
input = lambda: sys.stdin.readline().strip()
def I():
    return input()
def II():
    return int(input())
def MI():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def LFI():
    return list(map(float, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

def main():
    n=II()
    a=LII()
    b=LII()
    c=LII()
    if n==1:
        return a[0]
    dp=[[0]*2 for i in range(n)]
    dp[0][0]=a[0]
    dp[0][1]=-math.inf
    for i in range(1,n):
        dp[i][0]=a[i]+max(dp[i-1][0]+b[i-1]-a[i-1],dp[i-1][1]+c[i-1]-b[i-1])          
        dp[i][1]= max(dp[i-1][0]+b[i],dp[i-1][1]+b[i])
      
    return max(dp[-1])

t = 1
for i in range(t):
    w = main()
    print(w)
