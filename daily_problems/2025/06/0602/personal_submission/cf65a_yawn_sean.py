# Submission link: https://codeforces.com/contest/65/submission/322457044
def main():
    a, b, c, d, e, f = MII()
    print("Ron" if a * c * e < b * d * f or (a == 0 and b and d) or (c == 0 and d) else "Hermione")