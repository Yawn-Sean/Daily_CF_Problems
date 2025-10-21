'''
https://codeforces.com/gym/104848/submission/344976258
'''
lut = {
    12: 48,
    15: 5055,
    18: 288,
    21: 7077,
    24: 8088,
    27: 3699,
    36: 48888,
    45: 5055555555,
    54: 222888888,
    63: 111888,
    72: 8088888888,
    81: 9099999999,
}

def solve(n: int) -> int:
    global lut
    s = str(n)
    if all(c == s[0] for c in s):
        return n
    elif n in lut:
        return lut[n]
    else:
        return -1
