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
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		var n, i int
		fmt.Fscan(in, &n, &i)
		ans := 0
		for true {
			if i%2 == 1 {
				ans += i/2 + 1
				break
			}
			ans += n / 2
			i /= 2
			if n%2 == 1 {
				i++
			}
			n -= n / 2
		}
		fmt.Fprintln(out, ans)
	}
}
