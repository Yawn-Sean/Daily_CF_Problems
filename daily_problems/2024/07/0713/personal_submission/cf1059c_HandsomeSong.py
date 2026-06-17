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
def f(n):
    if n<=3:
        return [1]*(n-1)+[n]
    else:
        return [1]*(n-n//2)+[x*2 for x in f(n//2)]
n=II()
print(' '.join(map(str,f(n))))