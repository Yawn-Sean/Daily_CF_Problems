# Submission link: https://codeforces.com/contest/501/submission/262205043
def main():
    n = II()
    perm1 = LII()
    order1 = [0] * n

    fen = FenwickTree(n)
    for i in range(n):
        order1[i] = perm1[i] - fen.sum(perm1[i])
        fen.add(perm1[i], 1)

    perm2 = LII()
    order2 = [0] * n

    fen = FenwickTree(n)
    for i in range(n):
        order2[i] = perm2[i] - fen.sum(perm2[i])
        fen.add(perm2[i], 1)

    order = [0] * n
    carry = 0
    for i in range(n - 1, -1, -1):
        carry, order[i] = divmod(order1[i] + order2[i] + carry, n - i)

    ans = [0] * n
    fen = FenwickTree(n, [1] * n)
    for i in range(n):
        ans[i] = fen.bisect_min_larger(order[i] + 1)
        fen.add(ans[i], -1)

    print(' '.join(map(str, ans)))