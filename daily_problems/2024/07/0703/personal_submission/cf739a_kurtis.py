import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# hint: Find the answer first, and then construct the corresponding array.
# 答案就是所有查询最短的长度

n, m = MII()
ans = 10 ** 10
for _ in range(m):
    l, r = MII()
    ans = min(ans, r - l + 1)

print(ans)
print(*[i % ans for i in range(n)]) # 直接这样生成循环，妙