'''
https://codeforces.com/problemset/submission/599/318181468
'''
# sorting
def solve(n: int, a: list[int]):
    b = [(x, i) for i, x in enumerate(a)]
    b.sort()
    for j, (x, i) in enumerate(b):
        a[i] = j
    ans, j = 0, 0
    for i in range(n):
        j = max(j, a[i]) 
        if i == j:
            ans += 1
    return ans