import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n, L = MI()
costs = LI()

add = []

i = 0
x = L
while x:
    if x % 2:
        add.append(1 << i)
        x = x // 2
        i += 1
    else:
        x = x // 2
        i += 1
# print(add)

x = L
acc = 0
ans = 1 << 64
while x:
    y = add.pop()
    mi = 1 << 64
    for i, cost in enumerate(costs):
        c = 1 << i
        if c >= x:
            ans = min(ans, acc + cost)
        else:
            mi = min(mi, (y + c - 1) // c * cost)
    acc += mi
    x -= y
ans = min(ans, acc)
print(ans)
