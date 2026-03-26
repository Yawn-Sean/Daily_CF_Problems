def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
A={4:1,8:2,15:3,16:4,23:5,42:6}
a=LII()
cnt=[0]*7
cnt[0]=n
for x in a:
    x=A[x]
    if cnt[x-1]:
        cnt[x-1]-=1
        cnt[x]+=1
print(n-6*cnt[6])