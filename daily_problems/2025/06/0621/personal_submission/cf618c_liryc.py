'''
https://codeforces.com/problemset/submission/618/325456630
'''
# constructive

# actually 2 \times area
def calculate_triangle_area(x1, y1, x2, y2, x3, y3):
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))

def solve(n: int, a: list[list[int]]) -> list[int]:
    ia, ib, ic = 0, -1, -1

    for i in range(1, n):
        if a[i][0] < a[ia][0]:
            ia = i

    min_dist = -1
    for i in range(n):
        if i != ia:
            d = (a[i][0] - a[ia][0]) ** 2 + (a[i][1] - a[ia][1]) ** 2
            if ib < 0 or d < min_dist:
                ib, min_dist = i, d

    min_area = -1
    for i in range(n):
        if ia != i != ib:
            area = calculate_triangle_area(a[i][0], a[i][1], a[ia][0], a[ia][1], a[ib][0], a[ib][1])
            if area > 0 and (ic < 0 or area < min_area):
                ic, min_area = i, area

    return [ia + 1, ib + 1, ic + 1]
