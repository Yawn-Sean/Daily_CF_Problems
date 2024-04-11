# Submission link: https://codeforces.com/contest/1592/submission/256059680
def main():
    n, k = MII()
    nums = LII()
    
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    val = reduce(xor, nums)
    if val == 0: return 'YES'
    elif k == 2: return 'NO'
    else:
        parent = [-1] * n
        stack = [0]
        order = []
        while stack:
            u = stack.pop()
            order.append(u)
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    stack.append(v)
        dp = [0] * n
        xor_value = nums[:]
        for u in reversed(order):
            if xor_value[u] == val:
                dp[u] += 1
                xor_value[u] = 0
            if u:
                dp[parent[u]] += dp[u]
                xor_value[parent[u]] ^= xor_value[u]
        return 'NO' if dp[0] == 1 else 'YES'