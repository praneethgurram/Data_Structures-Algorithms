//C++ program to sort numbers using Insertion Sort algorithm
#include<iostream>

using namespace std;
//class for Insertion Sort
class InsertionSort{

public:
    void insertionsort(int a[],int k)//k length of array
    {
        int j,i,key;
        for(j=1;j<k;j++)
        {
            key = a[j];
            i = j-1;
            while(i >=0 && a[i]> key)
            {
                a[i+1] = a[i];
                i--;
            }
            a[++i] = key;
        }

    }
    void printarray(int a[], int k)
    {
        cout<<"Sorted array after using Insertion sort is"<<endl;
        for(int i=0;i<k;i++)
        {
            cout<<a[i]<<endl;
        }
    }

};

int main()
{
    int A[] = {31,41,59,26,41,58};
    int length = sizeof(A)/sizeof(A[0]);
    InsertionSort it;
    it.insertionsort(A,length);
    it.printarray(A,length);
    return 0;

}
