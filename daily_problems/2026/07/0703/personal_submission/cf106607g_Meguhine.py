import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, m, k = map(int, input().split())
    if n >= k:  # k 个 1, 其他全是 0
        return str(k)
    # 被注释掉的逻辑是错的, 反例是 `3 5 13`
    # if n * (m - 1) < k:  # 每个数都至少得是 (m-1)
    #     cm = k - n * (m - 1)
    #     return str(cm) if m & 1 else str(n - cm)
    if n * (m - 1) < k:
        cm = k - n * (m - 1)
        if (m - 1) & 1:
            return str(n - cm)
        else:  # 两个 (m-1) 可以变成 (m-2) 和 m, 都是奇数
            return str(n - ((n - cm) & 1))
    return str(n) if (n & 1) == (k & 1) else str(n - 1)


print('\n'.join(solve() for _ in range(int(input()))))
