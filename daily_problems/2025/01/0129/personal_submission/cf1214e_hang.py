def main():
    n = int(input())
    d = list(map(int, input().split()))
    st_r = sorted(range(n), key=lambda i: -d[i])
    ans = []
    lian = [2 * x + 1 for x in st_r]
    for i in range(1, n):
        ans.append(f'{lian[i - 1]} {lian[i]}')
    for i in range(n):
        cur = st_r[i]
        dis = d[cur]
        
        u = 2 * cur + 2
        v = lian[i + dis - 1]
        ans.append(f'{u} {v}')
        if lian[-1] == v:
            lian.append(u)
    print('\n'.join(ans))
main()