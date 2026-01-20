'''
https://codeforces.com/gym/105813/submission/358942268
'''
# ref
def solve(a: int, b: int, n: int) -> bool:    
    if n > a + ((b << 1) - 1 << 1):
        return False
    elif n <= a + (b - 1 << 1): 
        return True
    return n >= 3 * a 
    