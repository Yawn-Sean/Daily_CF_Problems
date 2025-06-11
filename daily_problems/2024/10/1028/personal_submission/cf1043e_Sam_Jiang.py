import sys
input = lambda: sys.stdin.readline().strip()
def I():
    return input()
def II():
    return int(input())
def MI():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def LFI():
    return list(map(float, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

def main():
    n,m=MI()
    lst=[None]*n
    for i in range(n):
        a,b=MI()
        lst[i]=(a,b,i)
  
    strong=sorted(lst,key=lambda x:(x[0]-x[1]))
    value=[0]*n
    postfix=sum(strong[i][1] for i in range(n))
    prefix=0
    for i in range(n):
        postfix-=strong[i][1]
        value[strong[i][2]]=strong[i][1]*i+strong[i][0]*(n-1-i)+postfix+prefix 
        prefix+=strong[i][0]
      
    for _ in range(m):
        a,b=GMI()
        t1,t2=lst[a],lst[b]
        score=min(t1[0]+t2[1],t1[1]+t2[0])
        value[a]-=score 
        value[b]-=score 
    return value

t = 1
for i in range(t):
    w = main()
    print(*w)
