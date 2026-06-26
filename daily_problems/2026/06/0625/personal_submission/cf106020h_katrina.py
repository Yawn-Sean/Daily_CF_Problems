import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    nxt = [-1] * n
    for i in range(n - 2, -1, -1):
        nxt[i] = nxt[i + 1] if a[i + 1] == 0 else (i + 1)
    
    pre, ans = -1, 0
    for i, x in enumerate(a):
        if x == 0:
            continue
        j = nxt[i]
        if j == -1:
            break
        y = a[j]
        if x > y:
            x, y = y, x
        if x == 1 and (y == 1 or y == 2):
            l = (i + 1) if pre == -1 else (i - pre)
            r = (n - j) if nxt[j] == -1 else (nxt[j] - j)
            ans += l * r - int(i + 1 == j)
        pre = i
    print(ans)

solve()
