// Recursion


package main


import (
	"fmt"
	"math/rand"
	"time"
)


func main() {


	// Seed the random number generator
	rand.Seed(time.Now().UnixNano())


	// Get the number of iterations
	var iterations int
	fmt.Print("Enter the number of iterations: ")
	fmt.Scanf("%d", &iterations)


	// Print the number of iterations
	fmt.Println("Iterations:", iterations)


	// Print the number of iterations
	fmt.Println("Recursive Fibonacci:", fibonacci(iterations))

}


// Recursive Fibonacci
func fibonacci(n int) int {

	
	// Check if the number is less than or equal to 1
	if n <= 1 {
		
		
		// Return the number
		return n
	}


	// Return the sum of the previous two numbers
	return fibonacci(n - 1) + fibonacci(n - 2)
}