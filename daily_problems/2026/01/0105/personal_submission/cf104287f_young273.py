def gcd_(x, y):
    while x % y != 0:
        x, y = y, x % y
    return y
def solve():
    l = a * b // gcd_(a, b)
    diff = gcd_(l, c)
    if diff == c:
        print(0)
        return
    print(c - diff)
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    solve()