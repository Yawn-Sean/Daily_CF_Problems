import sys
input = lambda: sys.stdin.readline().rstrip()

def sol():
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a

    if a == b:
        return (a & 1) == 0

    if (a % (b - a)):
        return 0

    for i in range(2, 5):
        if b % i == 0:
            x = a - b // i
            if x > 0 and b % x == 0:
                return 1

    return 0

def soviet():
    if (sol()):
        print("SI")
    else:
        print("NO")


MT = int(input())
for _ in range(MT):
    soviet()
