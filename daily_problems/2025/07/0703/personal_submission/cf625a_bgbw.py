n=II()
a=II()
b =II()
c =II()
if b-c <a :
    k=b-c
    ans =max(0,(n-b )//k+1)
    n-=(ans *k)
    ans +=n //a
    print(ans )
else:
    print(n//a  )
