'''
https://codeforces.com/gym/100488/submission/341003623
'''
# 反悔贪心
def solve(n: int, a: list[int]) -> list[int]:
    ja, fe = [], 0
    for i, x in enumerate(a):
        if i & 1: # Ferrante's turn
            fe += heappushpop(ja, x)
        else: # Jack's turn
            heappush(ja, x)
    return [sum(ja), fe]
