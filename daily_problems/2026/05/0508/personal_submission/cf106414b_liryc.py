'''
https://codeforces.com/gym/106414/submission/373880373
cases
'''
def solve(n: int, s: str) -> bool:
    cn = Counter(s)
    if len(cn) == 1:
        return False
    elif len(cn) == 2:
        return True
    elif len(s) == 3:
        return False
    else:
        return True
