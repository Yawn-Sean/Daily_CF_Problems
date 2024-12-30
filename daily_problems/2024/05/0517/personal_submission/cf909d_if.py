import math
l=[]
cnt=1
s=input()
n=len(s)
for i in range(n):
    if i==n-1:
        if cnt>1:
            l.append([cnt,s[i]])
            cnt=1
        else:
            l.append([1,s[i]])
        break
    if s[i+1]==s[i]:
        cnt+=1
    else:
        l.append([cnt,s[i]])
        cnt=1
if cnt>1:
    l.append([cnt,s[-1]])
ll=[i[0] for i in l]
length=len(ll)
cnt=0
while length>1:
    ll=[i[0] for i in l]
    tar=min(ll[0],ll[-1],math.ceil(min(ll[1:length-1:]+[9999999])/2))
    for i in range(length):
        if i==0 or i==length-1:
            l[i][0]-=tar
        else:
            l[i][0]-=2*tar
    p=[]
    for i in l:
        if i[0]<=0:
            length-=1
            continue
        if p and p[-1][1]==i[1]:
            p[-1][0]+=i[0]
            length-=1
            continue
        p.append(i)
    l=p[:]
    cnt+=tar
print(cnt)
