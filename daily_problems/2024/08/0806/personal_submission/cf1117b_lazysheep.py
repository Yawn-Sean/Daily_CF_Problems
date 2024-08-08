k = II()
st, sz = 1, 1
cnt = 9
while k >= cnt * sz:
    k -= cnt * sz
    st *= 10
    sz += 1
    cnt *= 10
 
s = str(st - 1 + k // sz + bool(k % sz))
print(s[k % sz - 1])
