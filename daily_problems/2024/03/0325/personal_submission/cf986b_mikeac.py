import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

class BIT:
    def __init__(self, n: int):
        self.nums = [0] * (n + 1)
        self.n = n
        self.BITree = [0] * (self.n + 1)
        
    def lowbit(self, x: int) -> int:
        return x & -x
    
    def query(self, x: int) -> int:
        ans = 0
        while x:
            ans += self.BITree[x]
            x -= self.lowbit(x)
        return ans

    def add(self, x: int, val: int):
        while x <= self.n:
            self.BITree[x] += val
            x += self.lowbit(x)

    def update(self, x: int, val: int) -> None:
        self.add(x + 1, val - self.nums[x])
        self.nums[x] = val

    # 逆序对
    def getPairOfInversion(nums: list) -> int:
        bit = BIT(max(nums))
        res = 0
        for i in range(len(nums) - 1, -1, -1):
            res += bit.query(nums[i])
            bit.update(nums[i], 1)
        return res
    
def solve() -> None:
    n = sint()
    nums = ints()
    cnt = BIT.getPairOfInversion(nums)
    print("Petr" if cnt & 1 == n & 1 else "Um_nik")


solve()
