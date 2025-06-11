# Submission link: https://codeforces.com/contest/1177/submission/274609437
def main():
    k = II()
    k -= 1

    start, digit, cnt = 1, 1, 9
    while k >= digit * cnt:
        k -= digit * cnt
        start *= 10
        digit += 1
        cnt *= 10

    x, y = divmod(k, digit)
    print(str(start + x)[y])