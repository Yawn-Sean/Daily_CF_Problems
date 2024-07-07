# Submission Link: https://codeforces.com/contest/1085/submission/267585196
def main():
    n, s = MII()
    degs = [0] * n

    for _ in range(n - 1):
        u, v = GMI()
        degs[u] += 1
        degs[v] += 1

    print(2 * s / degs.count(1))