import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

def solve():
    n, p, k = map(int, input().split())
    a = sorted([0] + list(map(int, input().split())))
    for i in range(1, n + 1):
        if i < k:
            a[i] += a[i - 1]
        else:
            a[i] += a[i - k]
    for i in range(n, -1, -1):
        if a[i] <= p:
            print(i)
            return
    print(n)
    
if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
