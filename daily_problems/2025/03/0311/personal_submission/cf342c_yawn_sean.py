# Submission link: https://codeforces.com/contest/342/submission/309897105
def main():
    r, h = MII()
    ans = h // r * 2
    h %= r

    if h * h * 4 >= r * r * 3: ans += 3
    elif h * 2 >= r: ans += 2
    else: ans += 1

    print(ans)