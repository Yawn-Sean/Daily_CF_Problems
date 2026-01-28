'''
https://codeforces.com/gym/105198/submission/360259875
'''
def solve(s_x: int, s_y: int, t_x: int, t_y: int, k: int) -> int:
    d_x = abs(s_x - t_x)
    d_y = abs(s_y - t_y)
    if d_x < d_y: 
        d_x, d_y = d_y, d_x
    if d_x <= k * (d_y + 1):
        return d_x + d_y
    else:
        a = (d_x - (d_y + 1) * k + 2 * k - 1) // (2 * k) * 2
        return d_x + d_y + a
   