'''
https://codeforces.com/gym/103059/submission/362210268
'''
def solve(n: int) -> list[int]:
    if n == 1:
        return [1]
    elif n == 4:
        return [1, 3, 2, 4]
    elif not isPrime(n):
        return [-1]
    fac = Factorial(n - 1, n)
    ans = [1]
    for m in range(2, n):
        ans.append(m * fac.inv(m - 1) % n)
    ans.append(n)
    return ans
