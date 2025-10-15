# Submission link: https://codeforces.com/contest/141/submission/320445465
def main():
    n = II()
    strs = []
    vals = []

    for _ in range(n):
        s, v = LI()
        v = int(v)
        
        strs.append(s)
        vals.append(v)

    order = sorted(range(n), key=lambda x: vals[x])

    tmp = []
    heights = [-1] * n

    cur = n

    for i in order:
        heights[i] = cur
        cur -= 1
        
        if vals[i] > len(tmp):
            exit(print(-1))
        
        ntmp = []
        
        for j in range(vals[i]):
            ntmp.append(tmp[j])
        
        ntmp.append(i)
        
        for j in range(vals[i], len(tmp)):
            ntmp.append(tmp[j])
        
        tmp = ntmp

    print('\n'.join(f'{strs[i]} {heights[i]}' for i in tmp))