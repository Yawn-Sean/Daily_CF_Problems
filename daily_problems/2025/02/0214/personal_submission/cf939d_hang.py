class UF:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)
def main():
    n = int(input())
    a = input()
    b = input()
    ans = 0
    out = []
    uf = UF(26)
    for x,y in zip(a,b):
        if uf.find(ord(x)-ord('a')) != uf.find(ord(y)-ord('a')):
            ans += 1
            out.append(f'{x} {y}')
            uf.union(ord(x)-ord('a'), ord(y)-ord('a'))
    print(ans)
    for x in out:
        print(x)


main()