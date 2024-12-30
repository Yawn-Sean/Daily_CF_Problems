package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveD(os.Stdin, os.Stdout) }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	// z[i] = LCP(s, s[i:])   串与串后缀的最长公共前缀
	calcZ := func(s string) []int {
		n := len(s)
		z := make([]int, n)
		for i, l, r := 1, 0, 0; i < n; i++ {
			if i <= r {
				z[i] = min(z[i-l], r-i+1)
			}
			for i+z[i] < n && s[z[i]] == s[i+z[i]] {
				l, r = i, i+z[i]
				z[i]++
			}
		}
		z[0] = n
		return z
	}

	const mod int = 1e9 + 7
	pow := func(a, b int) int {
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

	n, m := readTwoNums(in)
	s := readString(in)
	pos := readNNums(in, m)

	zs, l := calcZ(s), len(s)
	empty, pstart, ans := 0, 1-l, 1
	for _, v := range pos {
		if v-pstart >= l {
			empty += v - pstart - l
			pstart = v
		} else if zs[v-pstart] >= l-(v-pstart) {
			pstart = v
		} else {
			ans = 0
			break
		}
	}
	empty += n + 1 - pstart - l
	if ans != 0 {
		ans = pow(26, empty)
	}
	fmt.Fprintln(out, ans)
}
