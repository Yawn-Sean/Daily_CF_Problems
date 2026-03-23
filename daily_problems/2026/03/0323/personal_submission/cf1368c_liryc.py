'''
https://codeforces.com/problemset/submission/1368/367836252
'''
def solve(n: int) -> list[list[int]]: 
    a = []
    for i in range(-1, n):
        a.append([i, i])
        a.append([i, i + 1])
        a.append([i + 1, i])
    a.append([n, n])
    return a
