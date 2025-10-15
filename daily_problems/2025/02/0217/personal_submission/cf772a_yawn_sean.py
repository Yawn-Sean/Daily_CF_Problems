# Submission link: https://codeforces.com/contest/772/submission/306465346
def main():
    n, p = MII()
    power = []
    stored = []

    for _ in range(n):
        a, b = MII()
        power.append(a)
        stored.append(b)

    def cmp(x, y):
        v1 = power[y] * stored[x]
        v2 = power[x] * stored[y]
        if v1 < v2: return -1
        if v1 > v2: return 1
        return 0

    st_range = sorted(range(n), key=cmp_to_key(cmp))

    cur_x, cur_y = 0, -p
    for i in st_range:
        if cur_y <= 0 or cur_x * power[i] > cur_y * stored[i]:
            cur_x += stored[i]
            cur_y += power[i]

    if cur_y <= 0: print(-1)
    else: print(cur_x / cur_y)