mod = 10**9 + 7

class Matrix:
    def __init__(self, p=[[0,0], [0,0]]):
        self.p = p;
    def __mul__(self, other):
        res = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    res[i][j] = (res[i][j] + self.p[i][k] * other.p[k][j]) % mod
        return Matrix(res)

def ksm(a, k):
    res = Matrix([[1, 0], [0, 1]])
    while k > 0:
        if k % 2 == 1:
            res = res * a
        a = a * a
        k //= 2
    return res
def solve():
    a, b, n, x = MII()

    B = Matrix([[a, b], [0, 1]])
    C = Matrix([[x, 0], [1, 0]])

    B = ksm(B, n)
    B = B * C
    print(B.p[0][0] % mod)
solve()
