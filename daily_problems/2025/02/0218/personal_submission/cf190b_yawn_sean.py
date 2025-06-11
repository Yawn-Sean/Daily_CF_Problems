# Submission link: https://codeforces.com/contest/190/submission/306599310
def main():
    x1, y1, r1 = MII()
    x2, y2, r2 = MII()

    if (r2 - r1) * (r2 - r1) > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1):
        print((abs(r2 - r1) - math.hypot(x2 - x1, y2 - y1)) / 2)
    elif (r1 + r2) * (r1 + r2) < (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1):
        print((math.hypot(x2 - x1, y2 - y1) - r1 - r2) / 2)
    else:
        print(0)