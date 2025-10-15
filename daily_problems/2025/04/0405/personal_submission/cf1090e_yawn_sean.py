# Submission link: https://codeforces.com/problemset/submission/1090/313989974
def main():
    n = II()
    cur = [0] * 64

    for _ in range(n):
        s = I()
        pos = (int(s[1]) - 1) * 8 + ord(s[0]) - ord('a')
        cur[pos] = 1

    dirs = [(i, j) for i in range(-2, 3) for j in range(-2, 3) if abs(i) + abs(j) == 3]

    def f(msk):
        a, b = divmod(msk, 8)
        return chr(ord('a') + b) + str(a + 1)

    ops = []

    for i in range(n, 64):
        if cur[i]:
            start = i
            for j in range(n):
                if not cur[j]:
                    end = j
                    break
            
            prev = [-2] * 64
            prev[end] = -1
            
            que = [end]
            for u in que:
                x, y = divmod(u, 8)
                for dx, dy in dirs:
                    if 0 <= x + dx < 8 and 0 <= y + dy < 8:
                        nu = (x + dx) * 8 + y + dy
                        if prev[nu] == -2:
                            prev[(x + dx) * 8 + y + dy] = u
                            que.append(nu)
            
            saved = [start]
            while True:
                p = prev[saved[-1]]
                if p == -1: break

                if cur[p] == 0:
                    v = p
                    while saved:
                        u = saved.pop()
                        ops.append(f'{f(u)}-{f(v)}')
                        cur[u], cur[v] = cur[v], cur[u]
                        v = u
                
                saved.append(p)

    print(len(ops))
    print('\n'.join(ops))