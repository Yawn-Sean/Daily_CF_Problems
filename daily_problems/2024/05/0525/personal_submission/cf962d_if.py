n=int(input())
a=list(map(int,input().split()))
s=set()
stack=[]
for i in a:
    if i not in s:
        s.add(i)
        stack.append(i)
        continue
    while i in s:
        stack.remove(i) 
        s.remove(i)
        i*=2
    stack.append(i)
    s.add(i)
print(len(stack))
print(*stack)
