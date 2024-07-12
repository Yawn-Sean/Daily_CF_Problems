
def solve():
    l, r, x, y = MII()
    if y % x:
        print(0)
        return ;
    y //= x
    res = 0
    for i in range(1, 10**5 + 7):
        if i * i >= y:
            break
        if y % i == 0 and math.gcd(i, y // i) == 1 and l <= i * x and i * x <= r and l <= y // i * x and y // i * x <= r:
            if y // i != i:
                res += 2
            else:
                res += 1
    print(res)

def main():
    t = 1
    while t:
        solve();
        t -= 1
main()
