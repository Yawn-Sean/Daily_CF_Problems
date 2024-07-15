
class BIT:
    def __init__(self, n):
        self.tree = [0] * (n + 1)
    
    def add(self, i, v):
        while i < len(self.tree):
            self.tree[i] += v
            i += i & -i
    
    def query(self, i):
        ans = 0
        while i:
            ans += self.tree[i]
            i &= i - 1
        return ans

def main():
    n, k = map(int, input().split())
    a = []
    f = [0] * (n + 1) 
    for i in range(1, n + 1):
        a.append(int(input()))
        f[a[-1]] = 1

    for i in range(1, k + 1):  
        tree = BIT(n)
        for j in range(1, n + 1):
            tree.add(a[j - 1], f[j])
            f[j] = tree.query(a[j - 1] - 1)

    print(sum(f))
main()