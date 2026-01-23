'''
https://codeforces.com/gym/105803/submission/359318278
'''
def solve(n: int, k: int, a: list[int]) -> int:
    pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y
    if k == n - 1:
        cn = [0] * n
        for x in a:
            cn[x % n] += 1
        s, c = 0, 0
        for r in range(n):
            if cn[r]:
                s += r * cn[r]
                c += cn[r]
        rs, rc = 0, 0
        ans = -1
        for r in range(n - 1, -1, -1):
            if cn[r]:
                ans = pmin(ans, r * c - s + rs + r * rc)
                s, c = s - r * cn[r], c - cn[r]
                rs += (-r % n) * cn[r]
                rc += cn[r]
        return ans
    else:
        return -sum(a) % n
