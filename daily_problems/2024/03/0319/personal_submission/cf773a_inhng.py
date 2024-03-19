import sys
input = sys.stdin.readline
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    x, y, p, q = map(int, input().split())
    if not p:
        print(-1 if x else 0)
        continue
    if p == q:
        print(0 if x == y else -1)
        continue
    print(q * max((x + p - 1) // p, ((y - x) + (q - p) - 1) // (q - p)) - y)
