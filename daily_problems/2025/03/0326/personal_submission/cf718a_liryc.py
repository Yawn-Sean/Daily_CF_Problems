'''
https://codeforces.com/problemset/submission/718/312584190
'''
# big number
def solve(n: int, t: int, s: str) -> str:
    p0 = 0
    while p0 < len(s) and s[p0] != '.':
        p0 += 1
    if p0 == len(s):
        return s
    i = p0 + 1
    while i < len(s) and s[i] <= '4':
        i += 1
    if i == len(s):
        return s
    i -= 1
    t -= 1
    while t > 0 and i > p0 and s[i] == '4':
        i -= 1
        t -= 1

    def plus1(sn):
        a = [int(c) for c in sn]
        a[-1] += 1
        for i in range(len(a) - 1, 0, -1):
            if a[i] == 10:
                a[i] = 0
                a[i - 1] += 1
            else:
                break
        return ''.join(map(str, a))
    
    if i == p0:
        return plus1(s[:p0]) 
    else:
        return s[:i] + str(int(s[i]) + 1)
