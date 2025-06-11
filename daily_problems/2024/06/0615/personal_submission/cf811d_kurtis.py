import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

def op(c):
    print(c, flush=True)
    return GMI() # 获取反馈

n, m = MII()
g = [I() for _ in range(n)]
vis = [[0] * m for _ in range(n)]
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

# 找到路径并存储路径
vis[0][0] = 1
prev = [[None] * m for _ in range(n)]
endx, endy = -1, -1

stk = [(0, 0)]
while stk:
    x, y = stk.pop()
    if g[x][y] == 'F':
        endx, endy = x, y
        break

    for i in range(4):
        a, b = x + dx[i], y + dy[i]
        if 0 <= a < n and 0 <= b < m and g[a][b] != '*' and vis[a][b] == 0:
            vis[a][b] = 1
            prev[a][b] = (x, y)
            stk.append((a, b))

steps = [(endx, endy)]
while True:
    x, y = steps[-1]
    if prev[x][y] is None: break
    steps.append((prev[x][y]))

steps.reverse()

# 根据路径找到可以判断的位置，并输出路径
f_lr, f_ud = False, False
lr, ud = 'LR', 'UD'
for i in range(len(steps) - 1):
    dx, dy = steps[i + 1][0] - steps[i][0], steps[i + 1][1] - steps[i][1]
    if dx == 0: 
        if not f_lr: # 在第一次要向右走时
            f_lr = True
            nx, ny = op('L') # 一定可以测试左
            if ny == steps[i + 1][1]: lr = 'RL'
            else: op('R') # 没有交换lr，向右走
        else:
            if dy > 0: op(lr[1])
            else: op(lr[0])
    else:
        if not f_ud:
            f_ud = True
            nx, ny = op('U')
            if nx == steps[i + 1][0]: ud = 'DU'
            else: op('D')
        else:
            if dx > 0: op(ud[1])
            else: op(ud[0])