from collections import Counter
def solve(xx):
    xxcc = sorted(Counter(xx).items())
    if len(xxcc) == 2:
        (x0,c0),(x2,c2) = xxcc
        if x2-x0 == 2:
            xxcc = (x0,c0),(x0+1,0),(x2,c2)
    if len(xxcc) < 3:
        return len(xx), xx
    (x0,c0),(x1,c1),(x2,c2) = xxcc
    assert (x0,x2) == (x1-1,x1+1)
    m,d = min((c0+c1%2+c2,c1//2),(abs(c0-c2)+c1,-min(c0,c2)))
    c0,c1,c2 = c0+d,c1-2*d,c2+d
    return m, [x0]*c0 + [x1]*c1 + [x2]*c2
n = int(input())
xx = list(map(int, input().split()))
assert len(xx) == n
m, yy = solve(xx)
print(m)
print(" ".join(map(str, yy)))
