def matrix_multi(A,B,mod):
    res=[[0,0],[0,0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j]=(res[i][j]+A[i][k]*B[k][j])%mod
    return res

def matrix_pow(A,power,mod):
    res=[[1,0],[0,1]]

    while power>0:
        if power%2==1:
            res=matrix_multi(res,A,mod)
        A=matrix_multi(A,A,mod)
        power//=2
    return res
n =int(input())
mod = 998244353
print(pow(2,matrix_pow([[1, 1], [1, 0]], n, mod - 1)[0][1], mod))