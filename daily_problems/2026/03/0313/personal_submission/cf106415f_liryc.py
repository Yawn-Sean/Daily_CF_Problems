'''
20260313 Y1 1400
'''
# ref
def solve(x):
    if x & -x == x:
        return query(x, x) // 2
    v = 1 << x.bit_length()
    return query(v - x, x) - solve(v - x)
