def main():
    outs = []
    t = II()

    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        outs.append('NO' if max(sum(len(path[x]) >= 2 for x in path[i]) for i in range(n)) >= 3 else 'YES')

    print('\n'.join(outs))
