/* Overview:  
    Write a program that reads an integer N (1 ≤ N ≤ 100), followed by N integers. 
    Store them in a 1D array, calculate the sum and average, and print the results.
*/
#include<iostream>
#include<vector>

//defines the standard namespace (std)
using namespace std;

// protytype of sum function 
int sum(const vector<int>& arr, int n);

int main() {
    int n;

    do {
        cout << "Enter the number of elements: ";
        cin >> n;
    } while(n < 1 || n > 100); // stops when n is between 1 and 100

    vector<int> arr(n); // initializes a vector of n elements
    
    // loops through the array and stores the input in the array
    for(int i = 0; i < n; i++){  
        cout << "Enter index" << i << ": ";
        cin >> arr[i];
    }

    

    
    // calculate the sum once
    int totalSum = sum(arr, n);
    
    // prints the sum and average of the array
    cout << "Sum: " << totalSum << endl;
    cout << "Average: " << totalSum / n << endl;

    return 0;
}

int sum(const vector<int>& arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}
