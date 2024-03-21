import sys
input = lambda: sys.stdin.readline().strip()

# 题面的描述是移动数字，但其实我们可以想象成数字位置固定，变换数字对应的索引
# 假设某个数的初始索引为 i，每次查询后都会发生一次变化，且这种变化是确定的，也是可逆的
# 比如 i -> idx1 -> idx2 -> idx3 -> j，我们可以从 i 一步步得到 j，自然也可以通过 j 找到 i

n, q, m = map(int, input().split())
nums = list(map(int, input().split()))
query = []
for _ in range(q):
    t, l, r = map(int, input().split())
    query.append((t, l - 1, r - 1))

ans = []
for i in input().split():
    idx = int(i) - 1
    for t, l, r in query[::-1]:
        if idx < l or idx > r:
            continue
        if t == 1:
            idx = idx - 1 if idx > l else r
        else:
            idx = l + r - idx
    ans.append(nums[idx])

print(*ans)

