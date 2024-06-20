# -*- coding: utf-8 -*-
# @Project: leetcode
# @File    : __init__.py.py
# @Author  : Ng_Chun-fai
# @Time    : 2024-06-16 10:23:00

from bisect import bisect_left, bisect_right
from collections import deque, Counter, defaultdict
from functools import cache
from itertools import pairwise
from math import inf
from typing import List, Optional

from sortedcontainers import SortedList


class Fenwick:
    __slots__ = 'tree'

    def __init__(self, n: int):
        self.tree = [0] * n

    # 把下标为 i 的元素增加 1
    def add(self, i: int, val: int) -> None:
        while i < len(self.tree):
            self.tree[i] += val
            i += i & -i

    # 返回下标在 [1,i] 的元素之和
    def pre(self, i: int) -> int:
        res = 0
        while i > 0:
            res += self.tree[i]
            i &= i - 1
        return res


class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        c = defaultdict(int)
        ans = 0
        for e in hours:
            ans += c[(24 - e % 24) % 24]
            c[e % 24] += 1
        return ans

    def maximumTotalDamage(self, power: List[int]) -> int:
        c = defaultdict(int)
        for e in power:
            c[e] += 1
        li = []
        for k, v in c.items():
            li.append((k, v))
        li.sort()
        f = [0] * len(li)
        ans = 0
        for i, (k, v) in enumerate(li):
            for j in range(5, 0, -1):
                if i - j >= 0 and k - li[i - j][0] > 2:
                    f[i] = max(f[i], f[i - j])
            f[i] += k * v
            ans = max(f[i], ans)
        return ans

    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        tr = Fenwick(n + 1)
        ans = []

        def check(idx: int) -> bool:
            return nums[idx - 1] < nums[idx] and nums[idx] > nums[idx + 1]

        for i in range(1, n - 1):
            if check(i):
                tr.add(i, 1)

        for x, y, z in queries:
            if x == 1:
                if z - y < 2:
                    ans.append(0)
                    continue
                v = tr.pre(z - 1) - tr.pre(y)
                ans.append(v)
            else:
                v = nums[y]
                for index in (y - 1, y, y + 1):
                    if 0 < index < n - 1:
                        flag = check(index)
                        nums[y] = z
                        if check(index) != flag:
                            if flag:
                                tr.add(index, -1)
                            else:
                                tr.add(index, 1)
                        nums[y] = v
                nums[y] = z
        return ans


if __name__ == "__main__":
    run_code = 0
    so = Solution()
    # print(so.countCompleteDayPairs([12, 12, 30, 24, 24]))
    # print(so.countCompleteDayPairs([72, 48, 24, 3]))

    # print(so.maximumTotalDamage([1, 1, 3, 4]))
    # print(so.maximumTotalDamage([7, 1, 6, 6]))

    # print(so.countOfPeaks([3, 1, 4, 2, 5], [[2, 3, 4], [1, 0, 4]]))
    # print(so.countOfPeaks([4, 1, 4, 2, 1, 5], [[2, 2, 4], [1, 0, 2], [1, 0, 4]]))
    print(so.countOfPeaks([8, 7, 10],
                          [[1, 1, 1], [2, 2, 4], [1, 0, 1], [2, 1, 9], [1, 0, 2]]))
    print()
