import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    a,b=MII()
    if a|b!=a:
        print(-1)
    else:
        vals=[i for i in range(a+1) if i&a==i]
        xor=0
        for v in vals:
            xor^=v
        xor^=b
        if xor:
            vals.remove(xor)
        oor=0
        for v in vals:
            oor|=v
        if oor==a:
            print(len(vals))
            print(*vals)
        else:
            print(-1)