def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
u=LII()
freq=[0]*(10**5+10)
cnt_freq =[0]*(10**5+10)
distinct=0
mx=0
ans=1
for i in range(n):
    c=u[i]
    if freq[c]==0:
        distinct+=1
    cnt_freq[freq[c]]-=1
    freq[c]+=1
    cnt_freq[freq[c]]+=1
    mx=max(mx,freq[c])
    if cnt_freq[mx]==1 and cnt_freq[mx-1]==distinct-1 or cnt_freq[1] == 1 and cnt_freq[mx] == distinct - 1 or mx == 1:
        ans=i+1
print(ans)