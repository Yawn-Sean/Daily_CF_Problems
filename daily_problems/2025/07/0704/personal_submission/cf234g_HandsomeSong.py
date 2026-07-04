f=open("input.txt","r")
n=int(f.read().split()[0])
f.close()
m=0
while(1<<m)<n:
    m+=1
teams=[[]for _ in range(m)]
for i in range(n):
    for j in range(m):
        if not(i&(1<<j)):
            teams[j].append(i+1)
f=open("output.txt","w")
f.write(str(m)+"\n")
for j in range(m):
    f.write(str(len(teams[j]))+" "+" ".join(map(str,teams[j]))+"\n")
f.close()
