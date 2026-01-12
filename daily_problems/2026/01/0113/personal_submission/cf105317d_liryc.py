'''
2026/1/13 Y1
1700
tree, LCA
'''
# 关键思路：（1）分解质因数然后状态压缩编码；（2）用前缀和和LCA查询树的路径和
from collections import deque
from sys import stdin
input = lambda: stdin.readline().strip()
pmin = lambda x, y: y if y < x else x

class SparseTable:
    def __init__(self, a: list[int]):
        n = len(a)
        l1 = n.bit_length() + 1
        self.st = [[0] * l1 for _ in range(n)]
        for i in range(n):
            self.st[i][0] = a[i]
        for j in range(1, l1):
            pj = 1 << j - 1
            for i in range(n - pj):
                self.st[i][j] = pmin(self.st[i][j - 1], self.st[i + pj][j - 1]) #*#
    def query(self, l: int, r: int):
        lt = r - l + 1
        q = lt.bit_length() - 1
        return pmin(self.st[l][q], self.st[r - (1 << q) + 1][q]) #*#
    
def init():
    n = int(input())
    a = list(map(int, input().split()))
    tg = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        tg[u].append(v)
        tg[v].append(u)
    q = int(input())
    qa = [[0, 0] for _ in range(q)]
    for i in range(q):
        u, v = map(int, input().split())
        qa[i][:] = u - 1, v - 1
    return n, a, tg, q, qa

def solve(n: int, a: list[int], tg: list[list[int]], q: int, qa: list[list[int]]) -> list[int]:
    # 质数集合
    prime_set = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
    pi = [-1] * 71
    for i, p in enumerate(prime_set):
        pi[p] = i
    # 分解质因数
    def prime_elements(x: int):
        nonlocal prime_set
        for p in prime_set:
            if p * p > x: 
                break
            c = 0
            d, v = divmod(x, p)
            while v == 0:
                c += 1
                x = d
                d, v = divmod(x, p)
            if c:
                yield p, c
        if x > 1:
            yield x, 1
    # 按质因数编码
    def enc(x: int):
        nonlocal pi
        m = 0
        for e, c in prime_elements(x):
            if c & 1:
                m |= pi[e]
        return m
    # 前缀异或和
    ps = [0] * n
    # dfs and euler sequence
    pr = [-1] * n # parent of each node
    lv = [0] * n # level of each node
    fp = [-1] * n # first occur of each tree node in ES
    es = [] # euler sequence (value=level | code, code=bitset of primes)
    stk = deque()
    stk.append(0)
    while stk:
        u = stk.pop()
        if u < 0:
            u = ~u
            es.append(lv[i] << 20 | u)
        else:
            s = 0 if u == 0 else ps[pr[u]]
            ps[u] = s ^ enc(a[u])
            es.append(lv[i] << 20 | u)
            fp[u] = len(es) - 1
            for v in tg[u]:
                if pr[v] < 0:
                    pr[v] = u
                    lv[v] = lv[u] + 1
                    stk.append(~u)
                    stk.append(v)
    # lca(u, v): 
    # assume u < v, lca is min(x for x in es[u..v])
    # so, inorder to calc this, need RMQ/ST
    st = SparseTable(es) #ST(min, es)
    def lca(u, v):
        nonlocal fp, st
        s, t = fp[u], fp[v]
        if s > t:
            s, t = t, s
        return st.query(s, t) & (1 << 20) - 1
    
    def ans(u, v):
        nonlocal pr, ps
        c = lca(u, v)
        m = ps[u] ^ ps[v] ^ ps[c]
        if c:
            m ^= ps[pr[c]]
        return 1 if m else 0

    return [ans(u, v) for u, v in qa]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(*ans, sep='\n')
