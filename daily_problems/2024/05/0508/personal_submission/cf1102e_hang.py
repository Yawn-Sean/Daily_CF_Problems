from collections import Counter
def main():
    n = int(input())
    a = list(map(int, input().split()))
    r = dict()
    for i,x in enumerate(a):
        r[x] = i
    ans = 1
    mod = 998244353
    limit = r[a[0]]
    for i in range(1, n):
        if i <= limit:
            limit = max(limit, r[a[i]])
        else:
            ans *= 2
            ans %= mod
            limit = max(limit, r[a[i]])

    print(ans)

main()