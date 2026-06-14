'''
https://codeforces.com/gym/105442/submission/378814727
'''
def solve(n: int, pa: list[list[int]]) -> int:
    si_x = sorted(range(n), key=lambda i: pa[i][0])
    si_y = sorted(range(n), key=lambda i: pa[i][1])
    
    rv = [False] * n
    lx, rx, ly, ry = 0, n - 1, 0, n - 1
    
    for _ in range(n // 4 - 1):
        while lx < n and rv[si_x[lx]]: 
            lx += 1
        while rx >= 0 and rv[si_x[rx]]: 
            rx -= 1
        while ly < n and rv[si_y[ly]]: 
            ly += 1
        while ry >= 0 and rv[si_y[ry]]: 
            ry -= 1
            
        ra = []
        
        min_x = pa[si_x[lx]][0]
        i = lx
        while i < n and pa[si_x[i]][0] == min_x:
            idx = si_x[i]
            if not rv[idx]: 
                ra.append(idx)
            i += 1
            
        max_x = pa[si_x[rx]][0]
        i = rx
        while i >= 0 and pa[si_x[i]][0] == max_x:
            idx = si_x[i]
            if not rv[idx]: ra.append(idx)
            i -= 1
            
        min_y = pa[si_y[ly]][1]
        i = ly
        while i < n and pa[si_y[i]][1] == min_y:
            idx = si_y[i]
            if not rv[idx]: 
                ra.append(idx)
            i += 1
            
        max_y = pa[si_y[ry]][1]
        i = ry
        while i >= 0 and pa[si_y[i]][1] == max_y:
            idx = si_y[i]
            if not rv[idx]: 
                ra.append(idx)
            i -= 1
            
        for pid in ra:
            rv[pid] = True

    ri = [i for i in range(n) if not rv[i]]
    p0, p1, p2 = pa[ri[0]], pa[ri[1]], pa[ri[2]]
    
    return abs((p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1]))
