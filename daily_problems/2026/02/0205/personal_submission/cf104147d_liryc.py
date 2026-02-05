'''
https://codeforces.com/gym/104147/submission/361483579
'''
def solve(n: int, k: int) -> bool:
    m = n * k % (k + 1)
    return (m & 1) or m == k
