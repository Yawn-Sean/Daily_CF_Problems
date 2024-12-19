def main():
    n,m = map(int,input().split())
    p = [0] + list(map(int,input().split()))
    pair = [0] * (2 * n + 1)
    for _ in range(m):
        a,b  =  map(int,input().split())
        pair[a] = b
        pair[b] = a
    vis = [0] * (2 * n + 1)
    t = int(input())
    pre = 0
    for _ in range(n):
        if t == 2:
            pre = int(input())
            vis[pre] = 1
        if pre and pair[pre] and not vis[pair[pre]]:
            print(pair[pre], flush=True)
            vis[pair[pre]] = 1
        else:
            dif, chosen = -1, 0
            for i in range(1, 2 * n + 1):
                if pair[i] and not vis[i] and p[i] - p[pair[i]] > dif:
                    dif = p[i] - p[pair[i]]
                    chosen = i
            if not chosen:
                for i in range(1, 2 * n + 1):
                    if not vis[i] and p[i] > dif:
                        dif = p[i]
                        chosen = i
            print(chosen, flush=True)
            vis[chosen] = 1
        if t == 1:
            pre = int(input())
            vis[pre] = 1
main()