import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 曼哈顿距离不小于n-1，上三角才能问
# 一定可以走到对角线
# 只要返回True，那就一定可以走到。这样才可能直接动
# 控制查询的方向，使它们走到同一个位置，太妙了！

def query(r1, c1, r2, c2):
    print(*['?', r1, c1, r2, c2], flush=True)
    return I() == 'YES'

n = II()

# 先找前一段，默认往右走
x, y = 1, 1
tmp1 = []
for _ in range(n - 1):
    if query(x, y + 1, n, n):
        y += 1
        tmp1.append('R')
    else:
        x += 1
        tmp1.append('D')

# 找后半段，默认向上走
x, y = n, n
tmp2 = []
for _ in range(n - 1):
    if query(1, 1, x - 1, y):
        x -= 1
        tmp2.append('D')
    else:
        y -= 1
        tmp2.append('R')

print('! ' + ''.join(tmp1) + ''.join(reversed(tmp2)), flush=True)