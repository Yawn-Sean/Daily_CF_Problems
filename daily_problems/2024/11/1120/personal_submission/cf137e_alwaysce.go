package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

const fenwickInitVal = 1_000_000_000 // -1e18

type fenwick []int

func newFenwickTree(n int) fenwick {
	t := make(fenwick, n+1)
	for i := range t {
		t[i] = fenwickInitVal
	}
	return t
}

func (fenwick) op(a, b int) int {
	return min(a, b)
}

// a[i] 增加 val
// 1<=i<=n
func (f fenwick) update(i, val int) {
	for ; i < len(f); i += i & -i {
		f[i] = f.op(f[i], val)
	}
}

// 求前缀和 a[1] + ... + a[i]
// 1<=i<=n
func (f fenwick) pre(i int) int {
	res := fenwickInitVal
	i = min(i, len(f)-1)
	for ; i > 0; i &= i - 1 {
		res = f.op(res, f[i])
	}
	return res
}

func cf137E(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		+2 -1 -1 -1 +2 -1 +2 -1
		寻找子数组满足 区间和 >= 0
		输出这个最长的长度
	*/
	var s string
	Fscan(in, &s)
	values := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' {
			values[i] = -1
		} else if s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' {
			values[i] = -1
		} else {
			values[i] = 2
		}
	}

	off := len(values) + 1
	fen := newFenwickTree(3*len(values) + 5)
	fen.update(off, -1)
	curSum := 0
	ansL, cnt := 0, 0

	for i, v := range values {
		curSum += v
		// <= curSum的对应下标
		preIdx := fen.pre(curSum + off)
		L := i - preIdx
		if L > ansL {
			ansL = L
			cnt = 1
		} else if L == ansL {
			cnt++
		}
		fen.update(curSum+off, i)
	}

	if ansL > 0 {
		Fprintln(out, ansL, cnt)
	} else {
		Fprintln(out, "No solution")
	}
}

// func main() {
// 	cf137E(bufio.NewReader(os.Stdin), os.Stdout)
// }
