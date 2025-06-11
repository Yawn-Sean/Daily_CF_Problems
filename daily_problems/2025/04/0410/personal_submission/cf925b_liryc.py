'''
https://codeforces.com/problemset/submission/925/314825222
'''
def solve(n: int, x1: int, x2: int, ca: list[int]) -> list[list[int]]:
    sa = sorted(range(n), key=lambda x: ca[x])
    for i in range(n):
        c1 = (x1 + ca[sa[i]] - 1) // ca[sa[i]]
        if i + c1 < n and ca[sa[i + c1]] * (n - i - c1) >= x2:
            return [sa[i:i + c1], sa[i + c1:]]
        c2 = (x2 + ca[sa[i]] - 1) // ca[sa[i]]
        if i + c2 < n and ca[sa[i + c2]] * (n - i - c2) >= x1:
            return [sa[i + c2:], sa[i:i + c2]]
    return []

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print("Yes")
        print(len(ans[0]), len(ans[1]))
        print(*(x + 1 for x in ans[0]))
        print(*(x + 1 for x in ans[1]))
    else:
        print("No")