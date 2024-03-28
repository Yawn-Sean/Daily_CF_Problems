import math
def main():
    n = int(input())
    a = list(map(int, input().split()))
    if 1 in a:
        print(n - a.count(1))
        return
    ans = 10**9
    for i in range(n-1):
        z = a[i]
        for j in range(i + 1, n):
            z = math.gcd(z, a[j])
            if z == 1:
                ans = min(ans,j-i)
                break
    if ans < 10**9:
        print(ans + n - 1)
    else:
        print(-1)
main()
