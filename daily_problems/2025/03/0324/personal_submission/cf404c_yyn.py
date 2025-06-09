def main():
    n,k = MII()
    d = LII()
    stk = []
    dis = defaultdict(list)
    for i,x in enumerate(d):
        if x == 0:
            if stk:
                return print(-1)
            stk.append(i)
            st = i
        else:
            dis[x].append(i)
    dis = dict(sorted(dis.items()))
    d = 1
    ans = []
    while stk:
        path = stk[::]
        stk = []
        for u in path:
            if u == st:
                for i in range(k):
                    if d in dis and dis[d]:
                        ans.append([dis[d][-1],u])
                        stk.append(dis[d].pop())
                    else:
                        break
            else:
                for i in range(k - 1):
                    if d in dis and dis[d]:
                        ans.append([dis[d][-1],u])
                        stk.append(dis[d].pop())
                    else:
                        break
        if d in dis and dis[d]:
            return print(-1)
        d += 1
    for k,v in dis.items():
        if v:
            return print(-1)
    print(len(ans))
    for a,b in ans:
        print(a + 1,b + 1)
