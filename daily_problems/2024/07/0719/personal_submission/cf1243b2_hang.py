def main():
    n = int(input())
    s = list(input())
    t = list(input())
    f = True
    ans = []
    def swap(i,j):
        s[i],t[j] = t[j],s[i]
        ans.append(f'{i + 1} {j + 1}')
    for i in range(n):
        if s[i] == t[i]:
            continue
        for j in range(i + 1,n):
            if s[i] == s[j]:
                swap(j,i)
                break
        else:
            for j in range(i + 1,n):
                if s[i] == t[j]:
                    swap(i+1,j)
                    swap(i+1,i)
                    break
            else:
                f = False
                break
    if f:
        print('Yes')
        print(len(ans))
        print('\n'.join(ans))
    else:
        print('No')

k = int(input())
for _ in range(k):
    main()