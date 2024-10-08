from math import gcd
from collections import deque
def main():
    n = int(input())
    a = list(map(int, input().split()))
    pre = [(i - 1) % n for i in range(n)]
    suf = [(i + 1) % n for i in range(n)]
    d = [0] * n
    dq = deque(list(range(n)))
    res = []
    while len(dq):
        i = dq.popleft()
        if d[i] == 0:
            j = suf[i]
            if gcd(a[i], a[j]) == 1:
                d[j] = 1
                res.append(j + 1)
                pre[suf[j]] = pre[j]
                suf[pre[j]] = suf[j]
                dq.append(i)
    
    print(len(res),*res)
            

t = int(input())
for _ in range(t):
    main()