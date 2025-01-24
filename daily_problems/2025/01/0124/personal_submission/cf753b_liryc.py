'''
https://codeforces.com/problemset/submission/753/302772222
'''
# ref 先猜有哪几个数字，然后枚举全排列，最多猜10+24=34次

def solve():
    pa = []
    for i in range(10):
        x, y = query(str(i) * 4)
        if x == 4:
            return
        for _ in range(x + y):
            pa.append(i)
    for p in permutations(pa):
        x, y = query(''.join(map(str, p)))
        if x == 4:
            return