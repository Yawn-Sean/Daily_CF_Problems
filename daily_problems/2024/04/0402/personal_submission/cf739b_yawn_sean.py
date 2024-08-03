# Submission link: https://codeforces.com/contest/739/submission/254644378
def main():
    n = II()
    nums = LII()

    k = n.bit_length()
    tree = [[] for _ in range(n)]
    parent = [[-1] * n for _ in range(k)]
    dist = [[0] * n for _ in range(k)]

    for i in range(1, n):
        p, d = MII()
        p -= 1
        parent[0][i] = p
        tree[p].append(i)
        dist[0][i] = d

    for i in range(k - 1):
        for j in range(n):
            if parent[i][j] != -1:
                parent[i+1][j] = parent[i][parent[i][j]]
                dist[i+1][j] = dist[i][j] + dist[i][parent[i][j]]

    ans = [0] * n
    for i in range(1, n):
        ans[parent[0][i]] += 1
        cur = nums[i]
        for j in range(k - 1, -1, -1):
            if parent[j][i] != -1 and dist[j][i] <= cur:
                cur -= dist[j][i]
                i = parent[j][i]
        if i: ans[parent[0][i]] -= 1

    stack = [0]
    order = []
    while stack:
        u = stack.pop()
        order.append(u)
        for v in tree[u]:
            stack.append(v)

    for u in reversed(order):
        if u:
            ans[parent[0][u]] += ans[u]

    print(' '.join(map(str, ans)))
