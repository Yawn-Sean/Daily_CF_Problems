def main():
    index = 0
    def next_int():
        nonlocal index
        val = int(data[index])
        index += 1
        return val

    n = next_int()
    m = next_int()
    h = next_int()
    t = next_int()

    g = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = next_int()
        v = next_int()
        g[u].append(v)
        g[v].append(u)

    st = [0] * (n + 1)
    rest = [0] * (n + 1)
    k = 0

    for u in range(1, n + 1):
        for v in g[u]:
            if len(g[u]) <= h or len(g[v]) <= t:
                continue
            
            for x in g[u]:
                if x != v:
                    st[x] = 1
            
            k = 0
            for x in g[v]:
                if x != u:
                    st[x] += 2
                    if st[x] == 3:
                        rest[k] = x
                        k += 1

            head = []
            tail = []
            for x in g[u]:
                if x != v and st[x] == 1:
                    head.append(x)
                    if len(head) >= h:
                        break
            
            for x in g[v]:
                if x != u and st[x] == 2:
                    tail.append(x)
                    if len(tail) >= t:
                        break

            while len(head) < h and k > 0:
                k -= 1
                head.append(rest[k])

            while len(tail) < t and k > 0:
                k -= 1
                tail.append(rest[k])

            if len(head) >= h and len(tail) >= t:
                print("YES")
                print(u, v)
                print(" ".join(map(str, head)))
                print(" ".join(map(str, tail)))
                return

            for x in g[u]:
                st[x] = 0
            for x in g[v]:
                st[x] = 0

    print("NO")

if __name__ == "__main__":
    main()
