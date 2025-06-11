# Submission link: https://codeforces.com/contest/487/submission/287131776
def main():
    hp1, atk1, def1 = MII()
    hp2, atk2, def2 = MII()
    h, a, d = MII()

    ans = 0

    v = fmax(0, def2 + 1 - atk1)
    atk1 += v
    ans += v * a

    cur_h1 = fmax(0, atk2 - def1)
    cur_h2 = atk1 - def2

    new_ans = cur_h1 * d
    for delta_h1 in range(cur_h1):
        for delta_h2 in range(101):
            h1 = cur_h1 - delta_h1
            h2 = cur_h2 + delta_h2
            time = (hp2 + h2 - 1) // h2
            delta_hp1 = fmax(time * h1 + 1 - hp1, 0)
            new_ans = fmin(new_ans, delta_h1 * d + delta_h2 * a + delta_hp1 * h)

    print(ans + new_ans)