'''
https://codeforces.com/gym/106443/submission/369098175
'''
def solve(n: int, m: int, a: list[int]) -> int:
    if m == 2:
        return min(a.count(0), a.count(1))
    a.sort(reverse=True)
    if a[0] == a[-1]: 
        return 0 
    lq, rq = deque(), deque()
    lc, rc, d = 0, 0, 0
    ans = [0] * m
    for x in a:
        if x == 0:
            lq.append(x)
            lc += 1
        elif x < m - x:
            rq.appendleft(x)
            rc += 1
            d += x
        else:
            lq.appendleft(x)
            lc += 1
            d += m - x
    ans[0] = d
    for i in range(1, m):
        d += lc - rc
        while rq and rq[0] == i:
            lq.append(rq.popleft())
            lc, rc = lc + 1, rc - 1
        while lq and (i - lq[0]) % m > (lq[0] - i) % m:
            lc, rc = lc - 1, rc + 1
            d += (lq[0] - i) % m - (i - lq[0]) % m
            rq.append(lq.popleft())
        ans[i] = d
    return min(ans)
