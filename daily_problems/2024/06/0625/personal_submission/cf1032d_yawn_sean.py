# Submission Link: https://codeforces.com/contest/1032/submission/267242403
def main():
    def dis(x, y):
        return ((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2) ** 0.5

    def find_points(x, y):
        if a: yield (-(b * y + c) / a, y)
        if b: yield (x, -(a * x + c) / b)

    a, b, c = MII()
    x1, y1, x2, y2 = MII()

    ans = abs(x1 - x2) + abs(y1 - y2)
    for pt1 in find_points(x1, y1):
        for pt2 in find_points(x2, y2):
            ans = min(ans, dis((x1, y1), pt1) + dis(pt1, pt2) + dis(pt2, (x2, y2)))

    print(ans)