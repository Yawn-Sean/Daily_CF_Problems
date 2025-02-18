import sys
input = lambda: sys.stdin.readline().strip()
from collections import defaultdict

def solve():
    g = defaultdict(list)
    for qi in range(n):
        s = input()
        tmp = set() # 避免一直用set，可先統計好
        for i in range(len(s)): # 避免連續切片，用加的
            cur = ''
            for j in range(i, len(s)):
                cur += s[j]
                tmp.add(cur)
        for t in tmp:
            if len(g[t]) < 2: # 大量減少占用，只需2就不合(沒必要統計全部)
                g[t].append(qi)

    ans = [None] * n
    for x in g:
        if len(g[x]) > 1:
            continue
        i = g[x][0]
        if ans[i] is None or len(ans[i]) > len(x):
            ans[i] = x
    print(*ans, sep='\n')

               
for _ in range(1):
    n = int(input())
    solve()