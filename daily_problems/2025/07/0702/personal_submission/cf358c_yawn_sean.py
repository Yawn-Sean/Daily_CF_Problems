# Submission link: https://codeforces.com/contest/358/submission/327016350
def main():
    q = II()
    cur = []
    outs = []

    v1, v2, v3 = 0, 0, 0

    for _ in range(q):
        x = II()
        
        if x:
            if x > v1:
                v1, v2, v3 = x, v1, v2
            elif x > v2:
                v2, v3 = x, v2
            elif x > v3:
                v3 = x
            cur.append(x)
        else:
            tmp = []
            for v in cur:
                if v == v1:
                    outs.append('pushStack')
                    tmp.append('popStack')
                    v1 = 0
                elif v == v2:
                    outs.append('pushQueue')
                    tmp.append('popQueue')
                    v2 = 0
                elif v == v3:
                    outs.append('pushFront')
                    tmp.append('popFront')
                    v3 = 0
                else:
                    outs.append('pushBack')
            
            if tmp: outs.append(f"{len(tmp)} {' '.join(tmp)}")
            else: outs.append('0')
            cur.clear()

    for v in cur:
        outs.append('pushStack')

    print('\n'.join(outs))