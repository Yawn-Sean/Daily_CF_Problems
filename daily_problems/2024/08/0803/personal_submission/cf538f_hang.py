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
    nums = list(map(int, input().split()))
    f = BIT(n)
    ans = [0] * n
    for i in sorted(range(n), key=lambda x: nums[x]):
        for k in range(1, n):
            l, r = k * i + 1, k * (i + 1)
            if l >= n: 
                break
            r = min(r, n - 1)
            ans[k] += f.sum(r+1) - f.sum(l)
        f.add(i + 1, 1)
    print(*ans[1:])
main()