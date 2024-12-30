from collections import Counter

t=int(input())
for _ in range(t):
    n=int(input())
    c=list(map(int,input().split()))
    cnt=Counter(c)
    l=[]
    for i in cnt.values():
        l.append(i)

    for i in range(min(l)+1,0,-1):
        for j in l:
            p=j//i
            if p>=i-1-(j%i)or j%i==0:
                pass
            else:
                break
        else:
            s=0
            for j in l:
                s+=j//i
                if j%i:
                    s+=1
            print(s)
            break
