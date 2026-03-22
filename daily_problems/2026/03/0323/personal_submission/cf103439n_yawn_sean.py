# Submission link: https://codeforces.com/gym/103439/submission/367775964
def main(): 
    n = II()
    
    xs = []
    ys = []
    
    for _ in range(n * 2):
        x, y = MII()
        if x > y: x, y = y, x
        xs.append(x)
        ys.append(y)
    
    st_range = sorted(range(2 * n), key=lambda i: xs[i] + ys[i])
    
    print(sum(ys[st_range[2 * n - 1 - i]] - xs[st_range[i]] for i in range(n)))