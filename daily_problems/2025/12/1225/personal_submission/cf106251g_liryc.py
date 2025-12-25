'''
https://codeforces.com/gym/106251/submission/355023595
'''
def solve(n: int, b: int, a: list[int]) -> list[list[int]]: 
    ans = []
    if sum(a) % (b - 1) == 0: 
        li = []
        r = 0
        for x in a:
            r = r * b + x
            li.append(r // (b - 1))
            r %= b - 1
        ans.append([n + 2])
        ans.append([1, 0] + li)
        ans.append([1] + li + [0])    
    return ans
