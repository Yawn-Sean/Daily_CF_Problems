"""
problem: https://codeforces.com/contest/242/problem/D
submission: https://codeforces.com/contest/242/submission/266661969
"""

def main():
    n, m = MII()
    adj = defaultdict(list)
    for _ in range(m):
        u, v = MII()
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    a = list(MII())
    # 如果某个节点不满足条件，则将其加入队列
    q = deque()
    st = [0] * n 
    cnt = [0] * n 
    for i, [x, y] in enumerate(zip(cnt, a)):
        if x == y: q.append(i)

    while len(q):
        v = q.popleft()
        st[v] = 1
        cnt[v] += 1 
        for nxt in adj[v]: 
            cnt[nxt] += 1 
            if cnt[nxt] == a[nxt] and st[nxt] == 0: 
                st[nxt] = 1
                q.append(nxt) 

    if len(q): print(-1)
    else:
        print(sum(st))
        print(*[i + 1 for i, x in enumerate(st) if x])
