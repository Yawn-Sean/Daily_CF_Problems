'''
https://codeforces.com/gym/105666/submission/371099420
'''
enc = lambda x, e: x * e << 3 | e - 2
dec = lambda x: (x >> 3, (x & 7) + 2)
def solve(n: int) -> int:
    a = [1]
    ia = [0] * 10
    hp = [enc(1, e) for e in range(2, 10)]

    def check(x, e):
        while x: 
            x, y = divmod(x, 10)
            if y == e:
                return True
        return False
                
    while hp:
        y, e = dec(hp[0])
        if y > n:
            break
        if y != a[-1] and check(y, e):
            a.append(y)
        ia[e] = i = ia[e] + 1
        heapreplace(hp, enc(a[i], e))

    return len(a)
