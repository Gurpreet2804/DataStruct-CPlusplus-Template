#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H
#include <iostream>

#include <vector>



//The definition of the typename binaryTreeType contains several member functions that
//are private members of the typename. These functions are used to implement the public
//member functions of the typename and the user need not know their existence

namespace BINARY_TREE {

template <typename elemType>
struct binaryTreeNode {
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

template <typename elemType>
class binaryTreeType {
public:
    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    //copy constructor
    binaryTreeType();
    //default constructor
    ~binaryTreeType();
    //destructor

    bool isEmpty() const;

    void inorderTraversal() const;
    void nonRecursiveInorderTraversal() const;

    void preorderTraversal() const;
    void nonRecursivePreorderTraversal() const;

    void postorderTraversal() const;
    void nonRecursivePostorderTraversal() const;

    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();

protected:
    binaryTreeNode<elemType> *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,  binaryTreeNode<elemType>* otherTreeRoot);
    void destroy(binaryTreeNode<elemType>* &p);

    void inorder(binaryTreeNode<elemType> *p) const;
    void nonRecursiveInorder(binaryTreeNode<elemType> *p) const;

    void preorder(binaryTreeNode<elemType> *p) const;
    void nonRecursivePreorder(binaryTreeNode<elemType> *p) const;

    void postorder(binaryTreeNode<elemType> *p) const;
    void nonRecursivePostorder(binaryTreeNode<elemType> *p) const;

    int height(binaryTreeNode<elemType> *p) const;
    int max(int x, int y) const;
    int nodeCount(binaryTreeNode<elemType> *p) const;
    int leavesCount(binaryTreeNode<elemType> *p) const;



public:
    bool search(const elemType& searchItem) const;
    void insert(const elemType& insertItem);
    void deleteNode(const elemType& deleteItem);

private:
    void deleteFromTree(binaryTreeNode<elemType>* &p , binaryTreeNode<elemType>* &pTrailing);

};



template<typename elemType>
bool binaryTreeType<elemType>::isEmpty() const{
    return root?true:false;
}

template <typename elemType>
binaryTreeType<elemType>::binaryTreeType() {
    root = NULL;
}

template <typename elemType>
binaryTreeType<elemType>::~binaryTreeType() {

}

template <typename elemType>
void binaryTreeType<elemType>::inorderTraversal() const {
    inorder(root);
}

template <typename elemType>
void binaryTreeType<elemType>::nonRecursiveInorderTraversal() const {
    nonRecursiveInorder(root);
}


template <typename elemType>
void binaryTreeType<elemType>::nonRecursivePreorderTraversal() const {
    nonRecursivePreorder(root);
}


template <typename elemType>
void binaryTreeType<elemType>::nonRecursivePostorderTraversal() const {
    nonRecursivePostorder(root);
}

template <typename elemType>
void binaryTreeType<elemType>::preorderTraversal() const {
    preorder(root);
}

template <typename elemType>
void binaryTreeType<elemType>::postorderTraversal() const {
    postorder(root);
}

template<typename elemType>
int binaryTreeType<elemType>::treeHeight() const {
    return height(root);
}

template <typename elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}
template <typename elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <typename elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const {
    if ( p == NULL ) {
        std::cout<<" Emtpy Tree"<<endl;
        return 0;
    }

    static int count = 0;

    // p->info =
    while( p != NULL) {

    }

    return count;
}

