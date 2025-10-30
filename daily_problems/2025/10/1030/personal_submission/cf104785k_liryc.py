'''
https://codeforces.com/gym/104785/submission/346559091
'''

def solve(n: int, m: int, a: list[list[int]]) -> list[int]:
    asc, des = [], []
    for i, (x, y) in enumerate(a):
        if x < y:
            asc.append(i + 1)
        else:
            des.append(i + 1)
    return asc if len(asc) > len(des) else des
