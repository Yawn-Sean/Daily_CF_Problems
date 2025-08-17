'''
https://codeforces.com/problemset/submission/518/334148672
'''
# arrays, brute-force
def solve(n: int, m: int, k: int, a: list[int], b: list[int]) -> int:
    pos = [0] * n
    for i in range(n):
        a[i] -= 1
        pos[a[i]] = i
    ans = 0
    for bx in b:
        x = bx - 1
        i = pos[x]
        ans += i // k + 1 
        if i:
            a[i], a[i - 1] = a[i - 1], a[i]
            pos[a[i - 1]], pos[a[i]] = i - 1, i
    return ans
