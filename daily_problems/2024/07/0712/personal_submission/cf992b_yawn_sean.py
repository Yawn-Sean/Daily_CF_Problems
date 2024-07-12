# Submission Link: https://codeforces.com/contest/992/submission/270093732
def main():
    l, r, x, y = MII()
    if y % x: print(0)
    elif x == y:
        print(1 if l <= x <= r else 0)
    else:
        v = y // x
        ans = 0
        for i in range(1, 10 ** 5):
            if i * i >= v: break
            if v % i == 0 and math.gcd(i, v // i) == 1 and l <= i * x <= r and l <= v // i * x <= r:
                ans += 2
        print(ans)