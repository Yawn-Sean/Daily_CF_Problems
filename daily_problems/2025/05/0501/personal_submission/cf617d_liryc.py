'''
https://codeforces.com/problemset/submission/617/317950994
'''
def solve(a: list[list[int]]):
    if a[0][0] == a[1][0] == a[2][0] or a[0][1] == a[1][1] == a[2][1]:
        return 1
    else:
        for i in range(3):
            j = (i + 1) % 3
            k = (i + 2) % 3
            if a[j][0] == a[k][0] and not (min(a[j][1], a[k][1]) < a[i][1] < max(a[j][1], a[k][1])):
                return 2
            if a[j][1] == a[k][1] and not (min(a[j][0], a[k][0]) < a[i][0] < max(a[j][0], a[k][0])):
                return 2
    return 3
