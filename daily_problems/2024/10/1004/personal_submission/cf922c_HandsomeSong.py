import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,k=MII()
for i in range(1,k+1):
    if i in range(1,k+1):
        if n%i!=i-1:
            print('No')
            exit()
print('Yes')