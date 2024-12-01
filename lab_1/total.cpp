#include <iostream>
#include <vector>
#include <iomanip> // For std::setw
using namespace std;

// Function prototypes
int fibonacciRecursive(int n, vector<int>& fib);
int fibonacciIterative(int n, int& iterativeCalls);

int main() {
    const int numInputs = 8; // Exactly 8 inputs required
    vector<int> inputSizes(numInputs);
    
    cout << "Enter exactly " << numInputs << " non-negative integers for Fibonacci sizes:" << endl;
    
    for (int i = 0; i < numInputs; i++) {
        int n;
        cin >> n;
        
        while (n < 0) {
            cout << "Invalid input! Please enter a non-negative integer for position " << (i + 1) << ":" << endl;
            cin >> n;
        }
        inputSizes[i] = n;
    }

    cout << "\nInput Size | Recursive Calls | Iterative Steps" << endl;
    cout << "----------------------------------------------" << endl;

    for (int num : inputSizes) {
        // For recursive calculation with memoization
        vector<int> fib(num + 1, -1); // Initialize memoization array
        int recursiveCalls = 0; // To count calls made
        int resultRecursive = fibonacciRecursive(num, fib);
        
        // For iterative calculation
        int iterativeCalls = 0;
        int resultIterative = fibonacciIterative(num, iterativeCalls);

        // Print the results in a table format
        cout << setw(10) << num << " | "
             << setw(15) << recursiveCalls << " | "
             << setw(15) << iterativeCalls << endl;
    }

    return 0;
}

// Memoization Fibonacci function
int fibonacciRecursive(int n, vector<int>& fib) {
    if (n == 0) return 0; // Base case
    if (n == 1) return 1; // Base case
    
    if (fib[n] != -1) return fib[n]; // Return memoized result

    // Compute the Fibonacci number and store it
    fib[n] = fibonacciRecursive(n - 1, fib) + fibonacciRecursive(n - 2, fib);
    return fib[n];
}

// Iterative Fibonacci function
int fibonacciIterative(int n, int& iterativeCalls) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1;
    iterativeCalls++; // Count the first assignment
    for (int i = 2; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
        iterativeCalls++; // Count each iteration
    }
    return b; // Return the nth Fibonacci number
}
