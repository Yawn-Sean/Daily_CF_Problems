package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod int = 1e9 + 7

func ksm(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return res
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, k, r, c int
	fmt.Fscan(in, &n, &m, &k, &r, &c)
	var ax, ay, bx, by int
	fmt.Fscan(in, &ax, &ay, &bx, &by)
	s := n * m
	if (ax == bx && ay == by) != true {
		s -= r * c
	}
	ans := ksm(k, s)
	fmt.Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
