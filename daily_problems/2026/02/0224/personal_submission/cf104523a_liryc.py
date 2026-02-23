'''
https://codeforces.com/gym/104523/submission/364044137
'''
# binary search
def cascading_sum(x):
    y = 0
    while x:
        y += x
        x //= 10        
    return y

def solve(n: int) -> int:
    m = bisect_right(range(n + 1), n, key=cascading_sum) - 1
    return n - m
