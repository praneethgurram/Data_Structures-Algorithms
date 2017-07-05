/*Heap Sort Algorithm using C++

Heap is implemented by using Max Heap
*/
#include<iostream>
#include<climits>
using namespace std;

//class for the heap
class MaxHeap{

int *heaparray; // pointer for the heap elements
int capacity; //denotes the maximum number of elements possibly stored in heap
int heapsize; //size for this heap

public:
    //constructor for the class
    MaxHeap(int Capacity){
        heapsize =-1;
    capacity = Capacity; //Initializing the capacity of the heap
    heaparray = new int[capacity];
    }
    //Get root , left child and right child to perform operations
    int parent(int index){ //takes index of the array to return parent element of the child located at heaparray[index]
    return (index-1)/2 ;  //return the parent element
    }

    int leftchild(int index){
    return (2*index + 1); //return the left child
    }

    int rightchild(int index){
    return (2*index + 2); //return the right child
    }

    //swap operation to keep the largest element at root
    void swapkey(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    }

    int getMax(){ //returns the maximum element in the heap
    maxify(0);
        return heaparray[0];
    }

    void insertKey(int key){
        if(heapsize==capacity){ // check whether heap is full or not, yes return
            cout<<"Heap is full. Flag Overflow"<<endl;
            return;
        }
        heapsize++;
        int i =  heapsize;
        heaparray[i] = key; // inserting key at the end
        //Check for violation in heap property
        while(i!=0 && heaparray[parent(i)] < heaparray[i]){
            swapkey(&heaparray[parent(i)], &heaparray[i]);
            i = parent(i);
        }
    }


    int removemax(){
        if(heapsize<0){
            cout<<"Heap Empty. Flag Underflow"<<endl;
            return -1;
        }
        if(heapsize==0){
                //heapsize--;
                int root = heaparray[heapsize--];

            return root;
        }
        int top = heaparray[0];
        heaparray[0]=heaparray[heapsize];
        --heapsize;
        maxify(0);
        return top;
    }
    void maxify(int index){
    int leftindex = leftchild(index);
    int rightindex = rightchild(index);
    int largestindex = index;
    if(leftindex <= heapsize && heaparray[leftindex] > heaparray[largestindex]){
       largestindex = leftindex;
       }
       if(rightindex <=heapsize && heaparray[rightindex] > heaparray[largestindex]){
       largestindex = rightindex;
       }

    //update the root
        if(largestindex!=index){
            swapkey(&heaparray[index], &heaparray[largestindex]);
            maxify(largestindex);
        }
    }


    void Heapsort(){
       int hsr[capacity];
       for(int i = capacity-1; i>=0;i--){
        hsr[i] = removemax();
       }
        cout<<"Sorted array is"<<endl;
        for (int i=0; i<capacity; ++i){
        cout << hsr[i] << " ";
        }
    cout << "\n";
    }

};
int main()
{

int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr)/sizeof(arr[0]);
MaxHeap hmax(n);
for(int i =0;i<n;i++){
    hmax.insertKey(arr[i]);
}
hmax.Heapsort();

return 0;

}



