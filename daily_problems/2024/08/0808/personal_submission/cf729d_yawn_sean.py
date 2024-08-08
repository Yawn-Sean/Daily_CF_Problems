# Submission link: https://codeforces.com/contest/729/submission/275154706
def main():
    n, a, b, k = MII()
    s = I()

    tmp = []
    cur = 0
    for i in range(n):
        if s[i] == '0':
            cur += 1
            if cur == b:
                tmp.append(i)
                cur = 0
        else:
            cur = 0

    for _ in range(a - 1):
        tmp.pop()

    print(len(tmp))
    print(*(x + 1 for x in tmp))