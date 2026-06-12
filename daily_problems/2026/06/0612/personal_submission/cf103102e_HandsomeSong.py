import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
valid=[]
for s in range(3):
    for q in range(3):
        prevs=[s*3+q,((s-1)%3*3+(q-1)%3),((s-2)%3*3+(q-1)%3)]
        valid.append(prevs)
cnt=[0]*9
ans=0
ps=0
pq=0
for stt in valid[0]:
    ans+=cnt[stt]
cnt[0]+=1
for i in range(n):
    r=a[i]%3
    ps=(ps+r)%3
    pq=(pq+r*r)%3
    state=ps*3+pq
    for stt in valid[state]:
        ans+=cnt[stt]
    cnt[state]+=1
print(ans)
