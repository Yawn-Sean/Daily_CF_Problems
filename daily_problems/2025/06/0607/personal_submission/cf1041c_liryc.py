'''
https://codeforces.com/problemset/submission/1041/323192085
'''
# queue
def solve(n: int, m: int, d: int, a: list[int]) -> list[int]:
    d += 1
    si = list(sorted(range(n), key = lambda i: a[i]))
    ans = [0] * n
    dq = deque()
    for i in si:
        t = a[i]
        if dq and t >= dq[0][0] + d:
            t0, d0 = dq.popleft()
            ans[i] = d0 + 1
            dq.append((t, d0))
        else:
            ans[i] = len(dq) + 1
            dq.append((t, len(dq)))
    return ans
