import sys,math,heapq
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
    n=II()
    lst=[]
    for _ in range(n):
        a,b,c=MI()
        lst.append((a,b,c))
    edg=[-1]*n
    for i in range(n):
        for j in range(i+1,n):
            x1,y1,r1=lst[i]
            x2,y2,r2=lst[j]
            if (r2-r1)*(r2-r1)>=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2):
                if r2>r1:
                    if edg[i]<0 or lst[edg[i]][2]>r2:
                        edg[i]=j
                else:
                    if edg[j]<0 or lst[edg[j]][2]>r1:
                        edg[j]=i 
    edges={i:set() for i in range(n)}
    ans=0
    queue=[]
    for i in range(n):
        if edg[i]!=-1:
            edges[edg[i]].add(i)
        else:
            ans+=lst[i][2]*lst[i][2]
            queue.append(i)
    tmp=[]      
    for node in queue:
        for neighbor in edges[node]:
            ans+=lst[neighbor][2]*lst[neighbor][2]
            tmp.append(neighbor)

    queue=tmp
    level_cnt=0
    while queue:
        tmp=[]
        for node in queue:
            for neighbor in edges[node]:
                tmp.append(neighbor)
                if level_cnt%2==0:
                    ans-=lst[neighbor][2]*lst[neighbor][2]
                else:
                    ans+=lst[neighbor][2]*lst[neighbor][2]
        queue=tmp 
        level_cnt+=1 
    return ans*math.pi
            
t=1
for i in range(t):
    w = main()
    print(w)
    
    



