# Submission link: https://codeforces.com/contest/644/submission/280669072
def main():
    n, b = MII()

    ans = [-1] * n
    dq = deque()

    for i in range(n):
        t, d = MII()
        
        while dq and dq[0] <= t:
            dq.popleft()
        
        if len(dq) <= b:
            if len(dq) == 0:
                ans[i] = t + d
            else:
                ans[i] = dq[-1] + d
            dq.append(ans[i])

    print(' '.join(map(str, ans)))