# Submission link: https://codeforces.com/contest/1068/submission/292549690
def main():
    n, m = MII()
    pts = [[] for _ in range(n + 1)]

    for i in range(1, n + 1):
        pts[i].append(f'{i} {i}')

    for i in range(m):
        u, v = MII()
        pts[u].append(f'{n + 2 * i + 1} {u}')
        pts[u].append(f'{n + 2 * i + 1} {n + i + 1}')
        pts[v].append(f'{n + 2 * i + 2} {v}')
        pts[v].append(f'{n + 2 * i + 2} {n + i + 1}')

    for i in range(1, n + 1):
        print(len(pts[i]))
        print('\n'.join(pts[i]))