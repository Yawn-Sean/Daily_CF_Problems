outs = []
eps = 1e-10
for _ in range(int(input())):
    p, r, y = map(float, input().split())
    
    def f(e):
        n = (y + r + p) / 2 - e
        s = (y + r + p) / 2 - e - r
        w = e - p
        return max(abs(n), abs(s), abs(w), abs(e))

    left, right = -1.0, 1.0
    while right - left > eps:
        mid = (left + right) / 2
        if f(mid - eps) < f(mid + eps):
            right = mid
        else:
            left = mid

    e = left
    outs.append(f'{(y + r + p) / 2 - e} {e} {(y + r + p) / 2 - e - r} {e - p}')

print('\n'.join(outs))
