def main():
    b,d = map(int,input().split())
    a = input()
    c = input()
    n = len(c)
    idx = list(range(n))
    cnt = [0] * n
    for i in range(n):
        for ch in a:
            if ch == c[idx[i]]:
                idx[i] += 1
                if idx[i] == n:
                    idx[i] = 0
                    cnt[i] += 1
    u,v = 0,0
    for i in range(b):
        v += cnt[u]
        u = idx[u]
    print(v // d)
main()