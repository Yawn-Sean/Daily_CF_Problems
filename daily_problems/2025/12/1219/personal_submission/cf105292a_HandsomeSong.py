n,m=map(int,input().split())
a=[list(input()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if a[i][j]=='.':
            a[i][j]='L'
            
            for x in range(i+1,n):
                if a[x][j]=='#':
                    break
                a[x][j]='..'
            for y in range(j+1,m):
                if a[i][y]=='#':
                    break
                a[i][y]='..'
for i in range(n):
    for j in range(m):
        if a[i][j]=='..':
            a[i][j]='.'
print('\n'.join(''.join(items) for items in a))