from app.yly.algo.manage import SolutionBase,View,np
from typing import Dict,List
from functools import lru_cache
from collections import defaultdict
import bisect
MOD=(10**9)+7
inf = float("inf")
class Solution(SolutionBase):
    uri="https://codeforces.com/problemset/problem/1044/A"
    def get_cases(self):
        return [
            dict(input='''4 7
1
2
3
4
1 1000000000 1
1 1000000000 2
1 1000000000 3
1 1000000000 4
1 1000000000 5
1 1000000000 6
1 1000000000 7''',result=7),
            dict(input='''0 2
1 1000000000 4
1 1000000000 2''',result=2),
            dict(input='''1 3
4
1 5 3
1 9 4
4 6 6''',result=1),
            dict(input='''2 3
6
8
1 5 6
1 9 4
2 4 2''',result=1),
            dict(input='''2 3
4
6
1 4 3
1 5 2
1 6 5''',result=2),
        ]
    

        
    def exec(self,**kw):
        n,m=self.il()
        col_x=[]
        row_x=[]
        X_MAX=10**9
        x_max=0
        for _ in range(n):
            x=self.i1()
            col_x.append(x)
        for _ in range(m):
            x1,x2,_=self.il()
            if x1==1:
                x_max+=x2==X_MAX
                row_x.append(x2)
        ans=x_max+len(col_x)
        col_x.sort()
        row_x.sort()
        l=0
        # self.log(row_x)
        # self.log(col_x)
        for i,v in enumerate(col_x):
            while l<len(row_x) and row_x[l]<v:
                l+=1
            result=len(row_x)-l+i
            # self.log(i,v,row_x[l:],result)
            if result<ans:
                ans=result
        return ans
        



if __name__=='__main__':
    Solution().run()
