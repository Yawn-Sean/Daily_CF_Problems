class Query:
    def __init__(self, pos, v):
        self.pos = pos
        self.v = v

def lleaf(num, h, idl):
    while idl[h] > num:
        num <<= 1
    return num

def rleaf(num, h, idl):
    while idl[h] > num:
        num = (num << 1) | 1
    return num

def main():
    h, q = map(int, input().split())
    idl = [0] * (h + 1)
    idr = [0] * (h + 1)
    
    idl[1] = idr[1] = 1
    for i in range(2, h + 1):
        idl[i] = idl[i - 1] << 1
        idr[i] = (idr[i - 1] << 1) | 1

    d = []
    d.append(Query(idl[h], 0))
    d.append(Query(idr[h] + 1, 0))

    for _ in range(q):
        t1, t2, t3, op = map(int, input().split())
        t2 = max(t2, idl[t1])
        t3 = min(t3, idr[t1])

        if op == 1:
            d.append(Query(lleaf(t2, h, idl), 1))
            d.append(Query(rleaf(t3, h, idl) + 1, -1))
        else:
            d.append(Query(idl[h], 1))
            d.append(Query(lleaf(t2, h, idl), -1))
            d.append(Query(rleaf(t3, h, idl) + 1, 1))
            d.append(Query(idr[h] + 1, -1))

    d.sort(key=lambda x: x.pos)

    dd = []
    ptr = 0
    for i in range(len(d)):
        if i == 0 or d[i].pos != d[i - 1].pos:
            dd.append(Query(d[i].pos, d[i].v))
            ptr += 1
        else:
            dd[ptr - 1].v += d[i].v

    cnt = 0
    ans = 0
    cur = dd[0].v

    for i in range(1, ptr):
        diff = dd[i].pos - dd[i - 1].pos
        if cur == q:
            cnt += diff
            ans = dd[i - 1].pos
        cur += dd[i].v

    if cnt > 1:
        print("Data not sufficient!")
    elif cnt == 1:
        print(ans)
    else:
        print("Game cheated!")

if __name__ == "__main__":
    main()
