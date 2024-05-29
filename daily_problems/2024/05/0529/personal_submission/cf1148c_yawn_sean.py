# Submission link: https://codeforces.com/contest/1148/submission/263075793
def main():
    n = II()
    perm = LGMI()
    pos = [-1] * n

    for i in range(n):
        pos[perm[i]] = i

    ans = []

    def swap(u, v):
        pos[perm[u]], pos[perm[v]] = pos[perm[v]], pos[perm[u]]
        perm[u], perm[v] = perm[v], perm[u]
        ans.append(f'{u + 1} {v + 1}')

    for i in range(1, n // 2):
        if pos[i] != i:
            if pos[i] < n // 2:
                swap(pos[i], n - 1)
                swap(i, n - 1)
            else:
                swap(0, pos[i])
                swap(0, n - 1)
                swap(i, n - 1)

    for i in range(n // 2, n):
        if pos[i] != i:
            if pos[i] >= n // 2:
                swap(0, pos[i])
                swap(0, i)
            else:
                swap(pos[i], n - 1)
                swap(0, n - 1)
                swap(0, i)

    if perm[0] != 0:
        swap(0, n - 1)

    print(len(ans))
    print('\n'.join(ans))