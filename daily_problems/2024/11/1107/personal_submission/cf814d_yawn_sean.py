# Submission link: https://codeforces.com/contest/814/submission/290312555
def main():
    n = II()
    circles = [LII() for _ in range(n)]
    circles.sort(key=lambda x: -x[2])

    def isin(x, y):
        return (circles[x][0] - circles[y][0]) ** 2 + (circles[x][1] - circles[y][1]) ** 2 <= (circles[x][2] - circles[y][2]) ** 2

    times = [0] * n
    for i in range(n):
        for j in range(i):
            if isin(i, j):
                times[i] += 1

    ans = 0
    for i in range(n):
        if fmax(0, times[i] - 1) % 2: ans -= circles[i][2] ** 2
        else: ans += circles[i][2] ** 2

    print(math.pi * ans)