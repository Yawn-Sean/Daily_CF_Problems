'''
https://codeforces.com/problemset/submission/81/336833550
'''
# sorting
def solve(n: int, a: int, b: int, t: list[int]) -> list[int]:
    if a == b:
        return [1] * a + [2] * b
    si = sorted(range(n), key=lambda i: t[i]) if a > b else sorted(range(n), key=lambda i: -t[i])
    ans = [2] * n
    for i in si:
        if a:
            ans[i] = 1
            a -= 1
        else:
            break
    return ans
