#ifndef DOUBLYLINKLEDLIST_H
#define DOUBLYLINKLEDLIST_H


namespace DOUBLY_LINKED_LIST {

template <typename Type>
struct nodeType {
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};

template <typename Type>
class DoubleLinkedList {
public:
    DoubleLinkedList();
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

private:
    nodeType<Type> *m_headDoublyLinkList;
};

template<typename Type>
DoubleLinkedList<Type>::DoubleLinkedList():m_headDoublyLinkList(0) {
}


template<typename Type>
bool DoubleLinkedList<Type>::searchList(const Type &value) {
    bool found = false;
    int location = 0;
    nodeType<Type> * itrList = m_headDoublyLinkList;
    while( itrList != 0 && found == false) {
        if (itrList->info == value)
            found = true;
        else
            itrList= itrList->next;

        location++;
    }

    cout<<" At location = "<<location<<"    ";
    return found;
}

template<typename Type>
bool DoubleLinkedList<Type>::isListEmpty() {
    return (m_headDoublyLinkList == 0) ? true :false;
}

template<typename Type>
int DoubleLinkedList<Type>::sizeList() {
    int sizeofList = 0;
    nodeType<int> * itrList = m_headDoublyLinkList;
    while( itrList != 0 ) {
        itrList= itrList->next;
        sizeofList++;
    }
    return sizeofList;
}

template<typename Type>
int DoubleLinkedList<Type>::deleteNode(const Type &value) {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    if (m_headDoublyLinkList->info == value) {
        deleteFirstNode();
        return 0;
    }

    nodeType<Type> * itrList = m_headDoublyLinkList;
    nodeType<Type> * trailitrList = 0;

    int iterations = 0;
    while( itrList->info != value) {
        trailitrList = itrList;
        itrList = itrList->next;
        iterations++;
    }

    if ( itrList->next == 0 && iterations == sizeList()) {
        deleteLastNode();
        return 0;
    }
    else {
        trailitrList->next = itrList->next;
        delete itrList;
    }

    return 0;
}

template<typename Type>
void DoubleLinkedList<Type>::addNodeAtEnd(const Type &value) {

    nodeType<Type> * nodeDoubleLinkList = new nodeType<Type>;

    bool firstElement = false;
    if (sizeList() == 0 ) {
        m_headDoublyLinkList = nodeDoubleLinkList;
        firstElement = true;
    }

    nodeType<Type> * itrList = m_headDoublyLinkList;
    while( itrList->next != 0) {
        itrList= itrList->next;
    }

    if (firstElement ) {
        nodeDoubleLinkList->back = 0;
    }
    else {
        nodeDoubleLinkList->back = itrList;
        itrList->next = nodeDoubleLinkList;
    }
    nodeDoubleLinkList->next = 0;
    nodeDoubleLinkList->info = value;
}

template<typename Type>
void DoubleLinkedList<Type>::printList() {

    nodeType<Type> * itrList = m_headDoublyLinkList;
    while( itrList != 0) {
        cout<<"   "<<itrList->info;
        itrList = itrList->next;
    }
    cout<<endl;
}

template<typename Type>
void DoubleLinkedList<Type>::addNodeAtStart(const Type &value) {

    nodeType<Type> * nodeDoubleLinkList = new nodeType<Type>;
    nodeDoubleLinkList->info = value;
    nodeDoubleLinkList->back = 0;
    nodeDoubleLinkList->next = m_headDoublyLinkList;
    m_headDoublyLinkList = nodeDoubleLinkList;
}

template<typename Type>
int DoubleLinkedList<Type>::inserNodeAfter(const Type &value, const Type &newValue) {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headDoublyLinkList;

    int iterations = 0;
    while( itrList->info != value) {
        itrList = itrList->next;
        iterations++;
    }

    if ( itrList->next == 0 && iterations == sizeList()) {
        addNodeAtEnd(newValue);
        return 0;
    }
    else {
        nodeType<Type> * nodeLinkList = new nodeType<Type>;
        nodeLinkList->info = newValue;
        nodeLinkList->next = itrList->next;
        nodeLinkList->back = itrList;
        itrList->next = nodeLinkList;
    }
    return 0;
}

template<typename Type>
int DoubleLinkedList<Type>::deleteFirstNode() {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headDoublyLinkList;

    m_headDoublyLinkList = itrList->next;
    delete itrList;

    return 0;
}

template<typename Type>
int DoubleLinkedList<Type>::deleteLastNode() {

    if(!sizeList()) {
        cout<<" List Empty"<<endl;
        return 0;
    }

    nodeType<Type> * itrList = m_headDoublyLinkList;
    nodeType<Type> * trailitrList = 0;

    while( itrList->next != 0) {
        trailitrList = itrList;
        itrList = itrList->next;
    }

    // can be done with out trailing pointer also..... by following method......
    // itrList->back->next = 0;
    trailitrList->next = 0;
    delete itrList;

    return 0;
}
}
#endif // DOUBLYLINKLEDLIST_H
