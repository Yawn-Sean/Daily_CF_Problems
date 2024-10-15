# Submission link: https://codeforces.com/contest/1184/submission/277716507
def main():
    n = II()
    s = [int(x) for x in I()]

    cnt = [0] * n
    check = [False] * (n + 1)
    ans = 0
    
    for i in range(1, n + 1):
        if n % i == 0:
            for j in range(n):
                cnt[j % i] ^= s[j]
            check[i] = True
            for j in range(i):
                if cnt[j]:
                    cnt[j] = 0
                    check[i] = False
        ans += check[math.gcd(i, n)]

    print(ans)