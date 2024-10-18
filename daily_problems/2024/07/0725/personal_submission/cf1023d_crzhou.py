n, q = MII()
nums = LII()

if 0 in nums:
    idx = nums.index(0)
    cur = 1
    for i in range(n):
        if nums[i] == 0:
            nums[i] = cur
        else:
            cur = nums[i]
    if q not in nums:
        nums[idx] = q
else:
    if q not in nums:
        print('NO')
        return

pos = [[] for _ in range(q + 1)]
for i in range(n):
    pos[nums[i]].append(i)

seg_tree = SegmentTree(n)
seg_tree.build([float('inf')] * n)

for i in range(1, q + 1):
    if len(pos[i]):
        start = pos[i][0]
        end = pos[i][-1]

        # 检查[start, end]区间内是否存在元素
        if seg_tree.range_min(start, end + 1) != float('inf'):
            print('NO')
            return

        # 在线段树中添加这些位置
        for p in pos[i]:
            seg_tree.update(p, i)

print('YES')
print(' '.join(map(str, nums)))
