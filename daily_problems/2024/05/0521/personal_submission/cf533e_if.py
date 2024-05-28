n=int(input())
s1=input()
s2=input()
left=0
right=n-1
while s1[left]==s2[left]:
    left+=1
while s1[right]==s2[right]:
    right-=1
s1=s1[left:right+1:]
s2=s2[left:right+1:]
if len(s1)==1:
    print(2)
elif len(s1)==2:
    if s1[0]==s2[1] and s1[1]==s2[0]:
        print(2)
    elif s1[0]==s2[1] or s1[1]==s2[0]:
        print(1)
    else:
        print(0)
else:
    if s1[1::]==s2[:len(s2)-1:] and s2[1::]==s1[:len(s1)-1:]:
        print(2)
    elif s1[1::]==s2[:len(s2)-1:] or s2[1::]==s1[:len(s1)-1:]:
        print(1)
    else:
        print(0)
