'''
https://codeforces.com/contest/847/submission/285278982
CF847H
2024/10/11 Y1
1600
'''
# ref

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    pt = [0] * n
    pv = [0] * n

    for i in range(n - 1):
        pv[i + 1] = max(pv[i] + 1, a[i])
        pt[i + 1] = pt[i] + pv[i + 1] - a[i]

    st = [0] * n
    sv = [0] * n

    for i in range(n - 1, 0, -1):
        sv[i - 1] = max(sv[i] + 1, a[i])
        st[i - 1] = st[i] + sv[i - 1] - a[i]

    ans = 10 ** 15
    for i in range(n):
        ans = min(ans, pt[i] + st[i] + max(max(pv[i], sv[i]) + 1 - a[i], 0))

    print(ans)