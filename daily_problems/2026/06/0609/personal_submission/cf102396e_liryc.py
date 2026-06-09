'''
https://codeforces.com/gym/102396/submission/377851658
'''
def solve(n: int, a: list[int]) -> tuple[int, list[int]]:
    ans = [0] * n
    m = 0
    hp = n - 1
    for i in range(n):
        if a[i] != 0:
            ans[i] = a[i] << hp
            m += 1 << hp
            hp -= 1
    for i in range(n):
        if a[i] == 0:
            ans[i] = 1 << hp
            hp -= 1
    return m, ans
