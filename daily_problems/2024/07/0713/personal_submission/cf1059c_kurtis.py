import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 1到n，每次删除一个，找到字典序最大的结果
# 递归！！！
# 将所有数同时除以2，可以得到一个新的形式完全一致的子问题
n = II()
def f(n):
    if n <= 3:
        return [1] * (n - 1) + [n]
    return [1] * (n - n // 2) + [x * 2 for x in f(n // 2)]

print(*f(n))