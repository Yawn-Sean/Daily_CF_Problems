'''
https://codeforces.com/gym/106430/submission/367184724
'''
# simple math, cases
def solve(x: int, y: int):
    if y == x:
        return 0
    elif y == 1:
        return -1
    elif y == 2:
        return 1 if x == 1 else -1
    elif x < y:
        ans = 0
        while x < y:
            ans += 1
            x <<= 1
        return ans
    else: # x > y
        ans = 0
        while x > y:
            ans += 1
            x = x * 2 // 3 + 1
        return ans
