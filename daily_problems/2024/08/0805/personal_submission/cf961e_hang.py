class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)
    
    def add(self, i, x):
        while i <= self.n:
            self.bit[i] += x
            i += i & -i
    
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s
    

def main():
    n = int(input())
    a = list(map(int, input().split()))
    t = [[] for _ in range(n)]
    b = BIT(n)
    for i in range(n):
        t[min(a[i], n) - 1].append(i)
    res = 0
    for i in range(n-1, -1,-1):
        for x in t[i]:
            b.add(x + 1, 1)
        if a[i] - 1>= i + 1:
            res += b.sum(min(n, a[i])) - b.sum(i+1)
    print(res)


main()