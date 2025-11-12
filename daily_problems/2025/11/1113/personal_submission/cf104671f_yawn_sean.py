# Submission link: https://codeforces.com/gym/104671/submission/348630997
def main(): 
    n, k, q = MII()
    nums = LII()
    
    tmp = [-1] * n
    
    for i in range(n):
        if nums[i] & k == k:
            tmp[i] = nums[i] - k
    
    seg = SegTree(iand, -1, tmp)
    
    outs = []
    for _ in range(q):
        l, r = GMI()
        outs.append('NO' if seg.prod(l, r + 1) else 'YES')
    
    print('\n'.join(outs))