import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 分成两类，第一个的a的数量等于第二个的b的数量
# 没有分类出来
# 需要凑出x2 + y2，可以通过枚举两种都会的人选几个
n = II()
c, a = I(), I()
both = c.count('1')
cnt = [[] for _ in range(3)] # 记录每一类的下标
for i in range(n):
    cnt[int(c[i]) + int(a[i])].append(i + 1)

for i in range(len(cnt[2]) + 1):
    j = both - i * 2
    if 0 <= j <= len(cnt[1]) and 0 <= n // 2 - i - j <= len(cnt[0]):
        ans = []
        ans.extend(cnt[0][n // 2 - i - j:])
        ans.extend(cnt[1][j:])
        ans.extend(cnt[2][i:])
        print(*ans)
        exit()
print(-1)