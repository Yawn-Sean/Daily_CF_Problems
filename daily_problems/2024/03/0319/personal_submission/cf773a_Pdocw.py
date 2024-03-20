import math

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


def main():
    t = II()
    ans = []
    for _ in range(t):
        x, y, p, q = MII()
        if p == 0:
            ans.append(0 if not x else -1)
        elif p == q:
            ans.append(0 if x == y else -1)
        else:
            a = (x - 1) // p + 1
            b = (y - x - 1) // (q - p) + 1
            ans.append(max(a, b) * q - y)
    print("\n".join(str(res) for res in ans))
    return


t = 1
for _ in range(t):
    main()
