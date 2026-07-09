'''
https://codeforces.com/gym/106054/submission/381798600
cases
'''
def solve(t: int, sc: list[list[int]], dc: list[list[int]]) -> bool:
    if Counter(chain(*sc)) != Counter(chain(*dc)):
        return False
    elif t == 1:
        return True
    elif t == 2:
        return sc[0] + sc[1][::-1] == dc[0] + dc[1][::-1]
    else:
        return True
