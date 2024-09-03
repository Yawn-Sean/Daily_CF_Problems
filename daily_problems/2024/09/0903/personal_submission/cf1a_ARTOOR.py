import random
def generate_permutation(n, k):
    if k < 1 or k > 2*n-1:
        return [-1]
    if k == 1:
        return list(range(1, n+1))
    arr = list(range(1, n+1))
    elements_to_reverse = n - (k-1)//2
    arr[:elements_to_reverse] = arr[:elements_to_reverse][::-1]
    return arr

def solve(n, k):
    result = generate_permutation(n, k)
    if result == [-1]:
        print(-1)
    else:
        print(*result)
n, k = map(int, input().split())
solve(n, k)
