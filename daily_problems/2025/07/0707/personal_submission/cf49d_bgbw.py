n=II()
s=I()
ans =0
cur =0
for i in range ( n):
    if s[i]!=str(i%2) :
        cur +=1
for i in range(n):
    if s[i]!=str((i+1)%2):
        ans  +=1
print(min(cur,ans ))
