'''
https://codeforces.com/contest/644/submission/280701686
644B
2024/9/11 Y1
1700
Queue, 个人觉得这题难度不到1400
'''

from collections import deque
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, b = map(int, input().split())
    ta, da = [], []
    for _ in range(n):
        t, d = map(int, input().split())
        ta.append(t)
        da.append(d)
    return n, b, ta, da

def solve(n, b, ta, da):
    b += 1
    ans = [0] * n
    dq = deque()
    i = 0
    for t, d in zip(ta, da):
        while dq and dq[0] <= t:
            dq.popleft()
        if len(dq) >= b:
            ans[i] = -1
        else:
            if len(dq) == 0:
                ans[i] = t + d
            else:
                ans[i] = dq[-1] + d
            dq.append(ans[i])
        i += 1
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(*ans)
