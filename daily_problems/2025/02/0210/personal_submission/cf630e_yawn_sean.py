# Submission link: https://codeforces.com/contest/630/submission/305383448
def main():
    x1, y1, x2, y2 = MII()
    x = x2 - x1 + 1
    y = y2 - y1 + 1

    print(((x + 1) // 2) * ((y + 1) // 2) + ((x - 1) // 2) * ((y - 1) // 2))