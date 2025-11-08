'''
https://codeforces.com/gym/106170/submission/347859639
'''
pmax = lambda x, y: y if y > x else x
def solve(n: int, m: int, a: list[int], b: list[list[int]]) -> int:
    MAX_R = 10 ** 13

    p = [0] * (n + 1)

    def check(k):
        nonlocal n, m, a, b, p
        for i in range(n + 1):
            p[i] = 0
        
        for _ in range(n):
            for i in range(m):
                l, r, x, y = b[i]
                l -= 1
                p[r] = pmax(p[r], p[l] + x)
                p[l] = pmax(p[l], p[r] - y)
            
            for i in range(n):
                p[i + 1] = pmax(p[i + 1], p[i] + pmax(1, a[i] - k))
                p[i] = pmax(p[i], p[i + 1] - a[i] - k)
    
        for i in range(n):
            if not pmax(1, a[i] - k) <= p[i + 1] - p[i] <= a[i] + k:
                return False
        
        for i in range(m):
            l, r, x, y = b[i]
            l -= 1
            if not x <= p[r] - p[l] <= y:
                return False        
        return True
    
    ans = bisect_left(range(MAX_R + 1), True, key=check)
    if ans >= MAX_R:
        ans = -1
    return ans
