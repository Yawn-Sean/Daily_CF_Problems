def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())

n,m=MII()
s=LII()
for i in range(n):
    ss=LII()*2
    for j in range (m):
        if s == ss[j:j+m]:
            print(i+1)
            exit()
print(-1)