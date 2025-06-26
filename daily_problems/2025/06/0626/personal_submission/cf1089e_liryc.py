'''
https://codeforces.com/contest/1089/submission/326148487
'''
# discuss cases
def solve(n: int) -> list[str]:
    n += 1
    make = lambda row, col: f"{chr(97 + col)}{row}"
    ans = []
    i, j, inc = 1, -1, 1
    for _ in range(n - 2):
        if n >= 58 and i == 6 and j == 2:
            j = 0
            inc = 1
        elif n >= 58 and i == 6 and j == 1:
            i += 1
        elif n >= 58 and i == 7 and j == 7:
            j = 0
        elif n >= 58 and i == 7 and j == 0:
            i += 1
        elif j == 0 and inc == -1:
            i += 1
            inc = 1
        elif j == 7 and inc == 1:
            i += 1
            inc = -1
        else:
            j += inc
        ans.append(make(i, j))

    if i == 8:
        ans.append(make(8, 6))
    elif j == 7:
        ans.append(make(7, 7))
    else:
        ans.append(make(8, j))

    ans.append(make(8, 7))
    return ans

