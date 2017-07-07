#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Huffman{
    //Huffman tree
    struct huftree
    {
        char data;
        unsigned freq;
        huftree *left, *right;

        huftree(char data,unsigned freq)
        {
            left=right = NULL;
            this->data = data;
            this->freq =freq;
        }
    };

    struct hufheap
    {
        unsigned hsize, capacity;
        struct huftree** harray;

        hufheap(unsigned capacity)
        {
            hsize = -1;
            this->capacity =capacity;
            this->harray = new huftree*[capacity*sizeof(huftree)];
        }
    };
public:
    void swapnodes(huftree** x, huftree**  y)
    {
        huftree* temp = *x;
        *x=*y;
        *y =temp;

    }
    int parent(int index)
    { //takes index of the array to return parent element of the child located at heaparray[index]
        return (index-1)/2 ;  //return the parent element
    }

    int leftchild(int index)
    {
        return (2*index + 1); //return the left child
    }

    int rightchild(int index)
    {
        return (2*index + 2); //return the right child
    }
    void minHeapify(hufheap* minHeap, int index)
    {
        int smallest = index;
        int left = leftchild(index);
        int right = rightchild(index);

        if (left <=minHeap->hsize && minHeap->harray[left]->freq < minHeap->harray[smallest]->freq)
        {
            smallest = left;
        }

        if (right <=minHeap->hsize && minHeap->harray[right]->freq < minHeap->harray[smallest]->freq)
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swapnodes(&minHeap->harray[smallest], &minHeap->harray[index]);
            minHeapify(minHeap, smallest);
        }
    }

    huftree* extractmin(hufheap* heap)
    {

        if(heap->hsize==0)
        {
            return heap->harray[heap->hsize--];
        }
        huftree* top = heap->harray[0];
        heap->harray[0] = heap->harray[heap->hsize];
        --heap->hsize;
        minHeapify(heap,0);
        return top;
    }
    void insertHeap(hufheap* heap, huftree* node)
    {
        if(heap->hsize==heap->capacity)
        {
            cout<<"Heap Overflow"<<endl;
            return;
        }
        heap->hsize++;
        unsigned i = heap->hsize;
        heap->harray[i]=node;
        while(i!=0 &&heap->harray[parent(i)]->freq > heap->harray[i]->freq)
        {
            swapnodes(&heap->harray[parent(i)],&heap->harray[i]);
            i =  parent(i);
        }
    }
    void printEncodes(huftree* root, string top)
    {
        if(!root)
        {
            return;
        }
        if(root->data!='$')
        {
            cout<<root->data<<":"<<top<<endl;

        }
        printEncodes(root->left,top+"0");
        printEncodes(root->right,top+"1");
    }
    void ihuff(char data[], int freq[],int hsize)
    {
        huftree *top, *lefti, *righti;
        hufheap *heap = new hufheap(hsize);
        for(int i=0;i<hsize;++i)
        {
            insertHeap(heap,new huftree(data[i],freq[i]));
        }

        while(heap->hsize!=0)
        {
            lefti = extractmin(heap);
            righti =extractmin(heap);
            top = new huftree('$',lefti->freq + righti->freq);
            top->left=lefti;
            top->right=righti;
            insertHeap(heap,top);
        }
        cout<<"Printing Codes"<<endl;
        printEncodes(top,"");

    }
};

int main()
{
    char harray[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int hsize = sizeof(harray) / sizeof(harray[0]);
    Huffman hf;
    hf.ihuff(harray,freq,hsize);

    return 0;
}
