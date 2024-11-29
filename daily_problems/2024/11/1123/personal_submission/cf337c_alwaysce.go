package main

import (
	"bufio"
	"fmt"
	"io"
)

func powM(x, n, p int64) (res int64) {
	x %= p
	res = int64(1) % p
	for ; n > 0; n /= 2 {
		if n%2 > 0 {
			res = res * x % p
		}
		x = x * x % p
	}
	return
}

func cf337C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		翻倍 | 不翻倍
		xxxx | xxx0 xxx0 xxx0
		n/k个空位可以放0
		n-n/k
		1234k(2k) 5678
		1 2->4 5 x 6
		ik个完整组答对的分数 = k*(2^(i+1)-2)分
	*/

	var n, m, k int64
	fmt.Fscan(in, &n, &m, &k)
	mod := int64(1_000_000_009)

	// 不翻倍的部分
	v1 := min(m, n-(n/k))
	// 属于前面翻倍的部分长度
	v2 := m - v1

	// v2个组需要翻倍
	ans := (k*(powM(int64(2), int64(v2)+1, mod)-2) - (k-1)*v2%mod + v1 + mod) % mod
	fmt.Fprintln(out, ans)
}

//func main() {
//	cf337C(bufio.NewReader(os.Stdin), os.Stdout)
//}
