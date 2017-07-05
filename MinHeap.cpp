/*Binary Min Heap using C++
The following operations are performed on the heap
getMin
removemin
updatekey
insert
delete

Heap is implemented by using array
*/
#include<iostream>
#include<climits>
using namespace std;

//class for the heap
class MinHeap{

int *heaparray; // pointer for the heap elements
int capacity; //denotes the maximum number of elements possibly stored in heap
int heapsize; //size for this heap

public:
    //constructor for the class
    MinHeap(int Capacity){
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

    //swap operation to keep the smallest element at root
    void swapkey(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    }

    int getMin(){ //returns the minimum element in the heap
    minify(0);
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
        while(i!=0 && heaparray[parent(i)] > heaparray[i]){
            swapkey(&heaparray[parent(i)], &heaparray[i]);
            i = parent(i);
        }
    }

    void updateKey(int index, int tempmin){
        if(heapsize< index){
            insertKey(tempmin);
        }
        heaparray[index] = tempmin; // replace the current value at the index by value less than root
        while(index!=0 && heaparray[parent(index)] > heaparray[index] ){
            swapkey(&heaparray[index], &heaparray[parent(index)]);
            index = parent(index);
        }


    }

    int removemin(){
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
        minify(0);
        return top;
    }
    void minify(int index){
    int leftindex = leftchild(index);
    int rightindex = rightchild(index);
    int smallestindex = index;
    if(leftindex <= heapsize && heaparray[leftindex] < heaparray[smallestindex]){
       smallestindex = leftindex;
       }
       if(rightindex <=heapsize && heaparray[rightindex] < heaparray[smallestindex]){
       smallestindex = rightindex;
       }

    //update the root
        if(smallestindex!=index){
            swapkey(&heaparray[index], &heaparray[smallestindex]);
            minify(smallestindex);
        }
    }


    void deleteKey(int index){
        updateKey(index, INT_MIN);
        removemin();

    }

};
int main()
{
MinHeap hmin(11);
hmin.insertKey(3) ;
hmin.insertKey(2);
cout<<hmin.removemin()<<endl;
cout<<hmin.removemin()<<endl;
hmin.insertKey(15);
hmin.insertKey(5);
hmin.insertKey(4);
cout<<hmin.removemin()<<endl;
hmin.insertKey(45);
cout<<hmin.removemin()<<endl;
cout<<hmin.removemin()<<endl;
cout<<hmin.getMin()<<endl;
hmin.updateKey(2,1);
cout<<"Minimum value in heap"<<endl;
cout<<hmin.getMin();

return 0;

}


