from typing import *
from collections import deque

class Fenwick:
    ...

class Solution:
    def solve(self, n: int, arr: List[int]) -> int:
        indices = {val: i for i, val in enumerate(sorted(set(arr) | {-10 ** 9 - 1}))}
        ft = Fenwick(len(indices))
        arr = arr[::-1]
        ft.update(indices[arr[-1]], 1)
        cur = deque([arr.pop()])
        ans = 0
        while arr:
            num = arr.pop()
            l, r = ft.range_query(0, indices[num] - 1), ft.range_query(indices[num] + 1, len(indices) - 1)
            if l <= r:
                ans += l
                cur.append(num)
            else:
                ans += r
                cur.appendleft(num)
            ft.update(indices[num], 1)
        return ans


TC = int(input())

def main():
    obj = Solution()
    for _ in range(TC):
        n = int(input())
        arr = list(map(int, input().split()))
        print(obj.solve(n, arr))

main()
