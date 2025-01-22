import math
def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = 0

    for i in range(n):
        ans += (4 * i- 2*n+ 3) * a[i]
    g = math.gcd(ans, n)
    print(ans // g, n // g)

main()