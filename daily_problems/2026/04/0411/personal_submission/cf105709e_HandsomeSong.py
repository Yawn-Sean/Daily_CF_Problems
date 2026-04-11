from collections import defaultdict
class DSU:
    def __init__(self,n):
        self.parent=list(range(n+1))
        self.size=[1]*(n+1)
        self.max_size=1
    def find(self,i):
        if self.parent[i]!=i:
            self.parent[i]=self.find(self.parent[i])
        return self.parent[i]
    def union(self,i,j):
        root_i=self.find(i)
        root_j=self.find(j)
        if root_i==root_j:
            return
        if self.size[root_i]<self.size[root_j]:
            root_i,root_j=root_j,root_i
        self.parent[root_j]=root_i
        self.size[root_i]+=self.size[root_j]
        if self.size[root_i]>self.max_size:
            self.max_size=self.size[root_i]
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())

n,k,q=MII()
s=[]
for _ in range(n):
    s.append(input())
dsu=DSU(n)
visited=[False]*(k+1)
cate=[[]for _ in range(10)]
for _ in range(q):
    t=LII()
    if t[0]==1:
        if visited[t[1]]:
            continue
        visited[t[1]]=True
        groups=defaultdict(list)
        for i in range(1,n+1):
            char=s[i-1][t[1]-1]
            groups[char].append(i)
        for char,group_list in groups.items():
            if len(group_list)>1:
                base_bird = group_list[0]
                for other_bird in group_list[1:]:
                    dsu.union(base_bird, other_bird)
    elif t[0]==2:
        print(dsu.size[dsu.find(t[1])])   
    elif t[0]==3:
        print(dsu.max_size)