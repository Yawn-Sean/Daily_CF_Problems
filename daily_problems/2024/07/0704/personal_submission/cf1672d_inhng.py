import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    memo = [0] * (n + 1)
    last = 0
    for ai in a:
        if ai == b[last]:
            last += 1
        else:
            memo[ai] += 1
        while 0 < last < n and b[last] == b[last - 1] and memo[b[last]]:
            memo[b[last]] -= 1
            last += 1
    print("YES" if last == n else "NO")
