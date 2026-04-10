# Submission link: https://codeforces.com/gym/105709/submission/370541070
def main(): 
    n, k = MII()
    bs = LII()
    ws = LII()
    vs = LII()
    
    tmp = [[] for _ in range(k)]
    
    for i in range(n):
        if bs[i] + ws[i] <= k:
            tmp[bs[i]].append(i)
    
    fen = FenwickTree(k)
    ans = 0
    
    for i in range(1, k):
        for idx in tmp[i]:
            fen.add(ws[idx], vs[idx])
        ans = fmax(ans, fen.rsum(0, k - i))
    
    print(ans)