t=II()
ans =0
for  i  in range( t ):
    a,b=MII()
    if b==1:c=a+1
    else:
        c=a+math.ceil(math .log( b,4 ) )
    ans=max(ans,c )
print(ans )
