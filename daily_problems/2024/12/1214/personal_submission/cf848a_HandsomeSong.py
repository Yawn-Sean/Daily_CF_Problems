import sys
input = sys.stdin.readline
def II():
    return int(input())
k=II()
ans=[]
for i in range (1000,1,-1):
    while i*(i-1)//2<=k:
        k-=i*(i-1)//2
        ans.append(i)
print(''.join(chr(ord('a') + i)*ans[i] for i in range(len(ans))) if ans else 'a')
