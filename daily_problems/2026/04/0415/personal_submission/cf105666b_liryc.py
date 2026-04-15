'''
https://codeforces.com/gym/105666/submission/371196262
'''
# priority queue
def solve(n: int, pa: list[int], qa: list[int]) -> bool:
    h0, h1, hq = [], [], []
    for i in range(n):
        p, pt = pa[i]
        if pt == 0:
            heappush(h0, p)
        else:
            heappush(h1, p)
    for j in sorted(range(n), key = lambda j: qa[j][1] << 30 | qa[j][0]):
        q, qt = qa[j]
        if qt == 0:
            p0 = 0
            while h0:
                p0 = h0[0]
                if p0 << 1 >= q:
                    break
                else:
                    heappop(h0)
                    heappush(hq, p0)
                    p0 = 0
            p1 = 0
            while h1:
                p1 = h1[0]
                if p1 >= q:
                    break
                else:
                    heappop(h1)
                    heappush(hq, p1 << 1)
                    p1 = 0
            if p0 > 0 and (p1 == 0 or p0 <= p1 << 1):
                heappop(h0)
            elif p1 > 0:
                heappop(h1)
            else:
                return False     
        else:
            if h0 or h1:
                while h0:
                    heappush(hq, heappop(h0))
                while h1:
                    heappush(hq, heappop(h1) << 1)
            p1 = heappop(hq)
            if p1 < q:
                return False
    return True
