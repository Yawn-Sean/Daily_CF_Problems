'''
20251220 Y1
'''
def solve(n: int, a: list[int]) -> int: 
    l, r = 0, 0
    ans = 0
    b = [0] * 30
    c = [0] * 30
    while l < n:
        while r + 1 < n:
            v = (a[r] ^ a[r + 1]).bit_length() - 1
            if v >= 0:
                if a[r] >> v & 1:
                    if b[v]: break
                    c[v] += 1
                else:
                    if c[v]: break
                    b[v] += 1
            r += 1
        ans += r - l + 1
        if l + 1 < n:
            v = (a[l] ^ a[l + 1]).bit_length() - 1
            if v >= 0:
                if a[l] >> v & 1: c[v] -= 1
                else: b[v] -= 1
        l += 1
    return ans