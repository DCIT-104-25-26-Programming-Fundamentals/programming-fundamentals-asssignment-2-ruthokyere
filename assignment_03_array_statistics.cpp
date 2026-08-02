#include <iostream>
using namespace std;


// calculateSum()

int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}



// calculateAverage()

double calculateAverage(int arr[], int n) {
    int sum = calculateSum(arr, n);
    return static_cast<double>(sum) / n;  // cast to double so division isn't truncated
}


// findMax()

int findMax(int arr[], int n) {
    int max = arr[0];   // start by assuming the first element is the max
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


// findMin()

int findMin(int arr[], int n) {
    int min = arr[0];   // start by assuming the first element is the min
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


// main()

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    // Validate: n must be positive
    if (n <= 0) {
        cout << "Error: Number of values must be a positive integer." << endl;
        return 0;   
    }

    // Dynamically allocate an array of size n, since n is only known at runtime
    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << findMax(numbers, n) << endl;
    cout << "Minimum: " << findMin(numbers, n) << endl;

    delete[] numbers;  
    return 0;
}
