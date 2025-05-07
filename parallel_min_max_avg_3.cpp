
#include <iostream> 
#include <vector> 
#include <omp.h> 
using namespace std; 
 
int main() { 
    int n; 
    cout << "Enter number of elements: "; 
    cin >> n; 
    vector<double> arr(n); 
     
    cout << "Enter elements: " << endl; 
    for (double &x : arr) { 
        cin >> x; 
    } 
 
    double min_val = arr[0], max_val = arr[0], sum = 0.0, avg = 0.0; 
 
    #pragma omp parallel for reduction(min:min_val) reduction(max:max_val) 
reduction(+:sum) 
     
    for (int i = 0; i < n; i++) { 
        if (arr[i] < min_val) min_val = arr[i]; 
        if (arr[i] > max_val) max_val = arr[i]; 
        sum += arr[i]; 
    } 
 
    avg = sum / n; 
 
    cout << "Minimum: " << min_val << endl; 
    cout << "Maximum: " << max_val << endl; 
    cout << "Sum: " << sum << endl; 
    cout << "Average: " << avg << endl; 
 
    return 0; 
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
************************************* OUTPUT *************************************** 
//sudo apt update
//sudo apt install g++ libomp-dev
//g++ -fopenmp parallel_min_max_avg.cpp -o parallel_min_max_avg
//   ./parallel_min_max_avg






Enter number of elements: 5 
Enter elements:  
123 
45 
6 
678 
98 
Minimum: 4 
Maximum: 678 
Sum: 798 
Average: 159.6 


Takes an array of numbers as input from the user.

Uses OpenMP to:

Calculate the minimum value in the array.

Calculate the maximum value in the array.

Sum all the elements in the array.

Computes the average of the array values.

Displays the results: minimum, maximum, sum, and average.


| Library      | Purpose                                       |
| ------------ | --------------------------------------------- |
| `<iostream>` | For input/output operations.                  |
| `<vector>`   | To store the array (`std::vector`).           |
| `<omp.h>`    | OpenMP header to enable parallel programming. |
