def next_string(s):

    s = list(s)
    n = len(s)
    

    for i in range(n - 1, -1, -1):
        if s[i] != 'z':
            s[i] = chr(ord(s[i]) + 1)  
            return ''.join(s)  
        else:
            s[i] = 'a'  
    
    return ''.join(s)  


def solve():
    s=I()
    t=I()
    next_s = next_string(s)
    
    if next_s < t:
        print(next_s)
    else:
        print("No such string")


# T=II()
T=1
for _ in range(T):
    solve()
