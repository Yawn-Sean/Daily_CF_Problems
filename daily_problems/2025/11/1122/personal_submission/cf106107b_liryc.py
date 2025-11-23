'''
https://codeforces.com/gym/106107/submission/350148852
'''
# range, two pointers, counter, fenwick tree
def solve(n: int, a: list[int], b: list[int]) -> int:
    ans = 0
    cn = Counter()
    ra = [-1] * n
    for i in range(n):
        x, y = a[i], b[i]
        cn[y] = i
        if x in cn:
            ra[i] = cn[x] 
    cn.clear()
    la = [-1] * n
    for i in range(n - 1, -1, -1):
        x, y = a[i], b[i]
        cn[y] = i
        if x in cn:
            la[i] = cn[x]
    si = list(sorted(range(n), key = lambda i: la[i]))
    ft = FenwickTree(n + 1)
    j = n - 1
    for i in range(n - 1, -1, -1):
        ft.add(ra[i] + 1)
        while j >= 0 and la[si[j]] == i:
            ans += ft.sum(si[j])
            j -= 1
    return ans
