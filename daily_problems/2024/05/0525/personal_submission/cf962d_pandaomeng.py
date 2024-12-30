# submission: https://codeforces.com/problemset/submission/962/262793713

def main():
    n = II()
    arr = [0] * n
    m = defaultdict(list)
    arr = LII()
    for i, x in enumerate(arr):
        m[x].append(i)
    
    h = [k for k in m.keys()]
    heapify(h)
    vis = set()

    while h:
        k = heappop(h)
        if k in vis:
            continue
        indexes = sorted(m[k], reverse=True)
        while len(indexes) >= 2:
            a, b = indexes.pop(), indexes.pop()
            arr[a] = -1
            arr[b] = 2 * k
            m[2 * k].append(b)
            heappush(h, 2 * k)
        vis.add(k)
    ans = [x for x in arr if x != -1]
    print(len(ans))
    print(' '.join(map(str, ans)))

main()