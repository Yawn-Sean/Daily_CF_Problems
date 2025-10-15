# Submission link: https://codeforces.com/contest/199/submission/327856823
def main():
    x1, y1, r1, R1 = MII()
    x2, y2, r2, R2 = MII()

    v = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)

    def check(f, r0, r, R):
        if r >= r0 and (r - r0) * (r - r0) >= f: return 1
        if R <= r0 and (R - r0) * (R - r0) >= f: return 1
        if (R + r0) * (R + r0) <= f: return 1
        return 0

    print(check(v, r1, r2, R2) + 
        check(v, R1, r2, R2) + 
        check(v, r2, r1, R1) + 
        check(v, R2, r1, R1))