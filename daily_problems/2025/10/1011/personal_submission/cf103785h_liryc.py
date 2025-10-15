'''
https://codeforces.com/gym/103785/submission/343072941
'''
def solve(n: int, a: list[int]) -> list[int]:
    ans = []
    for i in range(n - 1, -1, -1):
        for j in range(i, -1, -1):
            if a[j] == j + 1:
                ans.append(a.pop(j))
                break
        else:
            return []
    return ans[::-1]
