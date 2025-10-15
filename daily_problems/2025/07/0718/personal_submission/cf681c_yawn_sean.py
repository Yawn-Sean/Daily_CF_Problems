# Submission link: https://codeforces.com/contest/681/submission/329344626
def main():
    t = II()
    pq = []
    
    outs = []
    for _ in range(t):
        query = LI()
        
        if query[0][0] == 'i':
            heappush(pq, int(query[1]))
            outs.append(' '.join(query))
        
        elif query[0][0] == 'r':
            if len(pq) == 0:
                heappush(pq, 1)
                outs.append('insert 1')
            
            heappop(pq)
            outs.append(query[0])
        
        else:
            v = int(query[1])
            while pq and pq[0] < v:
                outs.append('removeMin')
                heappop(pq)
            
            if not pq or pq[0] != v:
                heappush(pq, v)
                outs.append(f'insert {v}')
            
            outs.append(' '.join(query))
    
    print(len(outs))
    print('\n'.join(outs))