n=open('input.txt','r').read()
p=open('output.txt','w')
n=int(n)

cnt =math.ceil( math.log2(n))
p.write(str(cnt) )
p.write('\n')
for i in range(cnt ):
    cur =[ j for j in range(1,n+1) if (j>>i)&1 ]
    p.write(str(len(cur)) )
    p.write(' ')
    p.write(' '.join(map(str,cur )))
    p.write('\n')
