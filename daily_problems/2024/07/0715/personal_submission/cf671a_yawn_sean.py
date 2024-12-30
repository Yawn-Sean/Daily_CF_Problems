# Submission Link: https://codeforces.com/contest/671/submission/270548456
def main():
    ax, ay, bx, by, tx, ty = MII()

    def f1(x, y):
        return ((x - ax) * (x - ax) + (y - ay) * (y - ay)) ** 0.5

    def f2(x, y):
        return ((x - bx) * (x - bx) + (y - by) * (y - by)) ** 0.5

    def f(x, y):
        return ((x - tx) * (x - tx) + (y - ty) * (y - ty)) ** 0.5

    tot = 0
    dp1 = dp2 = dp3 = -4e9
    n = II()

    for _ in range(n):
        x, y = MII()
        tot += 2 * f(x, y)
        dp1, dp2, dp3 = max(dp1, f(x, y) - f1(x, y)), max(dp2, f(x, y) - f2(x, y)),\
                        max(dp3, dp1 + f(x, y) - f2(x, y), dp2 + f(x, y) - f1(x, y))

    print(tot - max(dp1, dp2, dp3))