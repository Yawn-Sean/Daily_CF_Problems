'''
https://codeforces.com/gym/106394/submission/370508619
'''
# greedy
def solve(n: int, a: list[int]) -> int:
    i, hp, ans, max_p = 0, 0, 0, a[0]
    while i < n - 1:
        ans += 1
        if hp:
            hp -= 1
            i += 1
            max_p = max(max_p, a[i])
        else:
            hp += max_p
    return ans

