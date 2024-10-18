# 题解
# https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/07/0708/solution/cf1195d2.md
def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 998244353
    c = [0] * 15
    for x in a:
        c[len(str(x))] += 1
    ans = 0
    for x in a:
        q,w,e = x, 0, 1
        for i in range(1, 11):
            w = (w + q % 10 * e) % mod
            q = q // 10
            ans +=  (q * 10 * e + w ) * c[i] * 10 % mod
            ans += (q * 100 * e + w) * c[i] % mod 
            ans %= mod
            e = e * 100 % mod
    print(ans)

main()