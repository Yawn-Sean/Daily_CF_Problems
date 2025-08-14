'''
https://codeforces.com/problemset/submission/148/333933072
'''
# constructive, greedy
def solve(n: int, a: int, b: int) -> list[int]:
    if n == 1:
        return [1]
    elif a == n - 1:
        return [-1]
    elif n == 2:
        return [1, 2] if b > 0 else [1, 1]
    else:
        ans = [1, 2] if b > 0 else [1, 1]
        if b > 0:
            b -= 1
        for _ in range(n - 2):
            if b > 0:
                ans.append(sum(ans) + 1)
                b -= 1
            elif a > 0:
                ans.append(ans[-1] + 1)
                a -= 1
            else:
                ans.append(1)
    return ans
