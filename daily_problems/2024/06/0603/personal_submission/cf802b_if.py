import heapq
n, k  = map(int, input().split())
a=list(map(int, input().split()))
d={}
pos={}
Q=[]
cnt=0
for i, x in enumerate(a):
    if x not in pos:
        pos[x] = []
    pos[x].append(i)
for i, x in enumerate(a):
    if x not in d:
        cnt += 1
        if len(d) == k:
            pos_, x_ = heapq.heappop(Q)
            del d[x_]
        d[x] = 1
    pos[x].pop(0)
    if len(pos[x]) > 0:
        heapq.heappush(Q, (-pos[x][0], x))
    else:
        heapq.heappush(Q, (-float('inf'), x))   
print(cnt)        
    
