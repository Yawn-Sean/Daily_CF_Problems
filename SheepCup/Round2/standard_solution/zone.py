def main():
    n, m, q = MII()
    grid = []

    for _ in range(n):
        grid.extend(GMI())

    pos = []
    cols = []

    for _ in range(q):
        x, y, c = GMI()
        pos.append(x * m + y)
        cols.append(c)

    pos_op = lst_lst(n * m)

    for i in range(n * m):
        pos_op.append(grid[i], i * (q + 2))

    vis = [0] * (n * m)
    for i in range(q):
        p = pos[i]
        c = cols[i]
        
        if not vis[p]:
            if grid[p] != c:
                pos_op.append(grid[p], ~(p * (q + 2) + i + 1))
                pos_op.append(c, p * (q + 2) + i + 1)
            vis[p] = 1

    for i in range(n * m):
        vis[i] = -1

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    updates = lst_lst(n * m + 1)
    def apply(i, j, x):
        updates.append(x, i * (q + 2) + j)

    state = [0] * (n * m)
    for i in range(n * m):
        ops = list(pos_op.iterate(i))
        ops.reverse()
        chosen = []
        
        for op in ops:
            if op >= 0:
                p = op // (q + 2)
            else:
                p = (~op) // (q + 2)
            if vis[p] == -1:
                vis[p] = len(chosen)
                chosen.append(p)
        
        l = len(chosen)
        k = len(ops)
        dsu = UnionFind(l)

        for j in range(k + 1):
            if (j == 0 or ops[j - 1] < 0) and (j == k or ops[j] >= 0):
                cur_ans = 0
                dsu.init()
                
                for idx in range(l):
                    if state[chosen[idx]]:
                        if cur_ans == 0: cur_ans = 1
                        p = chosen[idx]
                        x, y = divmod(p, m)
                        for dx, dy in dirs:
                            nx = x + dx
                            ny = y + dy
                            np = nx * m + ny
                            if 0 <= nx < n and 0 <= ny < m and state[np]:
                                dsu.merge(vis[p], vis[np])
                        cur_ans = fmax(cur_ans, dsu.getSize(idx))
                
                tmp_ans = cur_ans
                tmstamp = ops[j] % (q + 2) if j < k else q + 1
                for idx in range(j - 1, -1, -1):
                    if ops[idx] >= 0: break
                    p, ntmstamp = divmod(~ops[idx], q + 2)
                    state[p] = 1
                    x, y = divmod(p, m)
                    for dx, dy in dirs:
                        nx = x + dx
                        ny = y + dy
                        np = nx * m + ny
                        if 0 <= nx < n and 0 <= ny < m and state[np]:
                            dsu.merge(vis[p], vis[np])

                    if ntmstamp < tmstamp:
                        apply(ntmstamp, tmstamp, tmp_ans)
                        tmstamp = ntmstamp
                    tmp_ans = fmax(tmp_ans, dsu.getSize(vis[p]))
                
                for idx in range(j - 1, -1, -1):
                    if ops[idx] >= 0: break
                    state[~ops[idx] // (q + 2)] = 0
                
                if j > 0:
                    dsu.init()
                    for idx in range(l):
                        if state[chosen[idx]]:
                            p = chosen[idx]
                            x, y = divmod(p, m)
                            for dx, dy in dirs:
                                nx = x + dx
                                ny = y + dy
                                np = nx * m + ny
                                if 0 <= nx < n and 0 <= ny < m and state[np]:
                                    dsu.merge(vis[p], vis[np])
                
                if j < k:
                    tmp_ans = cur_ans
                    tmstamp = ops[j] % (q + 2) if j < k else q + 1
                    
                    for idx in range(j, k):
                        if ops[idx] < 0: break
                        p = ops[idx] // (q + 2)
                        state[p] = 1
                        x, y = divmod(p, m)
                        
                        for dx, dy in dirs:
                            nx = x + dx
                            ny = y + dy
                            np = nx * m + ny
                            if 0 <= nx < n and 0 <= ny < m and state[np]:
                                dsu.merge(vis[p], vis[np])
                        
                        if idx == k - 1:
                            ntmstamp = q + 1
                        elif ops[idx + 1] >= 0:
                            ntmstamp = ops[idx + 1] % (q + 2)
                        else: ntmstamp = (~ops[idx + 1]) % (q + 2)
                        
                        tmp_ans = fmax(tmp_ans, dsu.getSize(vis[p]))
                        if tmstamp < ntmstamp:
                            apply(tmstamp, ntmstamp, tmp_ans)
                            tmstamp = ntmstamp
                    else:
                        ntmstamp = q + 1
                        if tmstamp < ntmstamp:
                            apply(tmstamp, ntmstamp, tmp_ans)
                    
                    for idx in range(j, k):
                        if ops[idx] < 0: break
                        state[ops[idx] // (q + 2)] = 0
                
            if j < k:
                if ops[j] >= 0: state[ops[j] // (q + 2)] = 1
                else: state[(~ops[j]) // (q + 2)] = 0

        for x in chosen:
            state[x] = 0
            vis[x] = -1

    ans = [0] * (q + 1)
    dsu1 = UnionFind1(q + 2)
    
    for i in range(n * m, 0, -1):
        for msk in updates.iterate(i):
            l, r = divmod(msk, q + 2)
            while dsu1.find(l) < r:
                l = dsu1.find(l)
                ans[l] = i
                dsu1.merge(l + 1, l)
    
    print('\n'.join(map(str, ans)))