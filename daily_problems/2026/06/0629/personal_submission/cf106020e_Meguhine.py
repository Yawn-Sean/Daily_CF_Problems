import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input())
    p = list(map(int, input().split()))
    vis = bytearray(n)
    ans, a = 0, []
    for i in range(n):
        if vis[i]:
            continue
        vis[i] = 1
        b = [i + 1]
        while True:
            j = p[i] - 1
            if vis[j]:
                break
            vis[j] = 1
            b.append(j + 1)
            i = j
        s = sum(x if (i & 1) else (-x) for i, x in enumerate(b))
        res = abs(s)
        m = len(b)
        f = m & 1
        b += b
        j = 0
        for i in range(m, m << 1):
            s -= b[j] if (j & 1) else (-b[j])
            j += 1
            s += b[i] if (i & 1) else (-b[i])
            res = max(res, abs(s))
        if f & 1:
            a.append(res)
        else:
            ans += res
    a.sort(reverse=True)
    for i, x in enumerate(a):
        ans += (-x) if (i & 1) else x
    return str(ans)


print('\n'.join(solve() for _ in range(int(input()))))


"""
trivial 贪心
"""
