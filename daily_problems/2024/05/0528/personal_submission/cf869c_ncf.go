package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF869C(os.Stdin, os.Stdout) }

func CF869C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b, c int
	fmt.Fscan(in, &a, &b, &c)
	mod := 998244353
	mx := max(a, max(b, c))
	// 预处理阶乘和阶乘逆元
	factorial := makeFactorial(mx, mod)
	var f func(x, y int) int
	f = func(x, y int) (res int) {
		for i := 0; i <= min(x, y); i++ {
			res = (res + factorial.Combination(x, i)*factorial.Combination(y, i)%mod*factorial.Fac(i)%mod) % mod
		}
		return
	}
	fmt.Fprintf(out, "%d", f(a, b)*f(b, c)%mod*f(a, c)%mod)
}

func makeFactorial(n, mod int) *Factorial {
	factorial := &Factorial{}
	factorial.n = n
	factorial.mod = mod
	factorial.Init()
	return factorial
}

type Factorial struct {
	fact, invFact []int
	n, mod        int
}

func (t *Factorial) Init() {
	t.factorialModInit()
	t.invFactModInit()
}

// factorialMod 计算n! % mod
func (t *Factorial) factorialModInit() {
	fact := make([]int, t.n+1)
	fact[0] = 1
	for i := 1; i <= t.n; i++ {
		fact[i] = (fact[i-1] * i) % t.mod
	}
	t.fact = fact
}

// invFactMod 计算阶乘的逆元数组 % mod
func (t *Factorial) invFactModInit() {
	invFact := make([]int, t.n+1)
	invFact[len(invFact)-1] = t.powMod(t.fact[len(t.fact)-1], t.mod-2, t.mod)
	for i := len(invFact) - 2; i >= 0; i-- {
		invFact[i] = (invFact[i+1] * (i + 1)) % t.mod
	}
	t.invFact = invFact
}

// Fac 计算 k! % mod
func (t *Factorial) Fac(k int) int {
	return t.fact[k]
}

// Combination 计算C(n, k) % mod
func (t *Factorial) Combination(n, k int) int {
	if k > n || n < 0 || k < 0 {
		return 0
	}
	return (t.fact[n] * t.invFact[k] % t.mod) * t.invFact[n-k] % t.mod
}

// powMod 快速幂取模
func (t *Factorial) powMod(x, n, mod int) int {
	result := 1
	for n > 0 {
		if n%2 == 1 {
			result = (result * x) % mod
		}
		x = (x * x) % mod
		n /= 2
	}
	return result
}
