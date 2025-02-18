n = II()
s = I()
tx, ty = MII()
outs = []
need = abs(tx) + abs(ty)

def check(l: int) -> bool:
    for i in range(n - l + 1):
        tmpx = kx + prex[i + l] - prex[i]
        tmpy = ky + prey[i + l] - prey[i]
        tmp = abs(tmpx) + abs(tmpy)
        if l == tmp or l > tmp and (tmp - l) % 2 == 0:
            return True
    return False

if n < need or (need - n) % 2:
    outs.append(-1)
else:
    cx = cy = 0
    prex = [0] * (n + 1)
    prey = [0] * (n + 1)
    for i, mo in enumerate(s):
        if mo == 'U':
            cy += 1
        elif mo == 'D':
            cy -= 1
        elif mo == 'L':
            cx -= 1
        else:
            cx += 1
        prex[i + 1] = cx
        prey[i + 1] = cy
    
    kx = tx - cx
    ky = ty - cy

    outs.append(bisect_left(range(n), True, key = check))

print('\n'.join(map(str, outs)))
