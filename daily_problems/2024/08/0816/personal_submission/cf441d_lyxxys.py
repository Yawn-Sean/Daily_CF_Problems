import sys

def main():
    n = int(input())
    P = list(map(lambda x: int(x)-1, input().split()))
    m = int(input())
    All = n
    vis = [0 for _ in range(n)]

    for i in range(n):
        if not vis[i]:
            while not vis[i]:
                vis[i] = 1
                i = P[i]
            All -= 1

    det = abs(All - m)
    print(det)

    # 讨论合并环 还是 拆分环
    outs = []
    # 合并：找两个不同的环的最小下标
    if All < m:
        t = det
        while t:
            t -= 1
            for i in range(n): vis[i] = 0
            tmps = []
            for i in range(n):
                if not vis[i]:
                    tmps.append(i)
                    while not vis[i]:
                        vis[i] = 1
                        i = P[i]
                    if len(tmps) == 2: break
            P[tmps[0]], P[tmps[1]] = P[tmps[1]], P[tmps[0]]
            outs.append(f'{tmps[0]+1} {tmps[1]+1}')

    #拆分：找相同环的最小两个数
    else:
        t = det
        while t:
            t -= 1
            for i in range(n): vis[i] = 0

            for i in range(n):
                if i != P[i]:
                    while not vis[i]:
                        vis[i] = 1
                        i = P[i]
                    break

            tmps = []
            for i in range(n):
                if vis[i]:
                    tmps.append(i)
                if (len(tmps) == 2): break

            P[tmps[0]], P[tmps[1]] = P[tmps[1]], P[tmps[0]]
            outs.append(f'{tmps[0]+1} {tmps[1]+1}')

    print(' '.join(outs))
