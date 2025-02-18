'''
https://codeforces.com/problemset/submission/698/294936002
698B
2024/12/5 Y1
1700
Tree, DSU
'''

# Kruskal

import sys
input = lambda: sys.stdin.readline().strip()

# 模板进行了修改，区分0（未初始化）和等于自身（root）两种情况
class UnionFind:
    def __init__(self, n: int):
        self.parent = [0] * (n + 1)
    def check(self, index1: int, index2: int) -> bool:
        return self.find(index1) == self.find(index2)
    def union(self, index1: int, index2: int):
        self.parent[self.find(index2)] = self.find(index1)
    def find(self, index: int) -> int:
        if self.parent[index] == index or self.parent[index] == 0:
            return index
        else:
            ans = index
            while self.parent[ans] and self.parent[ans] != ans:
                ans = self.parent[ans]
            while self.parent[index] and self.parent[index] != ans:
                self.parent[index], index = ans, self.parent[index]
            return ans
    def parent(self, index: int) -> int:
        return self.parent(index)
        
def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

# 直接应用Kruskal算法构建最小生成树，当出现无法构建的时候即是当前节点需要调整的时候
def solve(n: int, a: list[int]) -> list[int]:
    uni = UnionFind(n)
    root, ans, b = 0, 0, [x for x in a]
    # WA at test #10: 需要先找到第一个root，否则如果先出现环后面才出现root，会多了一次操作
    for i, p in enumerate(a):
        if i + 1 == p:
            root = p
            uni.union(p, p)
            break
    for i, p in enumerate(a):
        x = i + 1
        if x == p: # there's a root, but in total we can have at most 1 root
            if p != root:
                ans += 1
                b[x - 1] = root
                uni.union(root, x)
        elif uni.check(x, p): # there's a circle
            ans += 1
            if not root:
                root = x
                uni.union(x, x)
            else:
                uni.union(root, x)
            b[x - 1] = root
        else: # ok, just draw the edge
            uni.union(p, x)
    return ans, b

if __name__ == '__main__':
    args = init()
    ans, parent = solve(*args)
    print(ans)
    print(*parent)
