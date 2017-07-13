//QuickSort Algorithm using C++
#include<iostream>
using namespace std;

class QuickSort{
public:
    void swapint(int *a, int *b)
    {
        int temp = *a;
        *a= *b;
        *b = temp;
    }
    int partitionfunc(int arr[],int low, int high)
    {
        int piv = arr[high];
        int i = low-1;
        int j = low;
        for(j;j < high;j++)
        {
            if(arr[j] <= piv)
            {
                i++;
                swapint(&arr[j],&arr[i]);
            }
        }
        swapint(&arr[i+1],&arr[high])    ;
        return (i+1);
    }
    void quicksort(int arr[], int low, int high)
    {
        if(low < high){
            int pi = partitionfunc(arr, low, high);
            quicksort(arr,low, pi-1);
            quicksort(arr,pi+1,high);
        }
    }
     void printarray(int Arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<Arr[i]<<" ";
        }
    }

};
int main()
{
     int Arr[]={2,4,5,7,1,3,6,31};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    QuickSort qs;
    cout<<"Before Sorting the array is"<<endl;
    qs.printarray(Arr, n);
    qs.quicksort(Arr,0,n-1);
    cout<<"\nArray after Sorting is"<<endl;
    qs.printarray(Arr,n);
    return 0;
}
