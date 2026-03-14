a=list(map(int,input().split()))
def shuffle(a):
    x=[]
    for i in range (26):
        x.append(a[i])
        x.append(a[i+26])
    return x
for _ in range (53):
    a=shuffle(a)
    if 1 not in a[-26:]:
        print("YES")
        exit()
    else:
        continue
print('NO')