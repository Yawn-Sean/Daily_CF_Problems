# Submission link: https://codeforces.com/contest/858/submission/280133227
def main():
    n = II()
    strs = [I() for _ in range(n)]

    vis = Counter()

    rnd = random.getrandbits(20)
    for x in strs:
        tmp = set()
        for i in range(9):
            cur = 0
            for j in range(i, 9):
                cur = cur * 10 + int(x[j])
                tmp.add(cur * 10 + j - i)
        for v in tmp:
            vis[v] += 1

    outs = []
    for x in strs:
        mi_len = 10
        start = 0
        for i in range(9):
            cur = 0
            for j in range(i, 9):
                cur = cur * 10 + int(x[j])
                if vis[cur * 10 + j - i] == 1 and j - i < mi_len:
                    start = i
                    mi_len = j - i
        outs.append(x[start:start+mi_len+1])

    print('\n'.join(outs))