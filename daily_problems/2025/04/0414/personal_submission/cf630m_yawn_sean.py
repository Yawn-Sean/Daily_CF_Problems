# Submission link: https://codeforces.com/problemset/submission/630/315516029
def main():
    x = II()
    x %= 360

    diff = 360
    times = -1

    for i in range(4):
        v = (x - i * 90) % 360
        v = fmin(v, 360 - v)
        if v < diff:
            diff = v
            times = i

    print(times)