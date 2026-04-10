def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

t=II()
for _ in range(t):
    n=II()
    a=LII()
    days=n-1
    sta=0
    cur=0
    for i in range(n):
        if cur<0:
            cur+=sta
            days+=1
        sta=max(sta,a[i])
        cur-=1
    print(days)
        