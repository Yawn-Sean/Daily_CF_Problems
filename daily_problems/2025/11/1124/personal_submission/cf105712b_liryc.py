'''
https://codeforces.com/gym/105712/submission/350448768
'''
def solve(n: int, a: list[int]) -> int:
    begin, end = sum(a), 1
    maxnum = max(a)
    if maxnum <= 1: 
        return 0
    elif maxnum == begin == 3:
        end = 2
    elif n == 2:
        x, y = a
        x, y = (x - 1) % 3 + 1, (y - 1) % 3 + 1
        if x == y:
            end = 2
    return begin - end
