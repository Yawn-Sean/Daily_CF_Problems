# Submission link: https://codeforces.com/contest/582/submission/320966394
def main():
    n = II()
    nums = LII()

    gcds = [math.gcd(i, n) for i in range(n)]

    ans = 0

    for i in range(1, n):
        if n % i == 0:
            ma = [0] * i
            for j in range(n):
                ma[j % i] = fmax(ma[j % i], nums[j])
            
            flg = [0] * (2 * n)
            calc = [0] * (n + 1)
            
            for j in range(n):
                if nums[j] == ma[j % i]:
                    flg[j] = 1
                    flg[j + n] = 1

            cur = 0
            for j in range(2 * n - 1, -1, -1):
                if flg[j]: cur += 1
                else: cur = 0
                if j < n:
                    calc[fmin(n, cur)] += 1
            
            for j in range(n - 1, -1, -1):
                calc[j] += calc[j + 1]
            
            for j in range(i, n, i):
                if gcds[j] == i:
                    ans += calc[j]

    print(ans)