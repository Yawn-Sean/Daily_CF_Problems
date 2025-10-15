n  = on = ix()

def query(l, r):
    print('Q', l, r, flush=True)
    return il()

def answer(nums):
    print('A', *nums, flush=True)

nums = []
if n == 1:
    exit(answer([1]))
if n == 2:
    a = query(1,1)[0]
    b = 1 + (1 ^ a - 1)
    exit(answer([a, b]))
last = set(query(1, 2))
i = 2
while n > 4:
    n -= 2
    ns = set(query(i, i + 2))
    a = (last - ns).pop()
    b = (ns & last).pop()
    nums += [a, b]
    last = ns - last
    i += 2
if n == 3:
    ls = set(query(i, i))
    a = (last - ls).pop()
    b = ls.pop()
    nums += [a, b]
elif n == 4:
    ls = set(query(i, i + 1))
    a = (last - ls).pop()
    b = (ls & last).pop()
    c = (ls - last).pop()
    nums += [a, b, c]
end = (set(range(1, on + 1)) - set(nums)).pop()
nums += [end]
answer(nums)



