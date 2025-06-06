'''
https://codeforces.com/problemset/submission/685/320743567
'''
# enumerate all permutations
def solve(n: int, m: int) -> int:
    def tobase7(x):
        if x == 0: 
            return [0]
        nums = []
        while x:
            x, y = divmod(x, 7)
            nums.append(y)
        return nums
    a, b = tobase7(n - 1), tobase7(m - 1)
    le = len(a) + len(b)
    if le > 7:
        return 0
    
    def check(p):
        nonlocal a, b
        ok = False
        for i, x in enumerate(p):
            if i < len(a):
                if ok:
                    continue
                j = len(a) - 1 - i
                if x < a[j]:
                    ok = True
                elif x > a[j]:
                    return False
            else:
                j = len(b) - 1 - (i - len(a))
                if x < b[j]:
                    return True
                elif x > b[j]:
                    return False
        return True
    return sum(check(p) for p in permutations(range(7), le))
