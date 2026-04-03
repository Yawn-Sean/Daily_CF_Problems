from math import gcd
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
    

prs = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

pp=[1]
for i in prs:
    for j in range(len(pp)):
        pp.append(pp[j]*i)
pp.sort()

t=II()
for _ in range(t):
    n=II()
    a=LII()
    
    vis=[0]*51
    for x in a:
        vis[x]=1
    for x in pp:
        for i in range(51):
            if vis[i] and gcd(i,x)==1:
                break

        else:
            print(x)
            break