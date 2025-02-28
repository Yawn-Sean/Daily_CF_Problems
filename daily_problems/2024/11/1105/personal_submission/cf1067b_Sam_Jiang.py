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
    n,k=MI()
    edges={i:set() for i in range(n)}
    degree=[0]*n
    for _ in range(n-1):
        a,b=GMI()
        edges[a].add(b)
        edges[b].add(a)
        degree[a]+=1
        degree[b]+=1
    if n<4:
        return 'No'
    queue=[i for i in range(n) if degree[i]==1]
    covered=set(queue)
    cnt=0
    while queue:
        parents={}
        tmp=[]
        for node in queue:
            tmp_cnt=0
            for neighbor in edges[node]:
                if neighbor not in covered:
                    tmp.append(neighbor)
                    tmp_cnt+=1
            if tmp_cnt!=1:
                return 'No'
            if tmp[-1] not in parents:
                parents[tmp[-1]]=1 
            else:
                parents[tmp[-1]]+=1
              
        for node in tmp:
            covered.add(node)
        

        if min(parents.values())<3:
            return 'No'
        queue=parents.keys()
        cnt+=1
        if len(queue)==1:
            if cnt==k:
                return 'Yes'
            return 'No'
                    
t=1
for i in range(t):
    w = main()
    print(w)
    



