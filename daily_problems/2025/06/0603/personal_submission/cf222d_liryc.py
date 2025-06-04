'''
https://codeforces.com/problemset/submission/222/322605182
'''
# greedy
def solve(n: int, x: int, a: list[int], b: list[int]) -> list[int]:
    a.sort(reverse=True)
    b.sort(reverse=True)
    j = n - 1
    k = 0
    for i in range(n):
        while 0 <= j and a[i] + b[j] < x: 
            j -= 1
        if 0 <= j:
            k += 1
            j -= 1
        else:
            break
    return [1, k]