template <typename elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const {
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <typename elemType>
void binaryTreeType<elemType>::nonRecursiveInorder(binaryTreeNode<elemType> *p) const {


    std::vector<binaryTreeNode<elemType> *> stack;
    binaryTreeNode<elemType> *current;
    current = p;


    while( (current!= NULL) || (stack.size() != 0)) {
        if (current != NULL ) {
            stack.push_back(current);
            current = current->llink;
        }
        else {
            current = stack[stack.size()-1];
            stack.pop_back();
            cout<<current->info<<" ";
            current =  current->rlink;
        }
    }
    cout<<endl;
}

template <typename elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const {
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <typename elemType>
void binaryTreeType<elemType>::nonRecursivePreorder(binaryTreeNode<elemType> *p) const {
    std::vector<binaryTreeNode<elemType> *> stack;
    binaryTreeNode<elemType> *current;
    current = p;

    while( (current!= NULL) || (stack.size() != 0)) {
        if (current != NULL ) {
            cout<<current->info<<" ";
            stack.push_back(current);
            current = current->llink;
        }
        else {
            current = stack[stack.size()-1];
            stack.pop_back();
            current =  current->rlink;
        }
    }
    cout<<endl;
}
template <typename elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const {
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }
}

template <typename elemType>
void binaryTreeType<elemType>::nonRecursivePostorder(binaryTreeNode<elemType> *p) const {

    std::vector<binaryTreeNode<elemType> *> stack;
    binaryTreeNode<elemType> *current;
    binaryTreeNode<elemType> *prev = NULL;
    current = p;

    while( (current!= NULL) || (stack.size() != 0)) {
        if (current != NULL ) {
            stack.push_back(current);
            prev = current;
            current = current->llink;
        }
        else {
            current = stack[stack.size()-1];
            stack.push_back(current);
            prev = current;
            current =  current->rlink;
        }
        if ( prev->llink == NULL && prev->rlink == NULL) {
            stack.pop_back();
            cout<<prev->info<<" ";
            current = stack[stack.size()-1];

        }
    }

}


template <typename elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const {
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <typename elemType>
int binaryTreeType<elemType>::max(int x, int y) const {
    if (x >= y)
        return x;
    else
        return y;
}

template <typename elemType>
void binaryTreeType<elemType>::copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot) {
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template <typename elemType>
void binaryTreeType<elemType>::destroyTree() {
    destroy(root);
}


template <typename elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p) {
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template<typename elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> & otherTreeRoot) {
    if (otherTreeRoot.root == NULL) {
        root = NULL;
    }
    else {
        copyTree(this->root,otherTreeRoot.root);
    }
}

template<typename elemType>
const binaryTreeType<elemType> & binaryTreeType<elemType>::operator=(const binaryTreeType<elemType> & otherTreeRoot) {

    if (this != otherTreeRoot) {   // avoid self copy

        if (root !=NULL)
            destroy(root);

        if (otherTreeRoot.root == NULL) {
            root = NULL;
        }
    }
}


template<typename elemType>
bool binaryTreeType<elemType>::search(const elemType& searchItem) const {

    if (root == NULL ) {
        cout<<" Empty Tree"<<endl;
        return false;
    }

    bool found = false;

    binaryTreeNode<elemType> * current;
    current= root;


    while( current != NULL && found!= true) {

        if ( current->info == searchItem ) {
            found = true;
            break;
        }
        else if( current->info > searchItem) {
            current = current->llink;
        }
        else {
            current = current->rlink;
        }
    }
    return found;
}

template<typename elemType>
void binaryTreeType<elemType>::insert(const elemType& insertItem) {

    binaryTreeNode<elemType> * current;
    binaryTreeNode<elemType> * trailCurrent;
    binaryTreeNode<elemType> * newNode;

    newNode = new binaryTreeNode<elemType>;
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if( root == NULL) {
        root = newNode;
    }

    else {
        current = root;
        while ( current != NULL) {

            trailCurrent = current;

            if ( current->info == insertItem ) {
                cout<<" dublicate key can not exists "<<endl;
                return;
            }
            else if ( current->info > insertItem) {
                current = current->llink;
            }
            else {
                current = current->rlink;
            }
        }

        if (trailCurrent->info > insertItem) {
            trailCurrent->llink = newNode;
        }
        else {
            trailCurrent->rlink = newNode;
        }
    }
}

template<typename elemType>
void binaryTreeType<elemType>::deleteNode(const elemType& deleteItem) {
    if (root == NULL ) {
        cout<<" Empty Tree"<<endl;
        return;
    }

    bool found = false;

    binaryTreeNode<elemType> * current;
    binaryTreeNode<elemType> * trailCurrent;

    trailCurrent = NULL;
    current = root;
    while ((current!= NULL) & (found!=true)) {

        if ( current->info == deleteItem) {
            found = true;
        }
        else {
            trailCurrent = current;

            if (current->info > deleteItem)
                current = current->llink;
            else
                current = current->rlink;

        }
    }

    if (current == NULL ) {
        cout<<" Item Not is List"<<endl;
        return;
    }
    else if( found) {

        if ( trailCurrent->info > deleteItem )
            deleteFromTree(current,trailCurrent->llink );
        else
            deleteFromTree(current,trailCurrent->rlink );
    }
}

template<typename elemType>
void binaryTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p,binaryTreeNode<elemType>* &pTrailing) {

    binaryTreeNode<elemType> *current;//pointer to traverse the treedd
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *temp;
    //pointer to delete the node

    if ( p == NULL) {
        cout<<" Node is Null "<<endl;
    }

    else if(p->llink == NULL && p->rlink == NULL) // leaf
    {
        temp = p;
        p = NULL;
        delete temp;
        pTrailing = NULL;
    }

    else if(p->llink == NULL)
    {
        temp = p;
        pTrailing = temp->rlink;
        delete temp;
    }
    else if(p->rlink == NULL)
    {
        temp = p;
        pTrailing = temp->llink;
        delete temp;
    }
    else
    {
        trailCurrent = NULL;
        current = p->llink;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }

        p->info = current->info;
        if (trailCurrent == NULL) //current did not move;
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;

        delete current;
    }
}
}

#endif // BINARYTREETYPE_H
