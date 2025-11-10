import sys
import math
input = lambda: sys.stdin.readline().rstrip()

def soviet():
    c = int(input())
    a = c
    b = c << int(math.log2(c) + 1)
    print(a, b)

T = int(input())
for _ in range(T):
    soviet()
