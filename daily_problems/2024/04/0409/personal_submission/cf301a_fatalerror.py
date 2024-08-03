import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    arr = lii()
    pos = [x for x in arr if x > 0]
    neg = [x for x in arr if x < 0]
    if len(neg) % 2 == 0 or len(pos) + len(neg) != 2*n-1 or n % 2 == 1:
        return sum(pos) - sum(neg)
    mxneg = max(neg)
    if not pos:
        return -sum(neg) + mxneg*2
    mnpos = min(pos)
    if mnpos + mxneg >= 0:
        return sum(pos) - sum(neg) + mxneg*2
    else:
        return sum(pos) - mnpos*2 - sum(neg)

print(solve())