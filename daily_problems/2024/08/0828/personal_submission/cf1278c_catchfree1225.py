import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    pre = [0] * (n * 2 + 1)
    for i, x in enumerate(a):
        pre[i + 1] = pre[i] + x
    
    def eatLeft(k):
        return pre[n] - pre[n - k]
    
    def eatRight(k):
        return pre[n + k] - pre[n]
    
    m = {}
    for li in range(n + 1):
        left = eatLeft(li)
        if left not in m:
            m[left] = li
        m[left] = min(m[left], li)

    tot = sum(a)
    ans = n * 2
    for ri in range(n + 1):
        right = eatRight(ri)
        left = tot - right
        if left in m:
            ans = min(ans, m[left] + ri)
    print(ans)
    
               
for _ in range(int(input())):
    n = int(input())
    a = [1 if x == 1 else -1 for x in MII()]
    solve()