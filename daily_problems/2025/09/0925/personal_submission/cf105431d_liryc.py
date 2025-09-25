'''
https://codeforces.com/gym/105431/submission/340353613
'''

def solve(n: int, k: int, a: list[int], b: list[int]) -> int:
    bp = [[] for _ in range(n + 1)]
    
    for i, x in enumerate(b):
        bp[x].append(i)
    
    mft = MaxFenwickTree(n * k + 1) # MaxFenwickTree from YawnSean
    
    for i, x in enumerate(a):
        for j in bp[x][::-1]:
            mft.set(j + 1, mft.prefmax(j) + 1)
    
    return mft.prefmax(n * k)

