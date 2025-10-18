# -*- coding: UTF-8 -*-
from Yean_Sawn_Template import *
"""
thinking process in 104848M.md
"""
def main():
    n,m,T=MII()
    e=lst_lst(n+1)
    for _ in range(m):
        u,v,l,c=MII()
        S=math.sqrt(l*c)
        e.append(u,(v,S))
        e.append(v,(u,S))
    dis=[inf]*(n+1)
    dis[1]=0
    heap=[]
    heappush(heap,(0,1))
    while heap:
        d,u=heappop(heap)
        if d!=dis[u]:
            continue
        for v,w in e.iterate(u):
            nd=d+w
            if dis[v]>nd:
                dis[v]=nd
                heappush(heap,(nd,v))
    ans=dis[n]
    ans=ans*ans/T
    print(f"{ans:.8f}")
    return

multi_test = 0
if __name__ == "__main__":
    T = II() if multi_test else 1
    for _ in range(T):
        main()
