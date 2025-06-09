# Submission link: https://codeforces.com/contest/593/submission/317243724
def main():
    n = II()

    xs = []
    ys = []

    for _ in range(n):
        x, y, r = MII()
        xs.append(x)
        ys.append(y)

    def solve(lst):
        print('(' * (n - 1), end='')
        for i in range(n):
            if i: print('+', end='')
            print(f'({lst[i] // 2}*((1-abs((t-{i})))+abs((1-abs((t-{i}))))))', end='')
            if i: print(')', end='')
        print()

    solve(xs)
    solve(ys)
