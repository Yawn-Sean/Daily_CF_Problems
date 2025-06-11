class DSU:
    def __init__(self, n):
        self.parent = list(range(2 * n + 1))
        self.size = [0] * (2 * n + 1)
        for i in range(1, n + 1):
            self.size[i] = 1
    
    def find(self, x):
        if self.parent[x] != x:
            root = self.find(self.parent[x])
            self.size[self.parent[x]] += self.size[x]
            self.size[x] = 0
            self.parent[x] = root
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.size[rootX] += self.size[rootY]
            self.size[rootY] = 0
            self.parent[rootY] = rootX

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        
        dsu = DSU(n)
        
        for _ in range(m):
            x = int(data[index])
            y = int(data[index + 1])
            s = data[index + 2]
            index += 3
            
            if s == "crewmate":
                dsu.union(x, y)
                dsu.union(x + n, y + n)
            else:  # s == "imposter"
                dsu.union(x, y + n)
                dsu.union(y, x + n)
        
        ans = 0
        contradiction = False
        for i in range(1, n + 1):
            if dsu.find(i) == dsu.find(i + n):
                contradiction = True
                break
            ans += max(dsu.size[dsu.find(i)], dsu.size[dsu.find(i + n)])
            dsu.size[dsu.find(i)] = 0
            dsu.size[dsu.find(i + n)] = 0
        
        if contradiction:
            results.append(-1)
        else:
            results.append(ans)
    
    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    main()
