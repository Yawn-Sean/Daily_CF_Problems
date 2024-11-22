# Submission link: https://codeforces.com/contest/257/submission/285747573
def main():
    n = II()
    angles = []

    for _ in range(n):
        x, y = MII()
        angles.append(math.atan2(y, x))

    angles.sort()

    ans = 0
    for i in range(1, n):
        ans = fmax(ans, angles[i] - angles[i - 1])

    print(fmin(2 * math.pi - ans, angles[-1] - angles[0]) / math.pi * 180) 