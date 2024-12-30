def II():
    return int(input())
def LM():
    return list(map(int, input().split()))
def MI():
    return map(int, input().split())
def LI():
    return list(input())
def I():
    return input()

import math
n = II()
a = []
for _ in range(n):
    x, y = MI()
    if x != 0 or y != 0:
        if y > 0:
            a.append(math.acos(x / (x ** 2 + y ** 2) ** 0.5) / math.pi * 180)
        elif y == 0:
            if x > 0:
                a.append(0)
            else:
                a.append(180)
        else:
            y *= -1
            a.append(360 - math.acos(x / (x ** 2 + y ** 2) ** 0.5) / math.pi * 180)
a.sort()
ans = 360
for i in range(len(a)):
    if i == 0:
        ans = min(ans, a[-1] - a[0])
    else:
        ans = min(ans, 360 - (a[i] - a[i - 1]))
print(ans)
        
