import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
idx_a=[(i,a[i]) for i in range(n)]
idx_a.sort(key =lambda x:x[1],reverse=True)
res=['B']*n
for i,av in idx_a:
    k=1
    while True:
        j=i+k*av
        if j>=n:
            break
        if a[j]>av:
            if res[j]=='B':
                res[i]='A'
                break
        k+=1
    if res[i]=='A':
        continue
    k=1
    while True:
        j=i-k*av
        if j<0:
            break
        if a[j]>av:
            if res[j] =='B':
                res[i]='A'
                break
        k+=1
print(''.join(res))