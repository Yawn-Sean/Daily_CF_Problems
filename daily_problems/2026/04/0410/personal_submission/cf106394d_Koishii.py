outs = []
for _ in range(int(input())):
    n = int(input())
    a = [0] + list(map(int, input().split()))

    ans = 0
    pos = 1
    rest = 0
    mx = 0

    while pos < n:
        mx = max(mx, a[pos])
        if rest == 0:
            ans += 1
            rest += mx
        pos += 1
        rest -= 1

    outs.append(ans + n - 1)

print('\n'.join(map(str, outs)))
