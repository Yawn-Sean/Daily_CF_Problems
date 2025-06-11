"""
    排序後，從小到大加入，同時使用併查集維護集合大小
    若加入後發現左側或右側相鄰元素已經加入，則需要合併集合
"""

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.fa = list(range(n))
        self.sz = [1] * (n)

    def find(self, x):
        if self.fa[x] != x:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]

    def merge(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx == fy:
            return False
        if self.sz[fx] > self.sz[fy]:
            fx, fy = fy, fx
        self.fa[fx] = fy
        self.sz[fy] += self.sz[fx]
        return True

n = int(input())
A = list(map(int, input().split()))

uf = UnionFind(n + 1)
vis = [False] * (n + 2)

ans_k = float('inf')  # 答案的 k 值
ans_n = 0             # 答案對應的集合數量

n_set = 0      # 當前集合數量
max_size = 0   # 最大集合大小
n_equal = 0    # 與最大集合大小相等的集合數量

for idx, v in sorted(enumerate(A, 1), key=lambda x: x[1]):
    vis[idx] = True

    # 處理左邊相鄰的元素
    if vis[idx - 1]:
        n_set -= 1
        if uf.sz[uf.find(idx - 1)] == max_size:
            n_equal -= 1
        uf.merge(idx, idx - 1)

    # 處理右邊相鄰的元素
    if vis[idx + 1]:
        n_set -= 1
        if uf.sz[uf.find(idx+1)] == max_size:
            n_equal -= 1
        uf.merge(idx, idx+1)

    n_set += 1
    new_sz = uf.sz[uf.find(idx)]
    if max_size < new_sz:
        n_equal = 1
        max_size = new_sz
    elif max_size == new_sz:
        n_equal += 1

    # 當滿足 n_set == n_equal 時，更新答案
    if n_set == n_equal:
        if n_set > ans_n or (n_set == ans_n and ans_k > v + 1):
            ans_k = v + 1
            ans_n = n_set

print(ans_k)
