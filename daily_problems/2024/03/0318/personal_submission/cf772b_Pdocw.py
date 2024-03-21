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


def S(a, b, c):  # 海伦公式求面积
    p = (a + b + c) / 2
    return (p * (p - a) * (p - b) * (p - c)) ** 0.5


def dis(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


def main():
    n = II()
    lx, ly = [], []
    for _ in range(n):
        x, y = MII()
        lx.append(x)
        ly.append(y)
    ans = inf
    # for i in range(-1, n - 1):
    #     a = dis(lx[i], ly[i], lx[i - 1], ly[i - 1])
    #     b = dis(lx[i], ly[i], lx[i + 1], ly[i + 1])
    #     c = dis(lx[i - 1], ly[i - 1], lx[i + 1], ly[i + 1])
    #     s = S(a, b, c)
    #     ans = min(ans, s * 2 / c)
    for i in range(-1, n - 1):
        dx1 = lx[i] - lx[i - 1]
        dy1 = ly[i] - ly[i - 1]
        dx2 = lx[i + 1] - lx[i]
        dy2 = ly[i + 1] - ly[i]
        dx3 = lx[i - 1] - lx[i + 1]
        dy3 = ly[i - 1] - ly[i + 1]
        # 叉乘求面积
        h = abs(dx1 * dy2 - dx2 * dy1) / (dx3**2 + dy3**2) ** 0.5
        ans = min(ans, h)
    print(ans / 2)
    return


t = 1
for _ in range(t):
    main()
