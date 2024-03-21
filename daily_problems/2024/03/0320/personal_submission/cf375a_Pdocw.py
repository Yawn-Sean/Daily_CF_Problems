import math
from collections import Counter, defaultdict, deque
from itertools import accumulate, combinations, permutations, count, product

inf = math.inf


def I():
    return input()


def II():
    return int(input())


def MII():
    return map(int, input().split())


def LI():
    return list(input().split())


def LII():
    return list(map(int, input().split()))


def LFI():
    return list(map(float, input().split()))


def GMI():
    return map(lambda x: int(x) - 1, input().split())


def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))


def quick_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * (n + 1)

    def add(self, i, x):
        while i <= self.n:
            self.data[i] += x
            i += i & -i

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s


modd = [""] * 7
for p in permutations("1689"):
    modd[int("".join(p)) % 7] = "".join(p)


def main():
    s = I()
    cnt = Counter(s)
    cnt["1"] -= 1
    cnt["6"] -= 1
    cnt["8"] -= 1
    cnt["9"] -= 1
    ans = []
    for x in cnt:
        if x != "0":
            ans.append(x * cnt[x])
    ans = "".join(ans)
    mod = 0
    for x in ans:
        mod = (mod * 10 + int(x)) % 7

    print(ans + modd[(-mod * 10000) % 7] + "0" * cnt["0"])
    return


t = 1
for _ in range(t):
    main()
