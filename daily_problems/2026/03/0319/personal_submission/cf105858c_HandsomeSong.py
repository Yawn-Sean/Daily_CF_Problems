a=list(input())
b=list(input())
mod=998244353
if len(b)>len(a):
    a,b=b,a
len_a=len(a)
len_b=len(b)
all=a+b
all.sort(reverse=True)
a=all[:len_a-len_b]
all=all[len_a-len_b:]
aa=all[::2]
b=all[1::2]
a+=aa
print((int(''.join(a))+int(''.join(b)))%mod)