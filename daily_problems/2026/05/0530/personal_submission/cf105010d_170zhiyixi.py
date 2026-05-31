def solve():
    [n, k] = LI()
    a = [0] + LI()
    ans0 = 0
    ans1 = 0
    for i in range(1, n + 1):
        if a[i] % k == 0:
            ans0 += 1
        else:
            ans1 += 1
    if ans0 == n:
        print("Rami")
        return 0
    if ans1 == 2:
        print("Oussama")
        return 0
    if ((ans0 + ans1) % 2 == 0):
        print("Oussama")

    else:
        print("Rami")
