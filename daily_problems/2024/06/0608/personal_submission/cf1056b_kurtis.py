import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 加法对于取模可以分开算
# 平方对于取模也是可以分开的

n, m = MII()
ans = 0
for i in range(1, m + 1):
    ci = (n - i) // m + 1  # 在1~n中找
    for j in range(1, m + 1):
        cj = (n - j) // m + 1 # 在1~n中找
        if (i * i + j * j) % m == 0:
            ans += ci * cj
print(ans)