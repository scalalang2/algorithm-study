package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)

	for i := 0; i < N; i++ {
		text := ""

		for j := 0; j < i; j++ {
			text = text + " "
		}

		for k := 0; k < (N-i)*2-1; k++ {
			text = text + "*"
		}

		fmt.Println(text)
	}
}
