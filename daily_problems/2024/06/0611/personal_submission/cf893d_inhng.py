import sys
input = lambda: sys.stdin.readline().strip()

n, d = map(int, input().split())
a = list(map(int, input().split()))
left = right = ans = 0
for ai in a:
    if ai:
        left += ai
        right = min(d, right + ai)
        if left > d:
            exit(print(-1))
    else:
        if right < 0:
            left, right = 0, d
            ans += 1
        else:
            left = max(left, 0)
print(ans)
