# Submission link: https://codeforces.com/gym/102911/submission/369458133
def main(): 
    n = II()
    v1 = LII()
    v2 = LII()
    
    st_range = sorted(range(n), key=lambda x: v1[x])
    
    fen = FenwickTree(n)
    
    ans = 0
    for i in st_range:
        ans += fen.rsum(i, n - 1) * v2[i]
        fen.add(i, v2[i])
    
    print(ans)