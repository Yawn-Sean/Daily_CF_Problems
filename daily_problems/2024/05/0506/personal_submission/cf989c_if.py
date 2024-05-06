a,b,c,d=map(int,input().split())
tar=[]
for i in range(0,24,2):
    for j in range(0,24,2):
        tar.append([i,j])

ab=["A"for i in range(25)]+["B" for j in range(25)]
AB=[ab.copy() for i in range(25)]
cd=["C"for i in range(25)]+["D" for j in range(25)]
CD=[cd.copy() for i in range(25)]

ABCD=AB+CD


if b>1:
    for i,j in tar:
        ABCD[i][j]="B"
        b-=1
        if b==1:
            break
if a>1:
    for i,j in tar:
        ABCD[i][j+26]="A"
        a-=1
        if a==1:
            break
if c>1:
    for i,j in tar:
        ABCD[i+26][j+26]="C"
        c-=1
        if c==1:
            break
if d>1:
    for i,j in tar:
        ABCD[i+26][j]="D"
        d-=1
        if d==1:
            break
print(len(ABCD),len(ABCD[0]))
for i in ABCD:
    print(''.join(i))
