def main():
    n = int(input())
    a = list(map(int, input().split()))
    k = int(input())
    b = list(map(int, input().split()))
    pos = 0
    idx = 1
    ans = []
    for v in b:
        cur = 0
        l = pos
        while pos < n and cur < v:
            cur += a[pos]
            pos += 1
        r = pos
        if cur != v:
            print('NO')
            return
        if r - l > 1:
            mx = max(a[l:r])
            flg = False
            for i in range(l,r):
                if a[i] == mx:
                    if i > l and a[i] > a[i - 1]:
                        flg = True
                        for j in range(i - 1, l - 1, -1):
                            ans.append(f'{idx + j + 1 - l} L')
                        
                        for j in range(i + 1, r):
                            ans.append(f'{idx} R')
                        break
                    
                    if i + 1 < r and a[i] > a[i + 1]:
                        flg = True
                        for j in range(i + 1, r):
                            ans.append(f'{idx + i - l} R')
                        
                        for j in range(i - 1, l - 1, -1):
                            ans.append(f'{idx + j + 1 - l} L')
                        
                        break
            if not flg:
                print('NO')
                return
        idx += 1
    if pos != n:
        print('NO')
        return
    print('YES')
    for v in ans:
        print(v)



main()