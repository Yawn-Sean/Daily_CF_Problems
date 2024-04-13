from functools import reduce
import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

def f():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    connect = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        connect[u-1].append(v-1)
        connect[v-1].append(u-1)
    all_xor = reduce(lambda x, y: x ^ y, nums)
    if not all_xor:
        return 'YES'
    if k == 2:
        return 'NO'
    
    #建树
    stack = [0]
    children = [[] for _ in range(n)]
    parent = [-1] * n
    arrive = [1] + [0] * (n-1)
    ind = [0] * n
    while stack:
        now = stack.pop()
        for i in connect[now]:
            if not arrive[i]:
                children[now].append(i)
                parent[i] = now
                stack.append(i)
                arrive[i] = 1
                ind[now] += 1
    
    stack = []
    for i in range(n):
        if not ind[i]:
            stack.append(i)
    
    ans = 0
    xor_subtree = [0] * n
    while stack:
        now = stack.pop()
        for i in children[now]:
            xor_subtree[now] ^= xor_subtree[i]
        ind[parent[now]] -= 1
        if not ind[parent[now]]:
            stack.append(parent[now])
        xor_subtree[now] ^= nums[now]
        if xor_subtree[now] == all_xor:
            ans += 1
            xor_subtree[now] = 0
        if ans > 1:
            return 'YES'
    return 'NO'

ans = []
for _ in range(int(input())):
    ans.append(f())
print('\n'.join(ans))
