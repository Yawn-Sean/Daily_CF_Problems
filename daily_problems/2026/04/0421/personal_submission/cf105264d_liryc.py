'''
https://codeforces.com/gym/105264/submission/371932200
greedy, cases
'''

def solve(n: int, a: list[int]) -> list[int]:
    if n == 1:
        return [0, 0]
    elif n == 2:
        if a[0] * 10 + a[1] <= a[1] * 10 + a[0]:
            return [0, a[0] * 10 + a[1]]
        else:
            return [1, a[1] * 10 + a[0]]
        
    x, y = a[0], 0
    c, s = 0, 0
    for u, v in pairwise(a):
        s += u * 10 + v
        if v > x:
            x, y = v, x
        elif v > y:
            y = v

    if a[0] == y and a[-1] == x:
        pass # c = 0
    elif a[0] == x and a[-1] == y:
        c = 1
        s += (y - x) * 9
    elif a[0] == y:
        c = 1
        s += (a[-1] - x) * 10
    elif a[-1] == x:
        c = 1
        s += a[0] - y
    else:
        c = 2
        s += (a[-1] - x) * 10 + a[0] - y

    return [c, s]
