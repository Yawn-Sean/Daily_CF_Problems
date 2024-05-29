"""
question: https://codeforces.com/problemset/problem/1148/C
submission: https://codeforces.com/contest/1148/submission/263079498
"""

n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
idx = {x: i for i, x in enumerate(a)}
def op(i: int, j: int): 
    # i < j, a[j] <-> a[i]
    if j - i >= n // 2: 
        res = [f'{i + 1} {j + 1}']
    elif j < n // 2 or i >= n // 2: 
        tar = n - 1 if j < n // 2 else 0
        res = [f'{j + 1} {tar + 1}', f'{i + 1} {tar + 1}', f'{j + 1} {tar + 1}']
    else:
        res = [f'{i + 1} {n}', f'{j + 1} 1', f'1 {n}', f'{i + 1} {n}', f'{j + 1} 1']
    a[i], a[j] = a[j], a[i]
    idx[a[i]] = i 
    idx[a[j]] = j 
    return res
ans = []
for i in range(n):
    if a[i] != i: 
        ans.extend(op(i, idx[i]))
fin = len(ans)
print(fin)
if fin: 
    print('\n'.join(ans))
