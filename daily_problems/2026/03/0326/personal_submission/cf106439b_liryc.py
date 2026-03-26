'''
https://codeforces.com/gym/106439/submission/368153563
'''
# permutations, simple math
def solve(n: int):
    r = n % 5
    if n == 1:
        yield 1
    elif n == 2 or n == 3:
        yield -1
    elif r == 0 or r == 1:
        a = [1, 3, 5, 2, 4]
        for i in range(n):
            yield i // 5 * 5 + a[i % 5]
    elif r == 2 or r == 3:
        a1 = [1, 3, 5, 2, 4]
        a2 = [1, 3, 5, 2, 7, 4, 6, 8]
        for i in range(n - r - 5):
            yield i // 5 * 5 + a1[i % 5]
        for i in range(n - r - 5, n):
            yield n - r - 5 + a2[i + r + 5 - n]
    else: 
        a1 = [1, 3, 5, 2, 4]
        a2 = [2, 4, 1, 3]
        for i in range(n - r):
            yield i // 5 * 5 + a1[i % 5]
        for i in range(n - r, n):
            yield i // 5 * 5 + a2[i % 5]
