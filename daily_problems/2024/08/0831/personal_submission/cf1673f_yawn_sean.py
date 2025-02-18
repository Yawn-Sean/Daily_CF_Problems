# Submission link: https://codeforces.com/contest/1673/submission/278871026
def main():
    def find_array(k):
        if k == -1: return [0]
        v = find_array(k-1)
        return v + [x ^ (1 << 2 * k) for x in reversed(v)]

    ar = find_array(4)

    n, k = MII()
    pos = [None] * 1024

    for i in range(n):
        for j in range(n):
            pos[ar[i] ^ (ar[j] * 2)] = (i + 1, j + 1)

    for _ in range(n):
        print(*((ar[i] ^ ar[i+1]) * 2 for i in range(n - 1)))

    for i in range(n - 1):
        print(*(ar[i] ^ ar[i+1] for _ in range(n)))

    sys.stdout.flush()

    msk = 0
    for _ in range(k):
        msk ^= II()
        print(*pos[msk], flush=True)
