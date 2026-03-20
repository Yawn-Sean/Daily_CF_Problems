n=int(input())
names=[]
scores=[]
others=[]

for _ in range(n):
    x,y=map(str,input().split())
    names.append(x)
    y=int(y)
    if y==0:
        scores.append(0)
        others.append(49)
    elif y==100:
        scores.append(9950)
        others.append(50)
    else:
        scores.append(100*y-50)
        others.append(99)

s=sum(scores)
sum_other=sum(others)
if s>10000 or s+sum_other<10000:
    print('IMPOSSIBLE')
else:
    res=10000-s
    for i in range(n):
        mn=scores[i]+max(0,res+others[i]-sum_other)
        mx=scores[i]+min(others[i],res)
        print(f'{names[i]} {mn//100}.{mn%100:02d} {mx//100}.{mx%100:02d}')