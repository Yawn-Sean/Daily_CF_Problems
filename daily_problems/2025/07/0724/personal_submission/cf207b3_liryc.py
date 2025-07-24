'''
(CF died, sumit link to be committed)
207 B3
2025/07/24 Y1
1700
RMQ
'''
# RMQ
from sys import stdin
input = lambda: stdin.readline().strip()
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x

class SparseTable:
    def __init__(self, a):
        n = len(a)
        l1 = n.bit_length() + 1
        self.st = [[(0, 0)] * l1 for _ in range(n)]
        for i in range(n):
            self.st[i][0] = a[i]
        for j in range(1, l1):
            pj = 1 << j - 1
            for i in range(n - pj):
                self.st[i][j] = pmin(self.st[i][j - 1], self.st[i + pj][j - 1])
    def query(self, l: int, r: int):
        lt = r - l + 1
        q = lt.bit_length() - 1
        return pmin(self.st[l][q], self.st[r - (1 << q) + 1][q])
    
def init():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    return n, a

def solve(n: int, a: list[int]) -> int:
    m = n << 1
    a *= 2
    b = [0 if i < x else i - x for i, x in enumerate(a)]
    st = SparseTable([(x, i) for i, x in enumerate(b)])
    nth = [[0] * m for _ in range(20)]
    
    for i in range(m):
        nth[0][i] = st.query(b[i], i)[1]
    
    for i in range(1, 20):
        for j in range(m):
            nth[i][j] = nth[i - 1][nth[i - 1][j]]
    
    ans = 0
    
    for i in range(n, m):
        if i - b[i] >= n - 1:
            ans += 1
            continue
        
        c = i
        for j in range(19, -1, -1):
            if i - b[nth[j][c]] < n - 1:
                ans += 1 << j
                c = nth[j][c]
        ans += 2
    
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
