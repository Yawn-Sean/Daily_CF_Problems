# Submission link: https://codeforces.com/contest/441/submission/276720967
def main():
    n = II()
    perm = LGMI()

    vis = [0] * n
    swaps = n

    for i in range(n):
        if not vis[i]:
            while not vis[i]:
                vis[i] = 1
                i = perm[i]
            swaps -= 1

    target = II()
    outs = []

    print(abs(target - swaps))
    if target > swaps:
        for _ in range(target - swaps):
            for i in range(n):
                vis[i] = 0
            tmp = []
            for i in range(n):
                if not vis[i]:
                    tmp.append(i)
                    while not vis[i]:
                        vis[i] = 1
                        i = perm[i]
                    if len(tmp) == 2: break
            perm[tmp[0]], perm[tmp[1]] = perm[tmp[1]], perm[tmp[0]]
            outs.append(f'{tmp[0] + 1} {tmp[1] + 1}')
    else:
        for _ in range(swaps - target):
            for i in range(n):
                vis[i] = 0
            
            for i in range(n):
                if perm[i] != i:
                    while not vis[i]:
                        vis[i] = 1
                        i = perm[i]
                    break
            
            tmp = []
            for i in range(n):
                if vis[i]:
                    tmp.append(i)
                    if len(tmp) == 2: break
            
            perm[tmp[0]], perm[tmp[1]] = perm[tmp[1]], perm[tmp[0]]
            outs.append(f'{tmp[0] + 1} {tmp[1] + 1}')

    print(' '.join(outs))