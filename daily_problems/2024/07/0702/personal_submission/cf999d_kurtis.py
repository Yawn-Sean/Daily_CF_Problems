import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 每种余数的个数是n / m
# 只有加法，所以每个没有满足的一定是从它的左边转移过来
# 利用多余的给它后面的

n, m = MII()
a = LMII()
pos = [[] for _ in range(m)]
for i, x in enumerate(a):
    pos[x % m].append(i)

ans = 0
target = n // m
stk = [] # 想着继续用链表维护，没想到直接存下来就行
for i in range(2 * m): # 最多两轮结束
    x = i % m
    while stk and len(pos[x]) < target:
        j = stk.pop() # 一定是离得最近的数
        v = (x - a[j]) % m # python取模自带变成正数
        a[j] += v
        ans += v
        pos[x].append(j)
    while len(pos[x]) > target:
        stk.append(pos[x].pop())
        
print(ans)
print(*a)