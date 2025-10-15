'''
https://codeforces.com/gym/106068/submission/338917208
'''
# implementation

# type 1 query
def solve1(n: int, a: list[int], i: int, val: int):
    a[i - 1] = val

# type 2 query
def solve2(n: int, a: list[int], i: int) -> int:
    if i - 1 >= 1000:
        return 1
    elif n - i >= 1000:
        return n
    else:
        for j in range(1, n + 1):
            if abs(i - j) ** 3 >= a[j - 1]:
                return j
    return -1
