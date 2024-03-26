class UF:
    def __init__(self, n:int) -> None:
        self.parent = list(range(n))
    def find(self, a:int) -> int:
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    def merge(self, a:int, b:int) -> bool:
        a = self.find(a)
        b = self.find(b)
        if a != b:
            self.parent[a] = b
            return True
        else:
            return False
def main():
    n,m,q = map(int,input().split())
    ans = n + m - 1
    uf = UF(n+m)
    for _ in range(q):
        u,v = map(int,input().split())
        u ,v = u-1,v-1
        ans -= uf.merge(u,v+n)
    print(ans)
main()
