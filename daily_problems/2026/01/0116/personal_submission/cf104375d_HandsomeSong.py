import bisect
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
n,q=MII()
a=LII()
a.sort()
for _ in range(q):
    opr=LI()
    if opr[0]=='1':
        k=int(opr[1])
        if k > a[-1]:
            a.append(k)
        else:
            p=bisect.bisect_right(a,k)
            if p>0 and a[p-1]==k:
                continue
            else:
                a[p]=k
    else:
        l=int(opr[1])
        r=int(opr[2])
        print(bisect.bisect_right(a,r)-bisect.bisect_left(a,l))