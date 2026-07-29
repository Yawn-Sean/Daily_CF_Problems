import sys
input = lambda: sys.stdin.readline().rstrip()

def z(s):
    n = len(s)
    z = [0] * n
    l = r = 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z

def solve():
    s = input()
    n = len(s)
    a = z(s)
    b = z(s[::-1])
    b.reverse()
    ans = 0
    for i in range(n - 1, 1, -1):
        x = min(i - 1, a[i])
        y = min(n - i, b[i - 1])
        y = min(i - 1, y)
        ans += max(0, x + y - i + 1)
    print(ans)

T = int(input())
for _ in range(T):
    solve()
