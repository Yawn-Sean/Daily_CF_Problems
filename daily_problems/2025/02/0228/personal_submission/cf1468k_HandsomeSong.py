import sys
input=sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
t=II()
for i in range(1,t+1):
    s=I()
    cand=[]
    visited=set()
    x,y=0,0
    
    for char in s:
        if char=='L':
            x-=1
        elif char=='R':
            x+=1
        elif char=='D':
            y-=1
        elif char=='U':
            y+=1
        if (x,y)!=(0,0) and (x,y) not in visited:
            visited.add((x,y))
            cand.append((x,y))
    fnd=False
    for obs_x,obs_y in cand:
        cx,cy=0,0
        for char in s:
            nx,ny=cx,cy
            if char=='L':
                nx -=1
            elif char=='R':
                nx+=1
            elif char=='D':
                ny-=1
            elif char=='U':
                ny+=1
            if nx==obs_x and ny==obs_y:
                pass
            else:
                cx,cy=nx,ny
        if cx==0 and cy==0:
            print(f"{obs_x} {obs_y}")
            fnd=True
            break
    if not fnd:
        print("0 0")