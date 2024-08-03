def main():
    n, k = MII()
    nums = LII()
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = GMI()
        g[a].append(b)
        g[b].append(a)
    val = reduce(xor, nums)

    if val == 0:  # 如果每个元素的异或和恰好等于 0 直接输出 'YES' 即可。
        return "YES"
    elif k == 2:
        return "NO"
    else:
        parent = [-1] * n
        stack = [0]
        order = []
        while stack:
            u = stack.pop()
            order.append(u)
            for v in g[u]:
                if parent[u] != v:
                    parent[v] = u
                    stack.append(v)
        dp = [0] * n
        xor_value = nums[:]
        for u in reversed(order):  # 从叶子结点开始向根节点更新
            if xor_value[u] == val:
                dp[u] += 1
                xor_value[u] = 0
            if u:
                dp[parent[u]] += dp[u]  # 以 u 为根的子树中，异或和等于 val 的节点个数
                xor_value[parent[u]] ^= xor_value[u]
        return (
            "NO" if dp[0] == 1 else "YES"
        )  # 如果以 0 为根的子树中，异或和等于 val 的节点个数为 1，则输出 'NO'，否则输出 'YES'。
    return
