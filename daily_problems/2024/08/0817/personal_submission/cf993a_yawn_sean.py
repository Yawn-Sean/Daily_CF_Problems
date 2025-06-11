# Submission link: https://codeforces.com/contest/993/submission/276854617
def main():
    s1 = LII()
    s2 = LII()

    def is_in(square1, square2):
        xl = min(square2[i] for i in range(0, 8, 2))
        xr = max(square2[i] for i in range(0, 8, 2))
        yl = min(square2[i] for i in range(1, 8, 2))
        yr = max(square2[i] for i in range(1, 8, 2))
        for i in range(4):
            if xl <= square1[i * 2] <= xr and yl <= square1[i * 2 + 1] <= yr:
                return True
        if xl * 2 <= square1[0] + square1[4] <= xr * 2 and yl * 2 <= square1[1] + square1[5] <= yr * 2:
            return True
        return False

    if is_in(s2, s1):
        print('YES')
    else:
        for i in range(4):
            s1[i * 2], s1[i * 2 + 1] = s1[i * 2] + s1[i * 2 + 1], s1[i * 2] - s1[i * 2 + 1]
            s2[i * 2], s2[i * 2 + 1] = s2[i * 2] + s2[i * 2 + 1], s2[i * 2] - s2[i * 2 + 1]
        print('YES' if is_in(s1, s2) else 'NO')