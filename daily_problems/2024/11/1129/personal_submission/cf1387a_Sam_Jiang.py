import sys,math,heapq
from collections import Counter
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
    edges={i:{} for i in range(n)}
    flag=True
    for _ in range(m):
        a,b,w=MI()
        a-=1
        b-=1
        if b not in edges[a]:
            edges[a][b]=w 
            edges[b][a]=w 
        else:
            if w!=edges[a][b]:
                flag=False 

    if not flag:
        print('NO')
        return 
    
    to_be_solved=set()
    relations=[None for i in range(n)]
    solved={}
    covered=set()
    for i in range(n):
        
        if i not in covered:
            covered.add(i)
            to_be_solved.add(i)
            queue=[i]
            relations[i]=[0,1,i] #constant, coef, variable name 
            
            while queue:
                tmp=[]
                for node in queue:
                    for neighbor in edges[node]:
                        if neighbor not in covered:
                            covered.add(neighbor)
                            tmp.append(neighbor)
                            relations[neighbor]=[edges[node][neighbor]-relations[node][0],-relations[node][1],relations[node][2]]
                            
                        else:
                            const,coef,var=relations[neighbor][0],relations[neighbor][1],relations[neighbor][2]
                            if coef+relations[node][1]==0:
                                if const+relations[node][0]!=edges[node][neighbor]:
                                    print('NO')
                                    return 
                            else:
                                cc=const+relations[node][0]
                                coeff=coef+relations[node][1]
                                tmp1=(edges[node][neighbor]-cc)/coeff 
                                if relations[node][2] not in solved:
                                    solved[relations[node][2]]=tmp1
                                else:
                                    if abs(tmp1-solved[relations[node][2]])>1e-8:
                                        print('NO')
                                        return 
                queue=tmp 
    
    dict_var={}
    for i in relations:
        if i[2] not in solved:
            if i[2] not in dict_var:
                dict_var[i[2]]=[(i[0],i[1])]
            else:
                dict_var[i[2]].append((i[0],i[1]))
    
    for var in dict_var:
        lst=[]
        for info in dict_var[var]:
            if info[1]==1:
                lst.append(info[0])
            else:
                lst.append(-info[0])
        lst.sort()
        solved[var]=-lst[len(lst)//2]
    print('YES')
    ans=[]
    for i in range(n):
        t=relations[i]
        ans.append(t[0]+t[1]*solved[t[2]])
    print(*ans)
                                      
t=1
for i in range(t):
    w = main()

