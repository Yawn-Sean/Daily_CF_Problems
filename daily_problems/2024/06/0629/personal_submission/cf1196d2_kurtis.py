import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 因为只有三种格式，所以直接枚举就好了
ans = []
mp = {'R': 0, 'G': 1, 'B': 2}
for _ in range(II()):
    n, k = MII()
    s = [mp[x] for x in I()]

    res = 10 ** 10
    for i in range(3): # 枚举每个起点
        cnt = 0
        for j in range(k):
            if s[j] != (i + j) % 3:
                cnt += 1
        res = min(res, cnt)

        for j in range(k, n): # 加一个，减一个
            if s[j] != (i + j) % 3:
                cnt += 1
            if s[j - k] != (i + j - k) % 3:
                cnt -= 1
            res = min(res, cnt)
    ans.append(res)
print(*ans, sep='\n')