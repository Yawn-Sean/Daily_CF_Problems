"""
要求 n 个字符串，它们的 n^2 种连接方式算出来的能量不一样
随便手写了三个就对了
"""
import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
ss = ["XOXXXOXOXX", "XOOXOOXOXX", "OOXOXXXXXO"]
st = set()
res = {}
for i in range(n):
    for j in range(n):
        s = ss[i] + ss[j]
        unique_substr = set()
        for l in range(len(s)):
            for r in range(l, len(s)):
                unique_substr.add(s[l:r + 1])
        res[len(unique_substr)] = (i + 1, j + 1)

for i in range(n):
    print(ss[i])
sys.stdout.flush()

q = int(input())
while q > 0:
    q -= 1
    magic = int(input())
    if magic in res:
        ans = res[magic]
        print(*ans)
        sys.stdout.flush()
    else:
        print(-1)
        sys.stdout.flush()
