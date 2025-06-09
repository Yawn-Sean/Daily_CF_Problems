# Submission link: https://codeforces.com/contest/718/submission/312503921
def main():
    n, t = MII()
    s = I()

    v1 = [0]
    v2 = [0]

    flg = True

    for c in s:
        if c == '.': flg = False
        else:
            if flg: v1.append(int(c))
            else: v2.append(int(c))

    k1 = len(v1)
    k2 = len(v2)

    for i in range(k2):
        if v2[i] >= 5:
            while i < len(v2):
                v2.pop()
            v2[-1] += 1
            t -= 1
            break

    while t and v2[-1] >= 5:
        t -= 1
        v2.pop()
        v2[-1] += 1

    v1[-1] += v2[0]
    v2[0] = 0

    while v2 and v2[-1] == 0:
        v2.pop()

    for i in range(k1 - 1, -1, -1):
        if v1[i] == 10:
            v1[i] = 0
            v1[i - 1] += 1

    print(''.join(str(v1[i]) for i in range(k1) if i or v1[i]), end='')

    if v2: print('.', ''.join(str(v2[i]) for i in range(1, len(v2))), sep='')
