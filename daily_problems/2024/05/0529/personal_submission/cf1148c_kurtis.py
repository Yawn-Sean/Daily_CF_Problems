import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 把0和n - 1当作中转点，一定可以转移
# 感觉和基础课上的堆排序很像，记录两个下标
n = II()
p = LGMI() # 映射小一位
pos = [-1] * n # 代表这个数的真正位置

for i in range(n):
    pos[p[i]] = i

def swap(u, v): # u, v的含义是下标
    pos[p[u]], pos[p[v]] = pos[p[v]], pos[p[u]]
    p[u], p[v] = p[v], p[u]
    ans.append(f'{u + 1} {v + 1}')

ans = []
# 分两边处理，毕竟中转站选的不一样
# 这个交换方式太妙了
for i in range(1, n // 2):
    if pos[i] != i:
        if pos[i] < n // 2:
            swap(pos[i], n - 1)
            swap(i, n - 1)
        else:
            swap(pos[i], 0)
            swap(0, n - 1)
            swap(i, n - 1)

for i in range(n // 2, n - 1):
    if pos[i] != i:
        if pos[i] >= n // 2:
            swap(pos[i], 0)
            swap(i, 0)
        else:
            swap(pos[i], n - 1)
            swap(n - 1, 0)
            swap(i, 0)

if p[0] != 0:
    swap(0, n - 1)
print(len(ans))
print('\n'.join(ans))