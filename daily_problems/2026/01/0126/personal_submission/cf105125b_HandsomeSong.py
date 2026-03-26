def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def I():
    return list(input())


t=II()
for _ in range(t):
    n=II()
    a=LII()
    total=sum(a)
    step2=sum(max(v-1,0) for v in a)
    if total%2==0 or step2<total-step2-1:
        print('No')
        continue
    else:
        print("Yes")
        sorted_range=sorted([i for i in range(n) if a[i]],key =lambda x:a[x])

        ones=[]
        ops=[]

        p=0
        flag=1
        k=len(sorted_range)
        for _ in range(total):
            while p<k and a[sorted_range[p]]==1:
                ones.append(sorted_range[p])
                p+=1
            if flag and ones:
                idx=ones.pop()
                a[idx]-=1
                ops.append(idx)
            else:
                a[sorted_range[p]]-=1
                ops.append(sorted_range[p])
            flag^=1
    print(' '.join(str(x+1) for x in ops))
