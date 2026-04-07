def II():
    return int(input())
n=II()
ls=[]
guess=1
for i in range(1,n+1):
    c=''
    while c != '=':
        print('?',i,guess,flush=True)
        c=input()
        if c=='=':
            ls.append(guess)
        elif c=='<':
            guess+=1
print('!',end=' ')
print(*ls)
    

