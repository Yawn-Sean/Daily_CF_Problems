'''
https://codeforces.com/gym/106007/submission/370383186
'''
# bit operations, cases
def solve(n: int, m: int, a: list[int], q: int, qa: list[int]) -> list[int]:
    t = reduce(or_, a)
    j, c = -1, 0
    b = 0 # bits that x must be 1
    for i in range(n):
        if a[i] != t:
            b |= a[i] ^ t
            if j < 0:
                j = i
            elif i >= j + m:
                j, c = i, c + 1
    if j >= 0:
        c += 1

    def qry(x: int) -> int:
        if c == 0:
            return 0
        elif x & b != b:
            return -1
        elif x & t == x:
            return c
        else:
            return (n + m - 1) // m
        
    return [qry(x) for x in qa]
