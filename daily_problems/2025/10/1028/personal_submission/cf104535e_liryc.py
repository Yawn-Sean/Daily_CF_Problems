'''
https://codeforces.com/gym/104535/submission/346152539
'''
def solve(n: int) -> list[list[int]]:
    return [[-1, 2], [0, 2], [n - 1, 1], [n, 0], [n - 1, 0], [0, 1]]
