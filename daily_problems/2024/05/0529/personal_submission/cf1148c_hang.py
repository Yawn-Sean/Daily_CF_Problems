def main():
    n = int(input())
    p = list(map(lambda x: int(x) - 1, input().split()))
    pos = [-1] * n
    for i in range(n): pos[p[i]] = i

    ans = []
    def f(u,v):
        pos[p[u]],pos[p[v]] = pos[p[v]],pos[p[u]]
        p[u], p[v] = p[v], p[u]
        ans.append(f'{u + 1} {v + 1}')
    for i in range(1, n // 2):
        if pos[i] != i:
            if pos[i] < n // 2:
                f(pos[i], n-1)
            else:
                f(0, pos[i])
                f(0, n-1)
            f(i, n-1)
    for i in range(n//2, n):
        if pos[i] != i:
            if pos[i] < n // 2:
                f(pos[i], n-1)
                f(0, n-1)
            else:
                f(0, pos[i])
            f(i, 0)
    if p[0] != 0:
        f(0, n-1)
    print(len(ans))
    print('\n'.join(ans))
        

main()