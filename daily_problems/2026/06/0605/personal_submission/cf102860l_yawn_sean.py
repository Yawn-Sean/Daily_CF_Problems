# Submission link: https://codeforces.com/gym/102860/submission/377293067
def main():
    n, q = MII()
    
    fen_x_k = FenwickTree(n + 2)
    fen_x_b = FenwickTree(n + 2)
    
    fen_y_k = FenwickTree(n + 2)
    fen_y_b = FenwickTree(n + 2)
    
    fen_x_k.add(0, 1)
    
    outs = []
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            l = query[1]
            r = query[2]
            
            if l == r: continue
            
            x1 = fen_x_k.rsum(0, l) * l + fen_x_b.rsum(0, l)
            x2 = fen_x_k.rsum(0, r) * r + fen_x_b.rsum(0, r)
            
            if x1 == x2:
                fen_x_k.add(l, 1)
                fen_x_k.add(r + 1, -1)
                
                fen_x_b.add(l, -l)
                fen_x_b.add(r + 1, l)
                
                fen_y_k.add(l, -1)
                fen_y_k.add(r + 1, 1)
                
                fen_y_b.add(l, l)
                fen_y_b.add(r + 1, -l)
            else:
                fen_x_k.add(l, -1)
                fen_x_k.add(r + 1, 1)
                
                fen_x_b.add(l, l)
                fen_x_b.add(r + 1, -l)
                
                fen_y_k.add(l, 1)
                fen_y_k.add(r + 1, -1)
                
                fen_y_b.add(l, -l)
                fen_y_b.add(r + 1, l)
            
        else:
            j = query[1]
            
            x = fen_x_k.rsum(0, j) * j + fen_x_b.rsum(0, j)
            y = fen_y_k.rsum(0, j) * j + fen_y_b.rsum(0, j)
    
            outs.append(f'{x} {y}')
    
    print('\n'.join(outs))