'''
https://codeforces.com/gym/100488/submission/341166084
'''
def query(l: int, r: int) -> list[int]:
    print('Q', l, r, flush=True)
    return list(map(int, input().split()))    

def solve(n: int) -> list[int]:
    ans = [0] * n
    ss = set(range(1, n + 1))
    
    if n & 1:
        qa = query(n, n)
        x = qa[0]
        ans[n - 1] = x
        ss.remove(x)
        n -= 1
    
    if n:
        ls = set(query(1, n // 2))
        rs = ss - ls
        
        for i in range(2, n // 2 + 1):
            ms = set(query(i, n + 1 - i))
            ans[i - 2] = (ls - ms).pop()
            ans[n - i + 1] = (rs - ms).pop()
            ls &= ms
            rs &= ms
        
        ans[n // 2 - 1] = ls.pop()
        ans[n // 2] = rs.pop()
    
    return ans
