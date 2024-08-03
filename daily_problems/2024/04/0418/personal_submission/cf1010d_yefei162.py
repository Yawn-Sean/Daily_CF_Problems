# -*- coding: utf-8 -*-
import sys
from operator import xor, and_, not_, or_

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
tree = [[] for _ in range(n + 1)]
fa = [-1 for _ in range(n + 1)]
ops = ['' for _ in range(n + 1)]
nums = [-1 for _ in range(n + 1)]

# func map
fm = {
    'AND': and_,
    'OR': or_,
    'XOR': xor,
    'NOT': not_
}

for i in range(1, n + 1):
    s = input().split()
    if s[0] in ['AND', 'XOR', 'OR']:
        c1, c2 = int(s[1]), int(s[2])
        tree[i] = [c1, c2]
        fa[c1] = i
        fa[c2] = i
        ops[i] = s[0]
    elif s[0] == 'NOT':
        c1 = int(s[1])
        tree[i] = [c1]
        fa[c1] = i
        ops[i] = s[0]
    else:
        c1 = int(s[1])
        nums[i] = c1

stk = [1]
dfs = []
while stk:
    x = stk.pop()
    dfs.append(x)
    for y in tree[x]:
        stk.append(y)
# print(dfs[::-1])
for x in dfs[::-1]:
    if not ops[x]:
        continue
    nums[x] = fm[ops[x]](*[nums[y] for y in tree[x]])
    nums[x] = int(nums[x])

# print(nums)
# print(nums[1])

state = [0] * (n+1)
stk = [1]
while stk:
    x = stk.pop()
    state[x] = 1
    if not ops[x]:
        continue
    if len(tree[x]) == 1:
        stk.append(tree[x][0])
    else:
        c1, c2 = tree[x]
        x1 = nums[c1] ^ 1
        x2 = nums[c2] ^ 1
        if fm[ops[x]](x1, nums[c2]) != nums[x]:
            stk.append(c1)
        if fm[ops[x]](nums[c1], x2) != nums[x]:
            stk.append(c2)

rets = []
for i in range(1, n+1):
    if not ops[i]:
        if state[i]:
            rets.append(nums[1] ^ 1)
        else:
            rets.append(nums[1])
print(''.join(str(x) for x in rets))
