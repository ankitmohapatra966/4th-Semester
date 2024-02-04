#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 int main()
{
    int arr[100],N;
    cout<<"Enter size of array:";
    cin>>N;
    cout<<"Enter the element of array:";
    for(int i=0;i<N;i++){
        cin>>arr[i];
    } 
    insertionSort(arr, N);
 
    cout << "Sorted array is \n";
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}