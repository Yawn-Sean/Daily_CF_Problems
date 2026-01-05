import math

outs = []
def soviet():
    a, b, c = map(int, input().split())
    d = math.lcm(a, b)
    outs.append(c - math.gcd(c, d))


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, outs)))
