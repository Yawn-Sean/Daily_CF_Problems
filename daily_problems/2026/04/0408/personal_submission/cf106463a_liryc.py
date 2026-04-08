'''
https://codeforces.com/gym/106463/submission/370235694
'''
def solve(n: int, k: int, x: int, y: int, a: list[int]) -> list[int]:
    pre, suf = [0] * k, [0] * k
    di = [-1] * n 
    od = [-1] * k 
    for i in range(k):
        pre[i] = (pre[i - 1] + a[i]) % n
        suf[~i] = (suf[~i + 1] + a[~i]) % n
    D = (x - y) % n
    od[-1] = y
    di[pre[-1]] = k - 1
    for i in range(k - 2, -1, -1):
        d = (pre[i] + D) % n
        if di[d] != -1:
            j = di[d]
            od[i] = od[j]
        else:
            od[i] = (suf[i + 1] + y) % n
        di[pre[i]] = i 
    def qry(p: int) -> int:
        nonlocal suf, di, od
        d = (x - p) % n
        if di[d] != -1:
            j = di[d]
            return od[j]
        else:
            return (p + suf[0]) % n
    return [qry(p) for p in range(n) if p != x]
