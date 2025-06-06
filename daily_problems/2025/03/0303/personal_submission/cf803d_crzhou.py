n = II()
s = I()

len_s = len(s)
s = re.split(r'[ -]', s)

def check(x: int) -> bool:
    tmp = cnt = 0
    for i, w in enumerate(s):
        a = 0 if i == len(s) - 1 else 1
        if len(w) + a > x:
            return False
        if tmp + len(w) + a > x:
            cnt += 1
            tmp = len(w) + a
            if cnt == n:
                return False
        else:
            tmp += len(w) + a
    return True

print(bisect_left(range(len_s), True, key=check))
