import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 找到公共部分取0，其余非公共部分取平均
# 这个非公共部分就是叶子节点，哎没有注意这是一颗树呀，所以
# 判断叶子节点就是度为1

n, s = MII()
d = [0] * n
for _ in range(n - 1):
    a, b = GMI()
    d[a] += 1
    d[b] += 1

print(2 * s / d.count(1))