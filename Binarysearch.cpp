#include<iostream>
using namespace std;
class Binarysearch
{
public:
   void binarySearch(int barray[], int left, int right,int key)
    {
        if(right>=1)
        {
            int mid = (left+right)/2;

            if(barray[mid]==key)
            {
                printvalue(barray[mid]);
            }
            if(barray[mid]>key)
            {
                binarySearch(barray,left,mid-1,key);
            }
            if(barray[mid]<key)
            {
                binarySearch(barray,mid+1,right,key);
            }
        }
        else
        {
            printvalue(-1);
        }
    }
    void printvalue(int data)
    {
        if(data==-1)
            {
            cout<<"Element not present in array"<<endl;
            }
        else
            {
            cout<<"Element present in array"<<endl;
            cout<<data<<endl;
            }
    }

};
int main()
{
    int biarray[]={2,3,4,10,40};
    int n = sizeof(biarray)/sizeof(biarray[0]);
    int key=10;
    Binarysearch bs;
    bs.binarySearch(biarray,0,n-1,key);
    return 0;
}
