import sys
input=lambda:sys.stdin.readline()
a=input().split(',')
s=[]
ans=[]
n=len(a)
for i in range(0,n,2):
    a[i+1]=int(a[i+1])
    if(len(s)>=len(ans)):
        ans.append([]) 
    ans[len(s)].append(a[i])
    s.append(a[i+1])
    while(len(s)>0 and s[-1]==0):
        s.pop(-1)
        if(len(s)>0):
            s[-1]-=1
print(len(ans))
for i in ans:
    print(' '.join(i))
