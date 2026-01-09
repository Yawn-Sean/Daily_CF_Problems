'''
https://codeforces.com/gym/106296/submission/357107027
'''
def solve(n: int) -> list[int]:
    def ask(a, b):
        print(a, b, flush=True)
        return input()

    l, r = 1, n + 1 >> 1
    while l <= r:
        m = l + r >> 1
        if ask(2, (m << 1) - 1) == ask(1, m << 1): 
            l = m + 1
        else: 
            r = m - 1
    return [3, (l << 1) - 3, (l << 1) - 1]
