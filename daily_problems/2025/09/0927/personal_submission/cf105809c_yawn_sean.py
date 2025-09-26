# Submission link: https://codeforces.com/gym/105809/submission/340606247
def main():
    a, b, c = MII()
    blocked = [0] * (a * b * c)
    
    def f(x, y, z):
        return (x * b + y) * c + z
    
    k = II()
    for _ in range(k):
        x, y, z = GMI()
        blocked[f(x, y, z)] = 1
    
    mf = MFGraph(a * b * c + 2)
    dirs = []
    
    for i in range(-2, 3):
        for j in range(-2, 3):
            if abs(i) + abs(j) == 3:
                dirs.append((0, i, j))
                dirs.append((i, 0, j))
                dirs.append((i, j, 0))
    
    cnt = a * b * c
    
    src = a * b * c
    dst = src + 1
    
    for i in range(a):
        for j in range(b):
            for k in range(c):
                if not blocked[f(i, j, k)]:
                    if (i + j + k) % 2 == 0:
                        mf.add_edge(src, f(i, j, k), 1)
                        for di, dj, dk in dirs:
                            ni = i + di
                            nj = j + dj
                            nk = k + dk
                            
                            if 0 <= ni < a and 0 <= nj < b and 0 <= nk < c and not blocked[f(ni, nj, nk)]:
                                mf.add_edge(f(i, j, k), f(ni, nj, nk), 1)
                    else:
                        mf.add_edge(f(i, j, k), dst, 1)
                else:
                    cnt -= 1
    
    print(cnt - mf.flow(src, dst))
