'''
https://codeforces.com/gym/103114/my#
'''
def solve(n: int) -> list[int]:
    idx = [0] * (n + 1)
    
    for i in range(10):
        b = []
        for j in range(1, n + 1):
            if j & 1 << i:
                b.append(j)
        
        if len(b):
            print(len(b), *b, flush=True)            
            for v in map(int, input().split()):
                idx[v] |= 1 << i
    
    ans = [0] * n
    for i in range(n + 1):
        if idx[i]:
            ans[idx[i] - 1] = i
    return ans
