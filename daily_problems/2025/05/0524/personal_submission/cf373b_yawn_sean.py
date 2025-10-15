# Submission link: https://codeforces.com/contest/373/submission/320965371
def main():
    w, m, k = MII()

    w //= k

    v = 10
    digit = 1

    ans = 0

    while True:
        l = fmax(0, v - m)
        if l * digit <= w:
            w -= l * digit
            ans += l
            m += l
        else:
            ans += w // digit
            break
        
        v *= 10
        digit += 1

    print(ans)