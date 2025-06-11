# 题解： https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/08/0823/solution/cf1184a2.md
from math import gcd

def main():
    n = int(input())
    y = [int(x) for x in input()]
    cnt = [0] * n
    check = [False] * (n + 1)
    res = 0
    for i in range(1, n + 1):
        if n % i == 0:
            for j in range(n):
                cnt[j % i] ^= y[j]
            check[i] = True
            for j in range(i):
                if cnt[j]:
                    cnt[j] = 0
                    check[i] = False
        res += check[gcd(i, n)]

    print(res)

main()