def dfs(l, n, a, pre):
    if l <= 2 * n + 2:
        return a[l]
    mid = l // 2
    if mid % 2 == 1:
        if n % 2 == 1:
            return pre[n]
        else:
            return pre[n + 1]
    else:
        if n % 2 == 1:
            return dfs(mid, n, a, pre) ^ pre[n]
        else:
            return dfs(mid, n, a, pre) ^ pre[n + 1]


def solve():
    import sys

    n, l, r = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    pre = [0] * (2 * n + 10)
    for i in range(1, n + 1, 1):
        pre[i] = pre[i - 1] ^ a[i]
    for i in range(n + 1, 2 * n + 3, 1):
        a.append(pre[i // 2])
        pre[i] = pre[i - 1] ^ a[i]

    if l <= n:
        print(a[l])
    else:
        print(dfs(l, n, a, pre))


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
