#include <iostream>
using namespace std;
// -----------------------------------------------------------------------------
// isPrime()
// Takes an integer and returns true if it's prime, false otherwise.
// -----------------------------------------------------------------------------
bool isPrime(int n) {
    // Rule: numbers less than 2 are NOT prime (covers negatives, 0, and 1)
    if (n < 2) {
        return false;
    }
    // Check for divisors starting at 2 up to n-1.
    // If we find ANY number that divides n evenly, it's not prime.
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {   // % is the modulus operator — gives the remainder
            return false;   // found a divisor other than 1 and itself -> not prime
        }
    }

    // If we made it through the loop with no divisors found, it's prime
    return true;
}
int main() 
{
      int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    return 0;
}
