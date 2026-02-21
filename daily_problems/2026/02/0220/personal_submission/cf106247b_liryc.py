'''
https://codeforces.com/gym/106247/submission/363708305
'''
def solve(n: int) -> tuple[int, list[int]]: 
    if n == 2:
        return -1, []
    elif n == 1:
        return 1, [1]
    a = [1, 2]
    for i in range(n - 2):
        a.append(3 << i)
    return 3 << n - 2, a
