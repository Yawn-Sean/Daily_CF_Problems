import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s1 = input().lstrip('0')
    s2 = input().lstrip('0')
    n = max(len(s1), len(s2))
    s1 = list(map(int, s1.zfill(n)))
    s2 = list(map(int, s2.zfill(n)))
    for i, (x, y) in enumerate(zip(s1, s2)):
        if x == y:
            continue
        if abs(x - y) > 1 or i+2 >= n:
            return '>' if x > y else '<'
        if x > y:
            s1[i+1] += x-y
            s1[i+2] += x-y
        else:
            s2[i+1] += y-x
            s2[i+2] += y-x
    return '='

print(solve())