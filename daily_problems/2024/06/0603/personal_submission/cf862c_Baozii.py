from functools import reduce
from operator import xor

MAX = 1 << 17

class Solution:
    def solve(self, n: int, x: int):
        if n == 1:
            return [x]
        if n == 2:
            if x == 0:
                return list()
            return [MAX, x ^ MAX]
        ans = list(range(1, n - 2))
        xorsum = reduce(xor, ans) if ans else 0
        if xorsum == x:
            ans.extend([MAX, MAX * 2, MAX ^ (MAX * 2)])
        else:
            ans.extend([0, MAX, MAX ^ x ^ xorsum])
        return ans

TC = 1

def main():
    obj = Solution()
    for _ in range(TC):
        n, x = map(int, input().split())
        ans = obj.solve(n, x)
        if not ans:
            print("NO")
        else:
            print("YES")
            print(*ans)

main()
