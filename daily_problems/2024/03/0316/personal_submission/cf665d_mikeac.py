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

mxn = 2 * 10 ** 6
factor = [1] * (mxn + 1)
primes = set()
def init():
    for i in range(2, mxn + 1):
        if factor[i] != 1:
        # if factor[i]:
            continue
        primes.add(i)
        for j in range(i, mxn + 1, i):
            factor[j] = i

def isPrime(x: int) -> bool:
    d = 2
    while d * d <= x:
        if x % d == 0:
            return False
        d += 1
    return True

def solve() -> None:
    n = sint()
    nums = ints()
    one = nums.count(1)
    a = b = -1
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] == nums[j]:
                continue
            # if isPrime(nums[i] + nums[j]):
            if nums[i] + nums[j] in primes:
                if nums[i] == 1 or nums[j] == 1:
                    x = nums[i] + nums[j] - 1
                    print(one + 1)
                    ans = [1] * one + [x]
                    print(*ans)
                    return
                else:
                    a, b = nums[i], nums[j]
    if one > 1:
        print(one)
        print(*([1] * one))
    elif a != -1:
        print(2)
        print(a, b)
    else:
        print(1)
        print(nums[0])

init()
solve()
