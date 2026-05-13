import sys
input = sys.stdin.readline
def II():
    return int(input())
t=II()
for _ in range(t):
    n=II()
    for i in range(1000):
        v=i*(i+1)//2
        if 2-v<=n<=v and (v-n)%2==0 and n!=v-2 and n!=4-v:
            print(i)
            chosen=[0]*(i+1)
            target=(v-n)//2
            for x in range(i,1,-1):
                if target>=x and target-x!=1:
                    target-=x
                    chosen[x]=1
            print('1'+''.join("+-"[chosen[j]]+str(j)for j in range(2,i+1)))
            break