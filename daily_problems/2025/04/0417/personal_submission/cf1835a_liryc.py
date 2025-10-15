'''
https://codeforces.com/problemset/submission/1835/315916953
'''
# enum + counting
def solve(a: int, b: int, c: int, k: int) -> str:
    min_a, max_a = 10 ** (a - 1), 10 ** a - 1
    min_b, max_b = 10 ** (b - 1), 10 ** b - 1
    min_c, max_c = 10 ** (c - 1), 10 ** c - 1
    for xa in range(min_a, max_a + 1):
        if xa + min_b > max_c or xa + max_b < min_c:
            continue
        lb = max(min_b, min_c - xa)
        rb = min(max_b, max_c - xa)
        n = rb - lb + 1
        if n < k:
            k -= n
        else:
            return f"{xa} + {lb + k - 1} = {xa + lb + k - 1}"
    return "-1"