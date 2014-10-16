
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

//      Linkedlist      //
namespace LINKED_LIST {
template <typename Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template <typename Type>
class LinkedList {
public:
    LinkedList();
    void addNodeAtEnd(const Type & value);
    void addNodeAtStart(const Type & value);
    int  inserNodeAfter(const Type & value, const Type & newValue);
    int  deleteNode(const Type & value);
    int  deleteFirstNode();
    int  deleteLastNode();
    bool isListEmpty();
    void printList();
    bool searchList(const Type & value);
    int sizeList();
    void reversePrintRecursive(const nodeType<Type> *current) ;
    void printListReverseRecursive() {reversePrintRecursive(m_headLinkList);}

private:
    nodeType<Type> *m_headLinkList;
};

template <typename Type>
void LinkedList<Type>::reversePrintRecursive(const nodeType<Type> *current)
{
    if (current != NULL)
    {
        reversePrintRecursive(current->link);
        cout<<endl;
        cout << current->info << " ";
        //print the node
    }
}

template<typename Type>
LinkedList<Type>::LinkedList():m_headLinkList(0)
{
}

template<typename Type>
int LinkedList<Type>::sizeList() {
    int sizeofList = 0;
    nodeType<int> * itrList = m_headLinkList;
    while( itrList != 0 ) {
        itrList= itrList->link;
        sizeofList++;
    }
    return sizeofList;
}

template<typename Type>
inline void LinkedList<Type>::addNodeAtEnd(const Type &value) {

    nodeType<Type> * nodeLinkList = new nodeType<Type>;

    if (sizeList() == 0 )
        m_headLinkList = nodeLinkList;


    nodeType<Type> * itrList = m_headLinkList;
    while( itrList->link != 0) {
        itrList= itrList->link;
    }

    itrList->link = nodeLinkList;
    nodeLinkList->info = value;
    nodeLinkList->link = 0;
}

template<typename Type>
void LinkedList<Type>::printList() {

    nodeType<Type> * itrList = m_headLinkList;
    while( itrList != 0) {
        cout<<"   "<<itrList->info;
        itrList = itrList->link;
    }
}

template<typename Type>
bool LinkedList<Type>::isListEmpty() {
    return (m_headLinkList == 0) ? true :false;
}

template<typename Type>
bool LinkedList<Type>::searchList(const Type &value) {
    bool found = false;
    int location = 0;
    nodeType<Type> * itrList = m_headLinkList;
    while( itrList != 0 && found == false) {
        if (itrList->info == value)
            found = true;
        else
            itrList= itrList->link;

        location++;
    }

    cout<<" At location = "<<location<<"    ";
    return found;
}

template<typename Type>
void LinkedList<Type>::addNodeAtStart(const Type &value) {

    nodeType<Type> * nodeLinkList = new nodeType<Type>;
    nodeLinkList->info = value;
    nodeLinkList->link = m_headLinkList;
    m_headLinkList = nodeLinkList;
}

template<typename Type>
int LinkedList<Type>::deleteFirstNode() {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headLinkList;

    m_headLinkList = itrList->link;
    delete itrList;

    return 0;
}

template<typename Type>
int LinkedList<Type>::deleteLastNode() {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headLinkList;
    nodeType<Type> * trailitrList = 0;

    while( itrList->link != 0) {
        trailitrList = itrList;
        itrList = itrList->link;
    }

    trailitrList->link = 0;
    delete itrList;

    return 0;
}

template<typename Type>
int LinkedList<Type>::inserNodeAfter(const Type & value, const Type & newValue) {
    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headLinkList;

    int iterations = 0;
    while( itrList->info != value) {
        itrList = itrList->link;
        iterations++;
    }

    if ( itrList->link == 0 && iterations == sizeList()) {
        addNodeAtEnd(newValue);
        return 0;
    }
    else {
        nodeType<Type> * nodeLinkList = new nodeType<Type>;
        nodeLinkList->info = newValue;
        nodeLinkList->link = itrList->link;
        itrList->link = nodeLinkList;
    }
    return 0;
}

template<typename Type>
int LinkedList<Type>::deleteNode(const Type &value) {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    if (m_headLinkList->info == value) {
        deleteFirstNode();
        return 0;
    }

    nodeType<Type> * itrList = m_headLinkList;
    nodeType<Type> * trailitrList = 0;

    int iterations = 0;
    while( itrList->info != value) {
        trailitrList = itrList;
        itrList = itrList->link;
        iterations++;
    }

    if ( itrList->link == 0 && iterations == sizeList()) {
        deleteLastNode();
        return 0;
    }
    else {
        trailitrList->link = itrList->link;
        delete itrList;
    }

    return 0;
}
}
#endif // LINKEDLIST_H
