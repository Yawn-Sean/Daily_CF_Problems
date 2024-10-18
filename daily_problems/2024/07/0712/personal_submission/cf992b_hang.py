from math import sqrt,gcd
def main():
    l,r,x,y = map(int,input().split())
    if y % x != 0: return print(0)
    t = y // x
    ans = 0
    for i in range(1, int(sqrt(t)) + 1):
        if t % i == 0:
            a,b = i * x, t // i * x
            if gcd(a,b) != x: continue
            if l <= a <= r and l <= b <= r:
                ans += 1
                if a != b:
                    ans += 1
    print(ans)

main()