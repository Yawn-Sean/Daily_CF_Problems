'''
https://codeforces.com/gym/106174/submission/347974963
'''
# binary search

# total digits of 1..n
def digits(n: int) -> int:
    b, ans = 1, 0
    while n >= b:
        ans += n - b + 1
        b *= 10
    return ans

def solve(n: int, k: int) -> int:
    def check(m):
        nonlocal n
        if m == 0:
            return 0
        return digits(m + n - 1) - digits(m - 1)
    
    f = bisect_left(range(10 ** 18), k, key=check)
    if f and check(f) == k:
        return f
    else: 
        return -1

