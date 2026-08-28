package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	arr := make([]int, n)
	for i := range n {
		fmt.Fscan(in, &arr[i])
	}
	mod := 1000000007
	fmt.Fprintln(out, ((arr[0]-arr[1])%mod+mod)%mod)
}
