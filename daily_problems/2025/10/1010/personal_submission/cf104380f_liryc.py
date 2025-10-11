'''
https://codeforces.com/gym/104380/submission/342846599
'''
def solve(n: int, l: int, r: int, a: list[int]) -> int:
    return sum(nlargest(r - l + 1, a[:n - min(l - 1, n - r)])) 
