class Matrix:
    def __init__(self, size):
        self.size = size
        self.G = [[0.0] * size for _ in range(size)]

    def clear(self):
        for i in range(self.size):
            for j in range(self.size):
                self.G[i][j] = 0.0

    def init_identity(self):
        self.clear()
        for i in range(self.size):
            self.G[i][i] = 1.0

    def __mul__(self, other):
        res = Matrix(self.size)
        res.clear()
        for i in range(self.size):
            for j in range(self.size):
                for k in range(self.size):
                    res.G[i][j] += self.G[i][k] * other.G[k][j]
        return res

def multi(base, exp):
    size = base.size
    res = Matrix(size)
    res.init_identity()
    while exp > 0:
        if exp & 1:
            res = res * base
        exp >>= 1
        base = base * base
    return res

n, x = map(int, input().split())
p = list(map(float, input().split()))

size = 128
a = Matrix(size)

for i in range(size):
    for j in range(size):
        a.G[i][j] = p[i ^ j] if i ^ j <= x else 0.0

res= multi(a, n)

print(f"{1.0 - res.G[0][0]:.6f}")
