outs = []
def soviet():
    sx, sy, tx, ty, k = map(int, input().split())
    x = abs(sx - tx)
    y = abs(sy - ty)
    if x < y:
        x, y = y, x
    n1 = (x - 1) // k
    if n1 <= y:
        outs.append(x + y)
    else:
        outs.append(x + n1 + ((n1 + y) & 1))


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, outs)))
