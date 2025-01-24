from app.yly.algo.manage import SolutionBase,View,np
from typing import Dict,List
from common.algo.unifind import UniFind
from functools import lru_cache
from collections import defaultdict
import bisect
MOD=(10**9)+7
inf = float("inf")
class Solution(SolutionBase):
    def get_cases(self):
        return [
            dict(
                input='''1 2
2 1
3 1 1''',result='''YES'''
            ),
            dict(input='''2 3
1 2 1
2 1
3 2 1''',result='NO'),
            dict(input='''4 9
1 4 3
2 4
3 3 1
1 2 3
2 2
3 1 2
1 3 1
2 2
3 1 3''',result='''YES
NO
YES''')
        ]
    

        
    def exec(self):
        n,m=self.il()
        edges=[[]]
        node_ids=[None]
        lt,rt=[-1]*(n+1),[-1]*(n+1)
        p=dict()
        dt=[]
        ct=0
        g=defaultdict(list)
        for _ in range(m):
            t,x,*args=self.il()
            if t==1:
                edges[-1].append([x,args[0]])
                g[args[0]].append(x)
                p[x]=args[0]
            elif t==2:
                node_ids.append(x)
                edges.append([])
            else:
                dt.append([args[0],x,ct,'NO'])
                ct+=1
        self.time_vt=0
        def dfs(u):
            self.time_vt+=1
            lt[u]=self.time_vt
            for v in g[u]:
                dfs(v)
            self.time_vt+=1
            rt[u]=self.time_vt
        for i in range(1,n+1):
            if i not in p:
                dfs(i)
        dt.sort()
        l=0
        uf=UniFind()
        for i in range(len(dt)):
            while l<dt[i][0]:
                for x,y in edges[l]:
                    uf.merge(y,x)
                l+=1
            p_id=node_ids[dt[i][0]]
            q_id=dt[i][1]
            # self.log(q_id,p_id)
            if uf.find(q_id)!=uf.find(p_id): # 不在一颗树
                continue
            if lt[q_id]<=lt[p_id] and rt[q_id]>=rt[p_id]:
                dt[i][-1]='YES'
        for _,_,_,s in sorted(dt,key=lambda v:v[2]):
            self.output(s)
        # self.log(dt)
        # self.log(edges)



if __name__=='__main__':
    Solution().run()
