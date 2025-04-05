n = RI()
now_num = 2
for now_step in range(1, n + 1):
    next_num = (now_step) * (now_step + 1)
    print((next_num ** 2 - now_num) // now_step)
    now_num = next_num
