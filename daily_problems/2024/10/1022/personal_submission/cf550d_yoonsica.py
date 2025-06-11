'''思路：
桥两边两个点,分别是两个联通块，单独考虑一个
桥的端点需要另外k - 1个点，这k - 1个点还需要k - 1个点
最后的k - 1个点，每两个连接即可
注意k为偶数时无解
https://codeforces.com/contest/550/submission/287303165
'''

k = RI()

edges = []
def solve(idx):
    # 1 [2, k] [k + 1, 2*k - 1]
    # 新建k - 1个点连idx
    for i in range(1, k):
        edges.append((idx, idx + i))
    # 再新建k - 1个点连前面k - 1个点
    for i in range(idx + 1, idx + k):
        for j in range(idx + k, idx + 2 * k - 1):
            edges.append((i, j))
    # k - 1个点两两链接
    for j in range(idx + k, idx + 2 * k - 1, 2):
        edges.append((j, j + 1))


if k & 1 == 0:
    print('NO')
else:
    print('YES')
    # 左边有 1 + k - 1 + k - 1个点
    edges.append((1, 2*k))
    solve(1)
    solve(2*k)
    print(4 * k - 2, len(edges))
    for a, b in edges:
        print(a, b)
        