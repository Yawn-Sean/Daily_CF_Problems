import math

def soviet():
    r, l, th = map(int, input().split())
    w = 2 * r * math.sin(th / 180 * math.pi / 2)
    print(math.sqrt(l * l - w * w))


MT = int(input())
for _ in range(MT):
    soviet()
