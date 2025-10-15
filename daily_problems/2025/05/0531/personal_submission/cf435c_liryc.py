'''
https://codeforces.com/problemset/submission/435/322185879
'''
# plot
def solve(n: int, a: list[int]) -> tuple[int, list[list[int]]]:
    hi = 0
    flip = 0
    x, y = 0, 0
    for c in a:
        flip ^= 1
        y = y + c if flip else y - c
        hi = max(hi, y)
    y = hi - 1
    ans = [[] for _ in range(hi)]
    flip = 0
    for c in a:
        flip ^= 1
        inc = -1 if flip else 1
        for _ in range(c):
            if y == len(ans):
                ans.append([])
            ans[y].append(x if flip else ~x)
            x += 1
            y += inc
        y -= inc
    return x, ans

def print_ans(maxx: int, a: list[list[int]]):
    for r in a:
        c = 0
        for x in r:
            b = ~x if x < 0 else x
            if b > c:
                print(' ' * (b - c), end='')
                c = b
            print(('/' if x >= 0 else '\\'), end='')
            c += 1
        if c < maxx:
            print(' ' * (maxx - c)) 
        else:
            print()
