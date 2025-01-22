# Submission link: https://codeforces.com/contest/712/submission/288012901
def main():
    x, y = MII()

    a, b = y, y
    cnt = 0

    while a < x:
        a, b = a + b - 1, a
        cnt += 1

    print(cnt + 2)