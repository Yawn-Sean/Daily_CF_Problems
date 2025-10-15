# Submission link: https://codeforces.com/contest/1109/submission/304196311
def main():
    s = I()
    n = len(s)

    flg = False
    for i in range(1, n // 2):
        if s[i] != s[i - 1]:
            flg = True

    for i in range(n - n // 2, n - 1):
        if s[i] != s[i + 1]:
            flg = True

    if not flg:
        print('Impossible')
    else:
        while len(s) % 2 == 0:
            v = s[:len(s) // 2]
            if v != v[::-1]:
                exit(print(1))
            s = v
        print(2)