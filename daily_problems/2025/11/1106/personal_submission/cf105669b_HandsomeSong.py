def LI():
    return list(input().split())
mod=10**9+7
s=LI()
a=s[0]
b=s[2]
aa=0
bb=0
for c in a:
    aa=(10*aa+int(c))%mod

for c in b:
    bb=(10*bb+int(c))%(mod if s[1]!='^' else (mod-1))


if s[1]=='+':
    print((aa+bb)%mod)
elif s[1]=='-':
    print((aa-bb)%mod)
elif s[1]=='*':
    print(aa*bb%mod)
else:
    print(pow(aa,bb,mod))