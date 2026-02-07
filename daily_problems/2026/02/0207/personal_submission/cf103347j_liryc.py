'''
https://codeforces.com/gym/103347/submission/361843769
'''
def solve(p: int, x: int, y: int, a: int) -> int: 
    ma = [1]
    for _ in range(p):
        r = ma[-1] * x % p
        if r == 1:
            break
        else:
            ma.append(r)
    n = len(ma)
    ia = [-1] * p
    
    for i in range(n):
        ia[ma[i]] = i
    
    ans = 0
    for i in range(1, p):
        v = pow(i, -1, p) * y % p
        if ia[v] >= 0:
            j = ia[v]
            res = ((j - i) * p + i) % (n * p)
            ans += (a - res) // (n * p) + 1
    return ans