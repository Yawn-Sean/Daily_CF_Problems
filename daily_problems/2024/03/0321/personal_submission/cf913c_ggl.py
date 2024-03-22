import sys
input = lambda: sys.stdin.readline().strip()
inf = float('inf')

def I():
    return input()
 
def II():
    return int(input())

def MII():
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


n, L = MII()
a = sorted(list(zip(LII(), range(n))), key = lambda p : p[0] / (1 << p[1]))
def check(m):
    tot = 0
    for x , i in a:
        cnt = m // x
        m -= x * cnt
        tot += cnt * (1 << i)                
        if tot >= L:
            return True
    return False

l , r = 0 , a[0][0] * L
while l < r:
    m = l + r >> 1
    if check(m):
        r = m
    else:
        l = m + 1
print(l)        

