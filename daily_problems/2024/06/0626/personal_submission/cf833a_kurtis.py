import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

n = II()
ans = []
for _ in range(n):
    # 找到一个数的三次方等于它，否则不合法
    a, b = MII()
    l, r = 0, 10 ** 6
    while l < r:
        m = l + r >> 1
        if m ** 3 >= a * b: r = m
        else: l = m + 1

    # 忘记a,b都得整除它这个条件了，很多反例的
    ans.append('Yes' if r ** 3 == a * b and a % r == 0 and b % r == 0 else 'No')
print(*ans, sep='\n')