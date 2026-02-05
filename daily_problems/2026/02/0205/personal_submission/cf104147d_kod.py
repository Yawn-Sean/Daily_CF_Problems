f = open('dotak.in', 'r')
input = lambda: f.readline().strip()

for x in range(ix()):
    n, k = il()
    c = n * k % (k + 1)
    print('Omda' if c == k or c % 2 else 'Teemo')
