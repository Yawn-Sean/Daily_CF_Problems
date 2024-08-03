n, d = map(int,input().split())
p = [-1]*(n+1)
c = 0
def find(x):
    if p[x] <0:
        return x
    return find(p[x])
    
for i in range(d):
    x,y = map(int,input().split())
    
    if find(x) ==find(y):
        c += 1
    else:
        p[find(x)] += p[find(y)]
        p[find(y)] = find(x)
    a = sorted(p)
    ans =sum(a[:c+1])
    print(-(1+ans))
