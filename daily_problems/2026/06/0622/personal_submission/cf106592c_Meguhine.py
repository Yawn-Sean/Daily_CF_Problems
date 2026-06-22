import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    m, n = map(int, input().split())
    a = list(map(int, input().split()))

    l, r, ans = 0, 10**9, -1
    while l <= r:
        mid = (l + r) >> 1
        if sum(min(x, mid) for x in a) <= m:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    assert ans != -1
    b = [min(x, ans) for x in a]
    m -= sum(b)
    if m:
        for i, (lim, x) in enumerate(zip(a, b)):
            if x < lim:
                b[i] += 1
                m -= 1
                if m == 0:
                    break
    return ' '.join(map(str, b))


print('\n'.join(solve() for _ in range(int(input()))))


"""
任意两个月的文章, 都是相乘然后加一起, 因此顺序没有影响
考虑有 x,y,S, S 指代除了 x,y 之外的剩余文章
那么有 xy+S(x+y), 为了使最大化, x,y 要尽量靠近
所以文章的分布要尽量均匀, 这个值二分即可
"""
