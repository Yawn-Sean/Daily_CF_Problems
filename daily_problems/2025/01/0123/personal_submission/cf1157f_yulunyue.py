from app.yly.algo.manage import SolutionBase,View,np
from typing import Dict,List
from functools import lru_cache
from collections import defaultdict
import bisect
MOD=(10**9)+7
inf = float("inf")
class Solution(SolutionBase):
    def get_cases(self):
        return [
                        dict(input='''5
3 7 5 1 5''',result='''2
5 5'''),    
            dict(input='''7
4 3 5 1 2 2 1''',result='''5
2 1 1 2 3'''),

        ]
    

    def exec(self):
        self.i1()
        ct=dict()
        for v in self.il():
            ct[v]=ct.get(v,0)+1
        keys=sorted(ct.keys())
        vv=uu=l=keys[0]
        ans=tmp=ct[uu]
        for i in range(1,len(keys)):
            if keys[i-1]+1!=keys[i]:
                tmp=ct[keys[i]]
                l=keys[i]
                if tmp>ans:
                    ans,vv,uu=tmp,keys[i],l
            else:
                tmp+=ct[keys[i]]
                if tmp>ans:
                    ans,vv,uu=tmp,keys[i],l
                if ct[keys[i]]==1:
                    tmp=ct[keys[i]]
                    l=keys[i]

        # self.log(ans,uu,vv)
        self.output(ans)
        result=[]
        for v in range(uu,vv+1):
            result.append(str(v))
        for v in range(vv,uu-1,-1):
            if ct[v]>1:
                result.extend([str(v)]*(ct[v]-1))
        # self.log(ct," ".join(result))
        self.output(" ".join(result))



if __name__=='__main__':
    Solution().run()
