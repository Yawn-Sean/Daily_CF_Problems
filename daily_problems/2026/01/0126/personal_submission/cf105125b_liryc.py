'''
https://codeforces.com/gym/105125/submission/359924034
'''
def solve(n: int, a: list[int]) -> list[int]:
    s1 = sum(a)
    s2 = sum(x - 1 if x > 0 else 0 for x in a)
    if not s1 & 1 or s2 < s1 - s2 - 1: 
        return []
    si = [i for i in range(n) if a[i]]
    si.sort(key = lambda i: a[i])
    b, ans, p, flip = [], [], 0, 1
    for _ in range(sum(a)):
        while p < len(si) and a[si[p]] == 1:
            b.append(si[p])
            p += 1
        if flip and b:
            idx = b.pop()
            a[idx] -= 1
            ans.append(idx + 1)
        else:
            a[si[p]] -= 1
            ans.append(si[p] + 1)
        flip ^= 1
    return ans
    