def main(): 
    n = II()
    nums = LII()
    
    inc_length = [1] * n
    pos = -1
    
    for i in range(n - 1, -1, -1):
        if nums[i] > 0:
            if pos != -1:
                if nums[i] > nums[pos]: inc_length[i] = pos - i
                else: inc_length[i] = inc_length[i + 1] + 1
            pos = i
        elif i != n - 1:
            inc_length[i] = inc_length[i + 1] + 1
    
    dec_length = [1] * n
    pos = -1
    
    for i in range(n):
        if nums[i] > 0:
            if pos != -1:
                if nums[i] > nums[pos]: dec_length[i] = i - pos
                else: dec_length[i] = dec_length[i - 1] + 1
            pos = i
        elif i > 0:
            dec_length[i] = dec_length[i - 1] + 1
    
    for i in range(3, n + 1):
        flg = True
        for j in range(0, n, i):
            l = j
            r = fmin(j + i - 1, n - 1)
            if inc_length[l] + dec_length[r] < r - l + 2 or r - l + 1 < 3 or inc_length[l] < 2 or dec_length[r] < 2:
                flg = False
        if flg:
            print('Y')
            break
    else:
        print('N')
