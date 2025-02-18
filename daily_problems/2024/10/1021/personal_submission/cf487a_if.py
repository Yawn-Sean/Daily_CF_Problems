import math
a1, a3, a2 = map(int, input().split())
b1, b3, b2 = map(int, input().split())
c1, c3, c2 = map(int, input().split())
ans = 1e15
for f in range(250):
    for g in range(250):
        if a3 + g <= b2:
            continue
        elif a2 + f >= b3:
            ans = min(ans, f * c2 + g * c3)

        else:
            t = math.ceil(b1 / (a3 + g - b2))
            x = t * (b3 - a2 - f) + 1
            x = max(0, x - a1)
            ans = min(ans, f * c2 + x * c1 + g * c3)
print(ans)
