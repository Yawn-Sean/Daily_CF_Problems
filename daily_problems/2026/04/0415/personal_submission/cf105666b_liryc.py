'''
https://codeforces.com/gym/105666/submission/371471734
'''
def solve(n: int, pa: list[int], qa: list[int]) -> bool:
    dep = deque(sorted(p if pt else ~p for p, pt in pa))
    hq = []

    for q in sorted(q if qt else ~q for q, qt in qa):
        qt = 1
        if q < 0:
            q, qt = ~q, 0
        if qt == 0:
            while dep and dep[0] < 0 and ~dep[0] << 1 >= q:
                heappush(hq, ~dep.popleft())
            while dep and dep[-1] > 0 and dep[-1] >= q:
                heappush(hq, dep.pop() << 1)
            if hq:
                heappop(hq)
            else:
                return False
        else: # qt == 1
            while dep:
                p = dep.pop()
                heappush(hq, p << 1 if p > 0 else ~p)
            if hq and hq[0] >= q:
                heappop(hq)
            else:
                return False
    return True
