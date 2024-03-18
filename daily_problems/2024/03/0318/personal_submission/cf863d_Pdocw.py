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
    n, q, m = MII()
    nums = LII()
    queries = [LGMI() for _ in range(q)]
    b = LGMI()
    for op, l, r in reversed(queries):
        if op == 0:
            for i in range(m):
                if l < b[i] <= r:
                    b[i] -= 1
                elif b[i] == l:
                    b[i] = r
        else:
            for i in range (m):
                if l <= b[i] <= r:
                    b[i] = l + r - b[i]
    print(' '.join(map(str, (nums[idx] for idx in b))))
    return

t = 1
for _ in range(t):
    main()
