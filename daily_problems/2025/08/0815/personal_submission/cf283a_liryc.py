'''
https://codeforces.com/problemset/submission/283/334014606
'''
# 数组，差分，前缀和
a = [0]
da = [0]
d = 0
sm = 0
def solve(operations: list[int]) -> float:
    global a, da, d, sm
    if operations[0] == 1:
        _, m, x = operations
        sm += x * m
        if m == len(a):
            d += x
        else:
            da[m] += x
    elif operations[0] == 2:
        k = operations[1]
        sm += k
        a.append(k)
        da.append(d)
        d = 0
    else: # operations[0] == 3:
        sm -= a[-1] + d
        d += da[-1]
        da.pop()
        a.pop()
    return sm / len(a)
