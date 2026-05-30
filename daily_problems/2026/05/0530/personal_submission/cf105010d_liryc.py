'''
https://codeforces.com/gym/105010/submission/376595710
'''
def solve(n: int, k: int, a: list[int]) -> bool:
    if all(x % k == 0 for x in a):
        return False
    elif 2 == sum(x % k != 0 for x in a):
        return True
    else:
        return (n & 1) == 0
