n=int(input())
l=[]
j=1
for _ in range(n):
    a1,a2=list(map(int,input().split()))
    l.append([a1,a2])
    j+=1
if l[0][0] not in l[l[0][1]-1]:
    p=[1,l[0][0],l[0][1]]
else:
    p=[1,l[0][1],l[0][0]]
cnt=3
while cnt<n:
    a=p[-2]-1
    l[a].remove(p[-1])
    p.append(l[a][0])
    cnt+=1
print(*p)
