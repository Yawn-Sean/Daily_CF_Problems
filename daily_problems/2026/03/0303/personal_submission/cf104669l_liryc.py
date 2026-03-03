'''
2026.3.3 Y1 1700
'''
def solve(a: int, b: int) -> int: 
    sm = (2 * a + b - 1) * b // 2
    def check(x):
        for i in range(1, b):
            l = a * i + i * (i - 1) // 2
            r = a * i + (2 * b - 1 - i) * i // 2
            if r // x * x >= l: 
                return True
        return False
    ans = 0
    for i in range(1, 10 ** 5 * 2):
        if i * i > sm: 
            break
        if sm % i == 0:
            if check(i): 
                ans = max(ans, i)
            if check(sm // i): 
                ans = max(ans, sm // i)
    return ans