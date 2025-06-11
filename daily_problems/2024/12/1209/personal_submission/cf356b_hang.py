import math
from collections import Counter
def main():
    n,m = map(int, input().split())
    x = input()
    y = input()
    k1 = len(x)
    k2 = len(y)
    g = math.gcd(k1, k2)
    ans = 0
    for i in range(g):
        cnt = Counter()
        for j in range(i, k1, g):
            cnt[x[j]] += 1
        for j in range(i, k2, g):
            ans += cnt[y[j]]

    print(n * k1 - math.gcd(n, m) * ans)
main()