# https://codeforces.com/contest/1142/submission/253425619

def main():

    n, m, q = MII()

    perm = LGMI()
    pos = [-1] * n
    for i in range(n):
        pos[perm[i]] = i

    to_check = [pos[i] for i in GMI()]

    pos = [m] * n
    next_pos = [m] * m
    for i in range(m - 1, -1, -1):
        next_pos[i] = pos[(to_check[i] + 1) % n]
        pos[to_check[i]] = i

    to_search = list(range(m))
    n -= 1
    for i in range(n.bit_length()):
        if n >> i & 1:
            to_search = [next_pos[x] if x < m else m for x in to_search]
        next_pos = [next_pos[x] if x < m else m for x in next_pos]

    for i in range(m - 1, 0, -1):
        if to_search[i-1] > to_search[i]:
            to_search[i-1] = to_search[i]

    ans = []
    for _ in range(q):
        l, r = GMI()
        ans.append(1 if to_search[l] <= r else 0)

    print(''.join(map(str, ans)))