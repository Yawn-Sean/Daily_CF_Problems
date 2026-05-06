'''
https://codeforces.com/gym/106414/submission/373639555
'''
def solve(n: int, pa: list[list[int]]) -> list[list[int]]:
    dyx = defaultdict(list)
    for x, y in pa:
        dyx[y].append(x)

    ys = list(sorted(dyx.keys(), reverse=True))
    for y in ys:
        dyx[y].sort() 
    ans = []
    xc = 200000000 
    y0 = ys[0] + 1
    
    for i, y in enumerate(ys):
        xs = dyx[y]
        yp = ys[i - 1] if i > 0 else y0
        
        if i > 0:
            ans.append([xc, yp])
            xc += 1
            
        for j, x in enumerate(xs):
            ans.append([x, y])
            if j < len(xs) - 1:
                ans.append([xc, yp])
                xc += 1
                
    y1 = ys[-1]
    ans.append([xc + 1, y1 - 1])     
    ans.append([xc + 2, y0 + 2])     
    ans.append([-200000000, y0 + 2]) 

    return ans
