def f(rest, l, r):
    if l > r: return (0, 0)
    left, right = l, r
    while left < right:
        mid = left + right >> 1
        if (l + mid) * (mid - l + 1) // 2 >= rest: right = mid
        else: left = mid + 1

    return ((l + left) * (left - l + 1) // 2, left - l + 1)


def soviet():
    n, s = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    a.sort()

    tot = sum(a)
    if tot >= s:
        print(n)
        return

    a.append(10 ** 18)
    ans = n
    for i in range(n + 1):
        rest, len = f(s - tot, a[i] + 1, a[i + 1] - 1)
        tot += rest
        ans += len
        if tot >= s:
            break

    print(ans)

soviet()
