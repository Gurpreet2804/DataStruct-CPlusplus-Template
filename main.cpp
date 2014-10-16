#include "LinkedList.h"
#include "DoublyLinkledList.h"
#include "EightQueensPuzz.h"
#include "binaryTreeType.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int largestOfArrrayRecursive(const int list[], int lowerIndex, int upperIndex) {

    int max;
    if (lowerIndex == upperIndex)
        return list[lowerIndex];

    else {
        max = largestOfArrrayRecursive(list,lowerIndex + 1,upperIndex);

        if ( list[lowerIndex] > max ) {
            return list[lowerIndex];
        }
        else
            return max;
    }
}

int mergeArrays(const int arr1[],int arr1Size , const int arr2[],int arr2Size, int destArr[],int destSize) {

    int i=0;
    int j=0;
    int k=0;

    while(i<arr1Size && j<=arr2Size)
    {
        cout<<" I = "<<i<<" J = "<<j;
        if(arr1[i] <= arr2[j])
        {
            destArr[k]=arr1[i];
            i++;k++;
        }
        else
        {
            destArr[k]=arr2[j];
            k++;j++;
        }
    }

    for(int unsigned k = 0; k< 8;k++) {
        cout<<" Dest = "<<destArr[k]<<endl;
    }


    return EXIT_SUCCESS;
}

int dectobin( int num, int base) {
    if ( num > 0 ) {
        dectobin(num / 2 ,base);
        cout << num % base;
    }
}

void moveDisks(int count, int needle1, int needle3, int needle2)
{
    if (count > 0)
    {
        cout<<"\n In Move Disk = " <<count<<"  Needle 1 = "<<needle1<<" Needle 2 = "<<needle2<<" Needle 3 = "<<needle3<<endl;
        moveDisks(count - 1, needle1, needle2, needle3);
        cout << "Move disk " << count << " from " << needle1
             << " to " << needle3 << "." << endl;
        moveDisks(count - 1, needle2, needle3, needle1);
        cout<<" After last move"<<endl;
    }
}


int main()
{

#if 0  // doubly Linked list

    cout << " Doubly Linked List" << endl;
    DOUBLY_LINKED_LIST::DoubleLinkedList<int> * objdoubleList = new DOUBLY_LINKED_LIST::DoubleLinkedList<int>;
    objdoubleList->addNodeAtEnd(2);
    objdoubleList->addNodeAtEnd(3);
    objdoubleList->addNodeAtEnd(55);
    objdoubleList->addNodeAtEnd(6);
    objdoubleList->addNodeAtEnd(7);
    objdoubleList->addNodeAtEnd(23);
    objdoubleList->addNodeAtStart(0);
    objdoubleList->inserNodeAfter(0,111);
    objdoubleList->inserNodeAfter(111,222);
    objdoubleList->inserNodeAfter(23,333);

    cout<<" Size = "<<objdoubleList->sizeList()<<endl;
    objdoubleList->printList();


    objdoubleList->deleteFirstNode();
    //  objdoubleList->deleteLastNode();
    cout<<" Size = "<<objdoubleList->sizeList()<<endl;
    objdoubleList->printList();

    objdoubleList->deleteLastNode();
    cout<<" Size = "<<objdoubleList->sizeList()<<endl;
    objdoubleList->printList();

    objdoubleList->deleteNode(6);
    cout<<" Size = "<<objdoubleList->sizeList()<<endl;
    objdoubleList->printList();

    cout<<objdoubleList->searchList(6)<<endl;
    objdoubleList->printList();

    cout<<objdoubleList->searchList(111)<<endl;
    objdoubleList->printList();

#endif
#if 0 // Linked list
    cout << "Linked List" << endl;

    LINKED_LIST::LinkedList<int> * objlinkList = new LINKED_LIST::LinkedList<int>;

    objlinkList->addNodeAtEnd(2);
    objlinkList->addNodeAtEnd(3);
    objlinkList->addNodeAtEnd(55);

    objlinkList->addNodeAtEnd(1);
    objlinkList->addNodeAtEnd(111);
    objlinkList->addNodeAtStart(123);
    objlinkList->addNodeAtEnd(98);
    objlinkList->addNodeAtStart(456);

    cout.setf(ios::boolalpha);
    cout<<" Size = "<<objlinkList->sizeList()<<endl;
    objlinkList->printList();

    cout<<endl;

    objlinkList->inserNodeAfter(456,25);

    cout<<" Size = "<<objlinkList->sizeList()<<endl;
    objlinkList->printList();

    cout<<endl;

    objlinkList->deleteNode(123);
    objlinkList->deleteNode(456);


    cout<<" Size = "<<objlinkList->sizeList()<<endl;
    objlinkList->printList();

    objlinkList->printListReverseRecursive();
#endif

#if 0

    int intArray[10] = {23, 43, 35, 38, 67, 12, 5, 10, 34, 8};
    cout << "The largest element in intArray: "    << largestOfArrrayRecursive(intArray, 0, 9);

#endif
#if 0
    moveDisks(2,1,3,2);

    dectobin(11,2);
#endif
#if 0
    nQueensPuzzle obj(4);
    obj.queensConfiguration(0);
    obj.printConfiguration();
#endif

#if 0
    BINARY_TREE::binaryTreeType<int>  * objBinaryTree = new BINARY_TREE::binaryTreeType<int>;

    objBinaryTree->insert(60);
    objBinaryTree->insert(50);
    objBinaryTree->insert(70);
    objBinaryTree->insert(30);
    objBinaryTree->insert(53);
    objBinaryTree->insert(80);
    objBinaryTree->insert(35);
    objBinaryTree->insert(57);
    objBinaryTree->insert(75);
    objBinaryTree->insert(32);
    objBinaryTree->insert(77);
    objBinaryTree->insert(48);
    objBinaryTree->insert(45);

    objBinaryTree->postorderTraversal();

    cout<<" Non Recursive "<<endl;

    objBinaryTree->nonRecursivePostorderTraversal();
    // objBinaryTree->inorderTraversal();
    cout<<endl;

    // cout<<boolalpha<<objBinaryTree->search(53);
    // cout<<objBinaryTree->treeHeight();
#endif
    return 0;
}

