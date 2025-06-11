'''
https://codeforces.com/problemset/submission/566/293166609
566D
2024/11/25 Y2
1900
union-find
'''
# u1: all union, u2: only type2 union, find(y)==(the leftmost union of y)
import sys
input = lambda: sys.stdin.readline().strip()

class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
    def check(self, index1: int, index2: int) -> bool:
        return self.find(index1) == self.find(index2)
    def union(self, index1: int, index2: int):
        self.parent[self.find(index2)] = self.find(index1)
    def find(self, index: int) -> int:
        if self.parent[index] == index:
            return index
        else:
            ans = index
            while self.parent[ans] != ans:
                ans = self.parent[ans]
            while self.parent[index] != ans:
                self.parent[index], index = ans, self.parent[index]
            return ans

if __name__ == '__main__':
    n, q = map(int, input().split())
    u1, u2 = UnionFind(n), UnionFind(n)
    for _ in range(q):
        t, x, y = map(int, input().split())
        x, y = x - 1, y - 1
        if t == 1:
            u1.union(x, y)
        elif t == 2:
            y0 = u2.find(y)
            while y0 > x:
                u1.union(y0 - 1, y0)
                u2.union(y0 - 1, y0)
                y0 = u2.find(y0)
        else: # t == 3
            print("YES" if u1.check(x, y) else "NO")

