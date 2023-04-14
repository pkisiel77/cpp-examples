## Task 1

Objective: Write a C++ program to implement a function that checks if a given number is prime and test it with various inputs.

Task Description:

A prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. In other words, a prime number has exactly two distinct natural number divisors: 1 and itself.

Your task is to write a C++ program that implements a function to determine if a given number is prime. Then, create a main function to test your implementation with various inputs.

Requirements:

- Write a function bool is_prime(int number) that takes an integer as an argument and returns true if the number is prime and false otherwise.
- In the main function, ask the user for an input number and then use the is_prime function to check if the input number is prime.
- Display the result to the user, indicating whether the input number is prime or not.
- Repeat the process until the user decides to stop.
- Ensure the program handles edge cases, such as negative numbers and non-integer inputs.

```
Enter a number to check if it's prime (-1 to quit): 5
5 is a prime number.

Enter a number to check if it's prime (-1 to quit): 4
4 is not a prime number.

Enter a number to check if it's prime (-1 to quit): -1
Exiting the program.
```
