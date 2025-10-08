/*
n = 1e7，1e4 组测试数据，根号以下
首先 2 和所有的偶数已经连起来了
考虑某两个素数 p 和 q，他们能相连的话，至少 n >= p * q
两个素数连起来了，则他们的倍数自然就连起来了
特别的，我们可以钦定 p = 2，这样对 n 的要求最少
这样，对于 q <= n / 2 的素数 q，都是可以和 2 连起来的
对于 q > n / 2 的素数 q，必然是落单的，需要单独连接
所以相当于求一个素数个数的前缀和
*/ 

LL primes[N], cnt;
int is_prime[N];

void meibao() {
    LL n;
    cin >> n;

    LL res1;
    if (n == 2) {
        res1 = 0;
    } else if (n == 3) {
        res1 = 1;
    } else {
        LL q = n / 2;
        res1 = is_prime[n] - is_prime[q];
    }
    cout << res1 << "\n";
}  
