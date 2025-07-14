'''
https://codeforces.com/problemset/submission/285/328837279
'''
lookup = [0, 1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0]

def solve(n: int):
    global lookup
    return lookup[n] * factorial(n) % 1000000007
