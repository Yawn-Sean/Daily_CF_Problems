# Submission link: https://codeforces.com/contest/1599/submission/308008861
def main():
    n, p = LI()
    n = int(n)
    p = float(p)

    for i in range(n + 1):
        prob = 0
        prob += i * (i - 1) * (i - 2) // 6
        prob += i * (i - 1) // 2 * (n - i)
        prob += i * (n - i) * (n - i - 1) // 2 / 2
        if prob / (n * (n - 1) * (n - 2) // 6) >= p:
            print(i)
            break
