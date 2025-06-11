class UF:
    def __init__(self, n):
        self.parent = list(range(n))
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)
def main():
    n,m = map(int, input().split())
    us,vs,ws = [],[],[]
    for i in range(m):
        u,v,w = map(int, input().split())
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
    ans = 10 ** 9
    uf = UF(n)  # 最终结果是一个连通块
    uf1 = UF(n) # 最终结果是两个连通块
    uf.union(us[0], vs[0]) # 合并第一条边的两个端点
    w_range = sorted(range(1, m), key = lambda x: ws[x])
    for i in w_range:
        if uf.find(us[i]) != uf.find(vs[i]):
            uf.union(us[i], vs[i])
            uf1.union(us[i], vs[i])
    # 两个连通块的最小边即为答案
    for i in w_range:
        if uf1.find(us[i]) != uf1.find(vs[i]):
            ans = ws[i]
            break
    print(ans)
main()