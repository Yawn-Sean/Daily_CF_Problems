# Submission link: https://codeforces.com/contest/662/submission/257239305
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    for _ in range(m):
        u, v, c = LI()
        u = int(u) - 1
        v = int(v) - 1
        c = 1 if c == 'R' else 0
        path[u].append((v, c))
        path[v].append((u, c))

    ans = inf
    chosen = []

    for target in range(2):
        flips = [-1] * n
        f = True
        for i in range(n):
            if flips[i] == -1:
                flips[i] = 0
                stack = [i]
                block = []
                while stack:
                    u = stack.pop()
                    block.append(u)
                    for v, c in path[u]:
                        if c == target:
                            if flips[v] == -1:
                                flips[v] = flips[u]
                                stack.append(v)
                            elif flips[v] != flips[u]:
                                f = False
                        else:
                            if flips[v] == -1:
                                flips[v] = flips[u] ^ 1
                                stack.append(v)
                            elif flips[v] == flips[u]:
                                f = False
                if not f: break
                res = sum(flips[i] for i in block)
                if res > len(block) - res:
                    for x in block:
                        flips[x] ^= 1
        if f and sum(flips) < ans:
            ans = sum(flips)
            chosen = [i for i in range(n) if flips[i]]

    if ans < inf:
        print(ans)
        print(' '.join(str(x + 1) for x in chosen))
    else:
        print(-1)