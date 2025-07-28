'''
https://codeforces.com/problemset/submission/207/330747001
'''
def solve(n: int, a: list[int]) -> int:
    m = n << 1
    a *= 2
    b = [0 if i < x else i - x for i, x in enumerate(a)]
    st = SparseTable([x << 19 | i for i, x in enumerate(b)]) # DO NOT use tuple, will TLE
    nth = [[0] * m for _ in range(20)]
    
    MSK = (1 << 19) - 1
    for i in range(m):
        nth[0][i] = st.query(b[i], i) & MSK
    
    for i in range(1, 20):
        for j in range(m):
            nth[i][j] = nth[i - 1][nth[i - 1][j]]
    
    ans = 0
    
    for i in range(n, m):
        if i - b[i] >= n - 1:
            ans += 1
            continue
        
        c = i
        for j in range(19, -1, -1):
            if i - b[nth[j][c]] < n - 1:
                ans += 1 << j
                c = nth[j][c]
        ans += 2
    
    return ans
