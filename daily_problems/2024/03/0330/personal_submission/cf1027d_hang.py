# https://codeforces.com/contest/1027/submission/254097157
# 求环内节点代价的最小值
def main():
    n = int(input())
    c = list(map(int, input().split()))
    a = list(map(int, input().split()))

    c = [0] + c
    a = [0] + a
    d = [0] * (n + 1)
    for i in range(1, n + 1):
        d[a[i]] += 1
    from queue import Queue
    q = Queue()
    for i in range(1, n + 1):
        if d[i] == 0:
            q.put(i)
    while not q.empty():
        cur = q.get()
        d[a[cur]] -= 1
        if d[a[cur]] == 0:
            q.put(a[cur])
    
    ans = 0
    vis = [0] * (n + 1)
    for i in range(n + 1):
        if d[i] == 0:
            vis[i] = 1
    def f(cur):
        if vis[cur]:
            return 0
        
        res = 10**10
        while vis[cur] == 0:
            vis[cur] = 1
            res = min(res, c[cur])
            cur = a[cur]
        return res
    for i in range(1, n+1):
        ans += f(i)
    print(ans)

main()