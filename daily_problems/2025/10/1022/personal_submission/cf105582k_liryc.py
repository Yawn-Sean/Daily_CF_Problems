'''
https://codeforces.com/gym/105582/submission/345780752
'''
# scale of 3-4-5 triangle
# 奇数的想不到，从样例1那里照搬的
def solve(n: int) -> list[list[int]]:
    if n == 3:
        return [[0, 0], [4, 3], [-20, 21]]
    elif n == 4:
        return [[0, 3], [4, 0], [0, -3], [-4, 0]]

    pa = [[0, 0]]
    x, k = 0, 0
    for _ in range(n // 2 - 1):
        pa.append([x + 9, 12])
        pa.append([x + 25, 0])
        x += 25
        k += 1
    pa.append([16 * k, -12 * k])
    if n & 1:
        pa.append([-80 * k, -84 * k])
    return pa
