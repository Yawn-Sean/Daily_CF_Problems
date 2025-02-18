# https://codeforces.com/contest/178/submission/286320157

h, m, n = RII()
ans = 0
g_idx = [(-1, -1)] * h # 每个位置属于哪个组里的第几个元素
idx = 0
cnt = 0
for i in range(h):
    if g_idx[i] == (-1, -1):
        j = i
        pos = 0
        while g_idx[j] == (-1, -1):
            g_idx[j] = (idx, pos) # 第j个位置属于第idx个组，在组内第pos位
            j = (j + m) % h
            pos += 1
        cnt = mx(cnt, pos)
        idx += 1

# 初始每个位置都可以选
sls = [SortedList(range(cnt)) for _ in range(idx)]

mp = defaultdict(list) # 记录每个hash存在哪个位置
for _ in range(n):
    s = RS().split()
    if s[0] == '+':
        id, hash = s[1:]
        hash = int(hash)
        sl = sls[g_idx[hash][0]]
        j = sl.bisect_left(g_idx[hash][1])
        if j < len(sl):
            ans += sl[j] - g_idx[hash][1]
        else:
            j = 0
            ans += cnt - g_idx[hash][1] + sl[j]
        mp[id] = [g_idx[hash][0], sl[j]]
        sl.remove(sl[j])
    else:
        id = s[1]
        x, y = mp[id] # 组id，组内位置id
        sls[x].add(y) # id对应的位置编号放回原来组里
        mp.pop(id)
print(ans)


