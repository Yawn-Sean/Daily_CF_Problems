'''
https://codeforces.com/gym/106511/submission/373282222
'''
def solve(n: int, m: int) -> int:
    if n == 1 and m == 1: 
        return 1
    elif n == 1 or m == 1: 
        return 2
    elif n != m:
        return 4
    else:
        return 8