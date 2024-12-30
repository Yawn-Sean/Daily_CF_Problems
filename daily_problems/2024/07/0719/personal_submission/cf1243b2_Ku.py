k = RI()
def swap(i,j):
    ans.append(f'{i+1} {j+1}')
    s[i],t[j] = t[j],s[i]
for _ in range(k):
    n = RI()
    s = list(input())
    t = list(input())
    judge =  0
    cnt = Counter(s)
    for x in t:
        cnt[x] += 1
    for k,v in cnt.items():
        if v % 2 ==  1:
            judge = 1
            break
    if judge:
        print('No')
        continue
    else:
        print('Yes')
        ans = []
        for i in range(n):
            if s[i] == t[i]:
                continue
            else:
                for j in range(i+1,n):
                    m = 0
                    if s[j] == s[i]:
                        swap(j,i)
                        m = 1
                        break
                if not m:
                    for j in range(i + 1, n):
                        if t[j] == s[i]:
                            swap(n-1, j)
                            swap(n-1, i)

                            break
        print(len(ans))
        print('\n'.join(ans))
