'''
https://codeforces.com/gym/106164/submission/374237940
'''
def solve(n: int, m: int) -> list[int]:
    if n == 2:
        if m & 1: 
            return [2, 1]
        else: 
            return [1, 2]
    else:
        m = min(n, m)
        ans = []
        
        for i in range(m):
            ans.append(n - i)
        
        for i in range(n - m):
            ans.append(i + 1)

        return ans
