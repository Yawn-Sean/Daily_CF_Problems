def main():
    n, q = map(int, input().split())
    s = input()
    Pr0 = [0] * (n+1)
    Pr1 = [0] * (n+1)
    for i, x in enumerate(s):
        Pr0[i+1] = Pr0[i] + (x == '0')
        Pr1[i+1] = Pr1[i] + (x == '1')

    mod = int(1e9+7)
    while q:
        q -= 1
        l, r = map(int, input().split())
        c0, c1 = Pr0[r] - Pr0[l-1], Pr1[r] - Pr1[l-1]
        ans1 = pow(2, c1, mod)-1
        ans2 = ans1 * (pow(2, c0, mod)-1) % mod
        ans1 += ans2
        if ans1 >= mod: ans1 -= mod

        print(ans1)
