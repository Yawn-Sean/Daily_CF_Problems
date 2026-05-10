outs = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    ans = 0

    def check(x1, x2):
        if x1 == x2: return 0
        if (x1 - x2) & 1: return 1
        return 2

    ans += check(x1, x2) + check(y1, y2)
    outs.append(ans)

print('\n'.join(map(str, outs)))
