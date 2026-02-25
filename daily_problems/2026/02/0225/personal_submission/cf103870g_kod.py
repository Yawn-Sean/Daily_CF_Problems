for i in range(ix()):
    a, b, m = il()
    t = m.bit_length() - 1
    print((b + 1 >> t) - (a >> t))
