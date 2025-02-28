# Submission link: https://codeforces.com/contest/1068/submission/292550726
def main():
    n, m = MII()
    pts = [[] for _ in range(n + 1)]

    for i in range(1, n + 1):
        pts[i].append(f'{i} {i}')

    for i in range(m):
        u, v = MII()
        pts[u].append(f'{n + i + 1} {u}')
        pts[v].append(f'{n + i + 1} {v}')

    for i in range(1, n + 1):
        print(len(pts[i]))
        print('\n'.join(pts[i]))