import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 按照最高位的1分组，但是别人要能把它&掉
n = II()
a = list(set(LMII()))
g = [[] for _ in range(30)]
for x in a:
    for i in range(29, -1, -1):
        if (x >> i) & 1:
            g[i].append(x)

for i in range(29, -1, -1): # 枚举每个组
    if g[i]:
        # 把它全&之后右边要为0
        msk = -1
        for x in g[i]:
            msk &= x
        if not msk:
            print(len(g[i]))
            print(*g[i])
            break

# 10
# 109070199 215498062 361633800 406156967 452258663 530571268 670482660 704334662 841023955 967424642