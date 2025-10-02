n = ix()
def answer(ans):
    print('!' , *ans, flush=True)

def query(i, x):
    print('?', i, x,flush=True)
    return True if input() == "=" else False

ans = []
i = x = 1
while i <= n:
    if query(i, x):
        ans += [x]
        i += 1
    else:
        x += 1
answer(ans)
