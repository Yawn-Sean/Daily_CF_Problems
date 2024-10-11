'''
submit link: https://codeforces.com/contest/992/submission/270194971
992B
2024/7/12 Y1
1600
prime, gcd, lcm
'''

def gcd(a, b):
    m = a % b
    return b if m == 0 else gcd(b, m)

l, r, x, y = map(int, input().split())
if y % x != 0:
    print(0)
elif x == y:
    if l <= x <= r:
        print(1)
    else:
        print(0)
else:
    ans, n = 0, y // x
    lo, hi = (l + x - 1) // x, r // x
    # find a, b such that gcd(a,b)==1 and a*b=n
    for a in range(lo, hi + 1):
        if a * a > n:
            break
        if n % a == 0:
            b = n // a
            if l <= b * x <= r and gcd(a, b) == 1:
                # print("found: ", a, b, a*x, b*x)
                ans += 2
    print(ans)
