"""
奇数项和偶数项相等，所以只关心偶数项，2 * i, i >= n + 1
a[2 * i] = a[1] ^ ... ^ a[n] ^ a[n + 1] ^ ... ^ a[i]
讨论奇偶：
- n 为奇数且 i 为奇数，则为 a[1] ^ ... ^ a[n]
- n 为奇数且 i 为偶数，则为 a[1] ^ ... ^ a[n] ^ a[i]，继续递归求 a[i]
- n 为偶数且 i 为奇数，则为 a[1] ^ ... ^ a[n] ^ a[n + 1]，继续递归求 a[n + 1]
- n 为偶数且 i 为偶数，则为 a[1] ^ ... ^ a[n + 1] ^ a[i]，继续递归求 a[i] 和 a[n + 1]
另外，当 2 * i < n 时，直接给出结果即可
"""
import sys

input = lambda: sys.stdin.readline().rstrip()

T = int(input())
while T > 0:
    T -= 1
    n, l, r = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    s = [0]
    for i in range(1, n + 1):
        s.append(s[i - 1] ^ a[i])

    def calc(k):
        if k <= n:
            return a[k]

        if k % 2 != 0:
            k -= 1

        # 至此，k 为偶数
        if k <= 2 * n:
            return s[k // 2]

        # k >= 2 * n + 2
        i = k // 2
        if n % 2 != 0 and i % 2 != 0:
            return s[n]
        elif n % 2 != 0 and i % 2 == 0:
            return s[n] ^ calc(i)
        elif n % 2 == 0 and i % 2 != 0:
            return s[n] ^ calc(n + 1)
        else:
            return s[n] ^ calc(n + 1) ^ calc(i)

    print(calc(l))
