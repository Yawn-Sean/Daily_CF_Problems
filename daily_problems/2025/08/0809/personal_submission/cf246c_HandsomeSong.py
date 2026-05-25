import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,k=MII()
a=LII()
a.sort(reverse=True)
out=[]
for i in range(n):
    for j in range(i,n):
        cur=[]
        for x in range(i):
            cur.append(a[x])
        cur.append(a[j])
        out.append(f'{len(cur)} {" ".join(map(str,cur))}')
print('\n'.join(out[:k]))