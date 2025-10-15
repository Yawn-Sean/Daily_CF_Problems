'''
https://codeforces.com/problemset/submission/689/319003566
'''
# bfs (OTK)
def solve(n: int, a: list[int]) -> list[int]:
    ans = [-1] * n
    ans[0] = 0
    for i in range(n):
        a[i] -= 1
    dq = deque()
    dq.append(0)
    while dq:
        i = dq.popleft()
        if i and ans[i - 1] < 0:
            ans[i - 1] = ans[i] + 1
            dq.append(i - 1)
        if i < n - 1 and ans[i + 1] < 0:
            ans[i + 1] = ans[i] + 1
            dq.append(i + 1)
        if ans[a[i]] < 0:
            ans[a[i]] = ans[i] + 1
            dq.append(a[i])
    return ans
