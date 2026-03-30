# Submission link: https://codeforces.com/gym/106443/submission/368850406
def main(): 
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        if y - x >= 0:
            xs.append(y - x)
            ys.append(y + x)
    
    n = len(xs)
    
    st_range = list(range(n))
    
    st_range.sort(key=lambda x: ys[x])
    st_range.sort(key=lambda x: xs[x])
    
    lis = []
    
    for i in st_range:
        if len(lis) == 0 or lis[-1] <= ys[i]:
            lis.append(ys[i])
        else:
            lis[bisect.bisect_right(lis, ys[i])] = ys[i]
    
    print(len(lis))