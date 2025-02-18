def main():
    s=I()
    vowel=['a','e','i','o','u','A','E','I','O','U']
    lst=[1 if i not in vowel else 0 for i in s]
    presum=[0]
    cur=0
    for i in lst:
        cur+=i 
        presum.append(cur)
    order=[3*presum[i]-i for i in range(len(presum))]
    mono_stack=[]
    
    sl=SortedList()
    ans=0
    cmax=-2
    dic={}
    for i in range(len(presum)):
        if i==0:
            mono_stack.append(i)
            sl.add(order[0])
            dic[order[0]]=i
        else:
            pos=sl.bisect_right(order[i])
            if pos>0:
                tmp=i-dic[sl[pos-1]]
            else:
                tmp=-3
            #print('here',i,tmp)
            if tmp>cmax:
                cmax=tmp 
                ans=1
            elif tmp==cmax:
                ans+=1
            if order[i]<order[mono_stack[-1]]:
                mono_stack.append(i)
                dic[order[i]]=i
                sl.add(order[i])
    if cmax<=0:
        print('No solution')
    else:
        print(cmax,ans)


t=1
for i in range(t):
    w = main()
    #print(w)

