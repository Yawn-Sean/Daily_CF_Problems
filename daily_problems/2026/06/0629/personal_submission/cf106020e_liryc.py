'''
https://codeforces.com/gym/106020/submission/380517141
'''

def solve(n: int, p: list[int]) -> int:
    vis = [False] * (n + 1)
    s = n * (n + 1) >> 1
    so = 0
    odds = [] 

    for i in range(1, n + 1):
        if vis[i]:
            continue
        va = []
        ci = i
        while not vis[ci]:
            vis[ci] = True
            va.append(ci)
            ci = p[ci]

        la = len(va)

        if la % 2 == 0:
            h0 = 0
            j = 0
            while j < la:
                h0 += va[j]
                j += 2
            h1 = 0
            j = 1
            while j < la:
                h1 += va[j]
                j += 2
            so += h0 if h0 > h1 else h1
        else:
            k = la - 1 >> 1
            if k == 0:
                mb = 0
                sm = va[0]
            else:
                w = va + va  
                b = 0
                j = 1
                cnt = 0
                while cnt < k:
                    b += w[j]
                    j += 2
                    cnt += 1
                mb = b
                r = 0
                for _ in range(la - 1):
                    b = b - w[r + 1] + w[r + 2 * k + 1]
                    r += 2
                    if r >= la:
                        r -= la
                    if b < mb:
                        mb = b
                sm = 0
                for v in va:
                    sm += v

            odds.append((sm - 2 * mb, mb))

    odds.sort(key=lambda x: -x[0])
    ts = 0
    for idx, (d, b) in enumerate(odds):
        if idx & 1:
            ts += b       
        else:
            ts += b + d  

    so += ts
    return 2 * so - s
