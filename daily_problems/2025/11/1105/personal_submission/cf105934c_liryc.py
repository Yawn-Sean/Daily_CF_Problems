'''
GYM105934-C
'''
def solve(n: int, a: list[int]) -> int: 
    ans = 10 ** 18
    
    r = 0
    c = a[0]
    
    for i in range(1, n):
        x = a[i]
        if i & 1:
            c = max(c + 1, x)
            r += c - x
        else:
            c = min(c - 1, x)
            r += x - c
    
    ans = min(ans, r)
    
    r = 0
    c = a[0]
    
    for i in range(1, n):
        if not (i & 1):
            c = max(c + 1, x)
            r += c - x
        else:
            c = min(c - 1, x)
            r += x - c
    
    ans = min(ans, r)
    return ans