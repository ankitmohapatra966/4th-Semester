#include <iostream>
using namespace std;
 
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
     if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
           heapify(arr, i, 0);
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
    heapSort(arr, N);
 
    cout << "Sorted array is \n";
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}