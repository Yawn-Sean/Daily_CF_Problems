import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# Some characters should be removed earlier.

def check(s): # 找到最大的可以删除的字符
    k = len(s)
    res = -1
    for i in range(k):
        if (i and ord(s[i]) - ord(s[i - 1]) == 1) or (i + 1 < k and ord(s[i]) - ord(s[i + 1]) == 1) and (res == -1 or s[i] > s[res]):
            res = i
    return res

n = II()
s = I()

ans = 0
while True:
    idx = check(s)
    if idx == -1: break # 找不到了
    s = s[:idx] + s[idx + 1:]
    ans += 1
print(ans)