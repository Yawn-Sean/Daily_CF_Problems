def main():
    n = int(input())
    r = list(map(int, input().split()))
    outs = []
    def opt(idxs):
        ans = ['0'] * n
        for i in idxs:
            r[i] = max(0, r[i] - 1)
            ans[i] = '1'
        outs.append(''.join(ans))
        
        
    while min(r) != max(r):
        mx = max(r)
        idxs = [i for i in range(n) if r[i] == mx]
        l = len(idxs)
        if l > 1:
            if l % 2 == 0:
                for i in range(0,l, 2):
                    opt(idxs[i:i+2])
            else:
                opt(idxs[:3])
                for i in range(3,l,2):
                    opt(idxs[i:i+2])
        else:
            idx = -1
            for i in range(n):
                if r[i] != mx and (idx == -1 or r[i] > r[idx]):
                    idx = i
            opt([idx, idxs[0]])
    print(r[0])
    print(len(outs))
    print('\n'.join(outs))


main()