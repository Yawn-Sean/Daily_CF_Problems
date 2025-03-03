# Submission link: https://codeforces.com/contest/374/submission/307870063
def main():
    n, m, i, j, a, b = MII()

    inf = 10 ** 9
    def f(dx, dy):
        if dx % a or dy % b:
            return inf
        dx //= a
        dy //= b
        if (dx + dy) % 2: return inf
        return fmax(dx, dy)

    if (i == 1 or i == n) and (j == 1 or j == m):
        print(0)
    elif n <= a or m <= b:
        print('Poor Inna and pony!')
    else:
        ans = inf
        for x in [1, n]:
            for y in [1, m]:
                ans = fmin(ans, f(abs(x - i), abs(y - j)))
        print(ans if ans < inf else 'Poor Inna and pony!')