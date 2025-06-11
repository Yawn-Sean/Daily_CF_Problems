n=int(input())
s=list(map(int,input().split()))
max_1=-1
max_2=-1
cnt=[0]*(n+1)
for i in s:
    if i>max_1:
        max_2=max_1
        max_1=i
        cnt[i]-=1
        
    elif i>max_2:
        max_2=i
        cnt[max_1]+=1
cnt=cnt[1::]
print(cnt.index(max(cnt))+1)
