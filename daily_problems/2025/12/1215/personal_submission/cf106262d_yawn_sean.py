# Submission link: https://codeforces.com/gym/106262/submission/353423405
def main(): 
    n = II()
    tots = LII()
    vals = LII()
    
    portion = [vals[i] / tots[i] for i in range(n)]
    st_range = sorted(range(n), key=lambda x: portion[x])
    
    down_xs = [0]
    down_ys = [0]
    
    for i in st_range:
        down_xs.append(down_xs[-1] + tots[i])
        down_ys.append(down_ys[-1] + vals[i])
    
    st_range.reverse()
    
    up_xs = [0]
    up_ys = [0]
    
    for i in st_range:
        up_xs.append(up_xs[-1] + tots[i])
        up_ys.append(up_ys[-1] + vals[i])
    
    pt1 = 0
    pt2 = 0
    ans = 0
    
    while pt1 < n and pt2 < n:
        l = fmax(down_xs[pt1], up_xs[pt2])
        r = fmin(down_xs[pt1 + 1], up_xs[pt2 + 1])
    
        if l < r and l > 0:
            kup = (up_ys[pt2 + 1] - up_ys[pt2]) / (up_xs[pt2 + 1] - up_xs[pt2])
            kdown = (down_ys[pt1 + 1] - down_ys[pt1]) / (down_xs[pt1 + 1] - down_xs[pt1])
            
            bup = up_ys[pt2] - kup * up_xs[pt2]
            bdown = down_ys[pt1] - kdown * down_xs[pt1]
            
            ans += (bup - bdown) * (math.log(r) - math.log(l))
        
        if down_xs[pt1 + 1] < up_xs[pt2 + 1]: pt1 += 1
        else: pt2 += 1
    
    ans /= up_xs[-1]
    
    print(ans)