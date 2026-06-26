import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, s = map(int, input().split())
    if n == 1:
        return "0"
    m = n >> 1
    pivot = m * 3 + (n & 1)
    if s >= pivot:
        r = s - pivot
        if n & 1 or (not r & 1):
            return "0"
        elif r == 1:
            return "1"
        elif n > 2:
            return "0"
        else:
            return "0" if (r + 3).bit_count() >= 2 else "1"
    else:
        r = s - n
        return str(n - r * 2 - 1)


print('\n'.join(solve() for _ in range(int(input()))))


"""
考虑用 1 2 1 2 1 的形式去填
如果 n 是奇数:
    设剩余的值为 x
    - 如果 x 是偶数, 那直接加到任意一个 2 上
    - 如果 x 是奇数, 先变成 2 1 2 1 2, 再把 (x-1) 加到任意一个 2 上
否则 n 是偶数:
    设剩余的值为 x
    - 如果 x 是偶数, 那直接加到任意一个 2 上
    - 如果 x 是奇数, 现在翻转也没用了, 需要考虑其他方法

现在只剩 n 是偶数且 x 是奇数
- x==1, 答案一定为 1 (3 1 2 1 ...)
- x>=3
    - n>2, 先变成 2 4 1 2 1 2, 然后把 (x-3) 加到最后一个 2 上
    - n==2, 那就看 (x+3) 的二进制表示有几个 1 即可
"""
