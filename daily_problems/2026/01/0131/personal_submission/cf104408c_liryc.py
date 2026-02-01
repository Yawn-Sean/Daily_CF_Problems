'''
https://codeforces.com/gym/104408/submission/360789938
'''
def solve(n: int, m: int, a: list[list[int]]) -> int:
    flip = [0] * n
    ans = 0
    for j in range(m - 1, -1, -1):
        c0, c1 = 0, 0
        for i in range(n):
            if a[i][j] ^ flip[i] == 0:
                c0 += 1
            else:
                c1 += 1
        fc = 1 if c1 < c0 else 0
        ans += c1 if c1 < c0 else c0
        for i in range(n):
            if a[i][j] ^ flip[i] == fc:
                flip[i] ^= 1
    return ans
