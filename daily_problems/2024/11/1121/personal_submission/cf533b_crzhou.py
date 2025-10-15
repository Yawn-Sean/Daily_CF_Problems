
data = input().split()
n = int(data[0])

tree = [[] for _ in range(n)]
weights = [0] * n
parents = [-1] * n

_, weights[0] = map(int, data[1:3])
index = 3

for i in range(1, n):
    p, w = map(int, data[index:index+2])
    index += 2
    tree[p - 1].append(i)
    weights[i] = w
    parents[i] = p - 1

dp = [[0, -inf] for _ in range(n)]

order = []
stack = [0]
while stack:
    node = stack.pop()
    order.append(node)
    for child in tree[node]:
        stack.append(child)

for node in reversed(order):
    even, odd = 0, -inf
    for child in tree[node]:
        child_even, child_odd = dp[child]
        even, odd = (
            max(even + child_even, odd + child_odd),  # 当前为偶数
            max(odd + child_even, even + child_odd),  # 当前为奇数
        )
    dp[node][0] = even
    dp[node][1] = max(odd, even + weights[node])

print(max(dp[0][0], dp[0][1]))
