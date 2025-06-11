

from typing import List, Dict, Optional
from collections import defaultdict, deque, Counter
from itertools import accumulate, product, permutations
from functools import lru_cache
import bisect
import sys
import math
import heapq


def case_load(sl):
    return dict(
        n=int(sl[0]),
        vids=[list(map(int, v.split(' '))) for v in sl[1:-1]],
        result=sl[-1]
    )


try:
    from app.yly.manage import SolutionBase
    SolutionBase.case_load = case_load
except:
    class SolutionBase:

        def log(self, *args, **kwargs):
            pass

        def execute(self, *args, **kwargs):
            pass

        def run(self):
            sl = [input()]
            for _ in range(int(sl[0])):
                sl.append(input())
            sl.append("")
            print(self.execute(**case_load(sl)))

inf = float("inf")
M = (10**9)+7


class UniFind:
    def __init__(self, n) -> None:
        self.p = [-1]*n
        # self.size = defaultdict(int)
        self.value = [0]*n

    def merge(self, parent, child, val=0):
        parent1, pval = self.find(parent)
        child1, cval = self.find(child)
        val += pval-cval
        self.value[child] = val
        if parent1 == child1:
            return parent1, False
        self.p[parent1] += self.p[child1]
        self.p[child1] = parent1
        return parent1, True

    def find(self, idx):
        idz = idy = idx
        value = 0
        while self.p[idx] >= 0:
            value += self.value[idx]
            idx = self.p[idx]
        while idy != idx:
            self.value[idy], value = value, value-self.value[idy]
            self.p[idy], idy = idx, self.p[idy]
        return idy, self.value[idz]

    def update(self):
        for k in self.p:
            self.find(k)

    def get_pkeys(self):
        return set(list(self.p.values()))


class Solution(SolutionBase):
    uri = ""
    gameid = ''

    def get_cases(self):
        return [
            '''
6
0
0
1 2 1
2 1 5 2 2
1 1 2
1 3 4
30
''', '''
10
0
0
0
1 3 -823680354
1 3 -850620736
2 3 640948460 2 -822416813
0
1 7 668611485
0
3 4 -642324044 8 609375785 9 -62137735
864760239
'''
        ]

    def execute(self, n, vids, **kw):
        ans = 0
        uf = UniFind(n+1)
        for pid, ids in enumerate(vids, 1):
            for i in range(1, len(ids), 2):
                cid, value = ids[i], ids[i+1]
                parent, val = uf.find(cid)
                val += value
                ans += val
                uf.merge(pid, parent, val)

                # self.log(pid, cid, value, ans, values, values[parent])
        # self.log(p)
        return ans % M


if __name__ == '__main__':
    Solution().run()
