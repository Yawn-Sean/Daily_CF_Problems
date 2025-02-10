n=int(input())
arr=list(map(int,input().split()))
if sum(arr)<2*(n-1):
    print("NO")
else:
    odd=[]
    for i in range(n):
        if arr[i]==1:
            odd.append(i)
            arr[i]=0
    print("YES",(n-len(odd)-1)+min(2,len(odd)))
    print(n-1)
    lst=-1
    if odd:
        lst=odd.pop()
    for i in range(n):
        if arr[i]>1:
            if lst!=-1:
                arr[lst]-=1
                arr[i]-=1
                print(lst+1,i+1)
            lst=i
        
    for i in range(n-1,-1,-1):
        while odd and arr[i]>0:
            arr[i]-=1
            print(odd.pop()+1,i+1)
