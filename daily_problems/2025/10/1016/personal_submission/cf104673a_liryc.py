'''
https://codeforces.com/gym/104673/submission/343952957
'''
# 杨辉三角
lookup = {}
def init():
    global lookup
    LIMIT = 1000000000
    lookup[1] = 1
    a = [0] * 45000
    a[0] = a[1] = 1
    for r in range(3, 45000):
        p = a[0]
        for i in range(1, r - 1):
            if a[i] == 0:
                break
            a[i], p = p + a[i], a[i]
            if a[i] > LIMIT:
                a[i] = 0
                break
            if not a[i] in lookup:
                lookup[a[i]] = r
        else:
            a[r - 1] = 1

def solve(n: int) -> int:
    global lookup
    if n in lookup:
        return lookup[n]
    else:
        return n + 1
