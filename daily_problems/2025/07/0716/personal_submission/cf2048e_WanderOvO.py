"""
一共有 2n + m 个点，所以同一种颜色的边必须不超过 2n + m - 1
所以应该有 (2n + m - 1) * n >= 2mn => m <= 2n - 1
显然，在已知 n 时，m 越大越难构造，大的构造出来了，删掉一些点和边剩下的就是小的
所以只需要构造 m = 2n - 1 时的情况即可
只考虑某种颜色的边，比如 (a, b) 和 (c, b) 同色，那么建一个新图，让 (a, c) 连边
则某种颜色的边建新图之后不能有环，连成链
"""

T = int(input())
while T > 0:
    T -= 1
    n, m = map(int, input().split())
    if m >= 2 * n:
        print("NO")
    else:
        print("YES")
        res = [[0 for _ in range(m + 1)] for _ in range(2 * n + 1)]
        for i in range(1, m + 1):
            color = 1
            cnt = 0
            for j in range(2 * n):
                k = i + j
                if k > 2 * n:
                    k %= (2 * n)
                res[k][i] = color
                cnt += 1
                if cnt % 2 == 0:
                    color += 1

        for i in range(1, 2 * n + 1):
            for j in range(1, m + 1):
                print(res[i][j], end=' ')
            print()
