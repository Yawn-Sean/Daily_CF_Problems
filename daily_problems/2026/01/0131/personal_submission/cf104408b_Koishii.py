import math

outs = []
def soviet():
    a = list(map(int, input().split()))
    x1, y1, x2, y2 = a
    if a.count(0) >= 3:
        outs.append(max(abs(x) for x in a))
    elif (x1 and x2) or (y1 and y2):
        outs.append(abs(x1 - x2) + abs(y1 - y2))
    else:
        x = min([abs(r) for r in [x1, y1, x2, y2] if r])
        y = max([abs(r) for r in [x1, y1, x2, y2] if r])
        outs.append(0.5 * math.pi * x + y - x)


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, [format(x, '.10f') for x in outs])))
