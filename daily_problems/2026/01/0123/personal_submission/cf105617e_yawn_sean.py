# Submission link: https://codeforces.com/gym/105617/submission/359173214
def main(): 
    n = II()
    nums = LII()
    
    fen = FenwickTreeArray([1] * n)
    pos = [0] * n
    
    for i in range(n - 1, -1, -1):
        pos[i] = fen.bisect_min_larger(nums[i])
        fen.add(pos[i], -1)
    
    max_fen = MaxFenwickTree(n)
    ans = 0
    outs = []
    
    for i in range(n):
        res = max_fen.prefmax(pos[i]) + 1
        ans = fmax(ans, res)
        outs.append(ans)
        max_fen.set(pos[i], res)
    
    print('\n'.join(map(str, outs)))