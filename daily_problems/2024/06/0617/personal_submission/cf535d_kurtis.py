import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 难受，字符串哈希被卡了

def z_algorithm(s):
    if isinstance(s, str):
        s = [ord(c) for c in s]

    n = len(s)
    if n == 0:
        return []

    z = [0] * n
    j = 0
    for i in range(1, n):
        z[i] = 0 if j + z[j] <= i else min(j + z[j] - i, z[i - j])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if j + z[j] < i + z[i]:
            j = i
    z[0] = n

    return z

n, m = MII()
s = I()
pos = LGMI()

k = len(s)
z = z_algorithm(s)

for i in range(m - 1):
    if pos[i + 1] - pos[i] >= k: continue # 举例足够大
    j = pos[i + 1] - pos[i]
    if z[j] + j != k: 
        print(0)
        break
else:
    # 差分统计空格
    b = [0] * (n + 1)
    for p in pos:
        b[p] += 1
        b[p + k] -= 1

    ans = 1
    mod = 10 ** 9 + 7

    for i in range(n):
        b[i + 1] += b[i]
        if b[i] == 0:
            ans *= 26
            ans %= mod

    print(ans)