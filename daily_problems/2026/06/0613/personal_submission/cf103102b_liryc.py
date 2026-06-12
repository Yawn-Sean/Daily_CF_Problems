'''
https://codeforces.com/gym/103102/submission/378458424
'''
def solve(s: str) -> bool:
    c, r = 0, 0
    for x in s:
        if x == '1': 
            c = (c + 1) % 3
        else: 
            r = (r + c) % 3
    return r != 0