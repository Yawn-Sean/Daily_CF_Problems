mii = lambda: map(int, input().split())
dist = lambda x1, y1, x2, y2: ((x1-x2)**2 + (y1-y2)**2) ** 0.5

def solve():
    a, b, c = mii()
    x1, y1, x2, y2 = mii()
    ans = abs(x1-x2) + abs(y1-y2)
    if a == 0 or b == 0:
        return ans
    xx1 = (-b*y1 - c) / a
    yy1 = (-a*x1 - c) / b
    xx2 = (-b*y2 - c) / a
    yy2 = (-a*x2 - c) / b
    ans = min(ans, abs(x1-xx1) + dist(xx1, y1, xx2, y2) + abs(x2-xx2))
    ans = min(ans, abs(x1-xx1) + dist(xx1, y1, x2, yy2) + abs(y2-yy2))
    ans = min(ans, abs(y1-yy1) + dist(x1, yy1, xx2, y2) + abs(x2-xx2))
    ans = min(ans, abs(y1-yy1) + dist(x1, yy1, x2, yy2) + abs(y2-yy2))
    return ans

print(solve())