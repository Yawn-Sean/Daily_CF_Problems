def solve():
    n=II()
    a=LMII()
    pos=[]
    x,y=0,0
    y_max=0;y_min=0
    for i in range(n):
        x+=a[i];y+=a[i] if i%2==0 else -a[i]
        pos.append([x,y])
        y_max=max(y_max,y)
        y_min=min(y_min,y)
    graph=[[' ']*pos[-1][0] for i in range(y_max-y_min)]
    X,Y=-1,y_max
    for i in range(n):
        x,y=pos[i]
        for j in range(x-X-1):
            X+=1
            if i%2==0:
                Y-=1
                c='/'
            else:
                Y+=1
                c='\\'
            graph[Y][X]=c
        if i%2==0:
            Y-=1
        else:
            Y+=1
    for i in range(y_max-y_min):
        print(''.join(graph[i]))
    return
