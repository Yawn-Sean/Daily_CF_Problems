n = int(input())
ans = [-1] * n
queries = []

for i in range(n):
    opt, t, x = map(int, input().split())
    queries.append((x, i, opt, t))

# 离散化
time_map = {v: i + 1 for i, v in enumerate(sorted(q[3] for q in queries))}

# 按 x 和 id 排序
queries.sort()

fenwick = FenwickTree(len(time_map))

it = 0
while it < n:
    cur = it
    while it < n and queries[it][0] == queries[cur][0]:
        x, idx, opt, t = queries[it]
        t = time_map[t]
        if opt == 1:
            fenwick.modify(t, 1)  # 添加
        elif opt == 2:
            fenwick.modify(t, -1)  # 删除
        elif opt == 3:
            ans[idx] = fenwick.query(t)  # 查询
        it += 1
    
    # 撤销
    for i in range(cur, it):
        _, _, opt, t = queries[i]
        t = time_map[t]
        if opt == 1:
            fenwick.modify(t, -1)  # 撤销添加
        elif opt == 2:
            fenwick.modify(t, 1)  # 撤销删除


print('\n'.join(str(res) for res in ans if res != -1))
