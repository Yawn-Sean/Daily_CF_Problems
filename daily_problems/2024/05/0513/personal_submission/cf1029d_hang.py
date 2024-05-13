
from collections import Counter
def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    z = [Counter() for i in range(11)]
    ans = 0
    for i in range(n):
        p = 1
        for j in range(11):
            z[j][(a[i] * p) % k] += 1
            p *= 10
    for i in range(n):
        t = (k - (a[i] % k)) % k
        m = len(str(a[i]))
        ans += z[m][t]
        if a[i] * pow(10, m) % k == t:
            ans -= 1

    print(ans)



if __name__ == '__main__':
    main()

