'''
https://codeforces.com/problemset/submission/367/317700625
'''
# sliding window
def solve(n: int, m: int, p: int, a: list[int], b: list[int]) -> list[int]:
    cb = Counter(b)
    nb = len(cb)
    ans = []
    for s in range(p):
        if s + (m - 1) * p < n:
            ndiff = nb
            ca = Counter()
            i = s
            for j in range(s, n, p):
                x = a[j]
                ca[x] += 1
                if ca[x] == cb[x]:
                    ndiff -= 1
                elif ca[x] == cb[x] + 1:
                    ndiff += 1
                if j >= m * p:
                    y = a[i]
                    i += p
                    ca[y] -= 1
                    if ca[y] == cb[y]:
                        ndiff -= 1
                    elif ca[y] == cb[y] - 1:
                        ndiff += 1
                if ndiff == 0:
                    ans.append(i + 1)
        else:
            break
    ans.sort()
    return ans
