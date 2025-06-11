def main():
    n,q = map(int, input().split())
    cnt = [0] * (n + 1)
    unread = [0] * (n + 1)
    pos = []
    pi = 0
    tot = 0
    for _ in range(q):
        t,x = map(int, input().split())
        if t == 1:
            tot += 1
            cnt[x] += 1
            pos.append(x)
        elif t == 2:
            tot -= cnt[x]
            cnt[x] = 0
            unread[x] = len(pos)
        else:
            while pi < x:
                if pi >= unread[pos[pi]]:
                    tot -= 1
                    cnt[pos[pi]] -= 1
                pi += 1
        print(tot)
main()