n = int(input()) 
a = map(int, input().split()) 

outs = [[]] 
lsts = [0] 

for x in a: 
    l, r = 0, len(lsts) - 1
    while l < r: 
        mid = l + r >> 1 
        if lsts[mid] < x: r = mid 
        else: l = mid + 1 
    if lsts[l] >= x: 
        outs.append([f'{x}'])
        lsts.append(x)
    else:
        outs[l].append(f'{x}')
        lsts[l] = x 

print('\n'.join([' '.join(out) for out in outs]))
