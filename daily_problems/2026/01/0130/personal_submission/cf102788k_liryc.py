'''
https://codeforces.com/gym/102788/submission/360671636
'''
def solve(n: int, m: int, sa: list[str]) -> int: 
    arr = []
    def make(s):
        x = 0
        a, c, b = 'A', 'C', 'B'
        for d in reversed(s):
            if d == b:
                x = x << 1 | 1
                a, c = c, a
            else:
                x <<= 1
                c, b = b, c
        return x
    arr = [make(s) for s in sa]
    i = 0
    for j in range(1, m):
        if arr[j] > arr[i]:
            i = j
    return i + 1    
