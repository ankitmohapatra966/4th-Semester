#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
  
        // Last i elements are already 
        // in place 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
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
    bubbleSort(arr, N);
 
    cout << "Sorted array is \n";
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}