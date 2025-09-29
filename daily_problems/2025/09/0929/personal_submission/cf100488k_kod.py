n = ix()
a = il()
sl = SortedList()
for i,x in enumerate(a):
    c = (i + 2) // 2
    if len(sl) < c:
        sl.add(x)
    else:
        if x > sl[0]:
            sl.remove(sl[0])
            sl.add(x)
print(sum(sl),sum(a) - sum(sl))
