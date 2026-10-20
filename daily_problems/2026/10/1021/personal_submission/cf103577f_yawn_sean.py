# Submission link: https://codeforces.com/gym/103577/submission/395309729
def main():
    n, q = MII()
    
    cur = array('i', [0]) * (n * n + q)
    
    cnt_row = [0] * n
    cnt_col = [0] * n
    
    for i in range(n):
        s = [int(c) for c in I()]
        
        for j in range(n):
            cur[i * n + q + j] = s[j]
            cnt_row[i] += s[j]
            cnt_col[(q + j) % n] += s[j]
    
    start_pos = q
    outs = []
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            row, col = query[1] - 1, query[2] - 1
            target = query[3]
            
            pos = start_pos + row * n + col
            
            cnt_row[row] -= cur[pos]
            cnt_col[pos % n] -= cur[pos]
            
            cur[pos] = target
            
            cnt_row[row] += cur[pos]
            cnt_col[pos % n] += cur[pos]
        
        else:
            for i in range(n):
                cnt_row[i] -= cur[start_pos + i * n + (n - 1)]
            
            for i in range(n - 1):
                cnt_row[i + 1] += cur[start_pos + i * n + (n - 1)]
            
            start_pos -= 1
            cnt_col[start_pos % n] -= cur[start_pos + n * n]
            
            target = query[1]
            
            cur[start_pos] = target
            
            cnt_row[0] += target
            cnt_col[start_pos % n] += target
    
        ans = 0
        
        for x in cnt_row:
            if x == n:
                ans += 1
        
        for x in cnt_col:
            if x == n:
                ans += 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))