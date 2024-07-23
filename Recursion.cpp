//                  Recursion 
// #include <iostream>
/*call stack -> output
Three
Two
One
*/
/*using namespace std;


void funcThree() {
    cout << "Three" << endl;
}

void funcTwo() {
    funcThree();
    cout << "Two" << endl;
}

void funcOne() {
    funcTwo();
    cout << "One" << endl;
}


int main() {

    funcOne();

}
*//*
#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{

    cout << factorial(4);
}*/
//              Recursive BST
#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }

        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

 bool rContains(Node* currentNode, int value) {
            if (currentNode == nullptr) return false;
            
            if (currentNode->value == value) return true;
            
            if (value < currentNode->value) {
                return rContains(currentNode->left, value);
            } else {
                return rContains(currentNode->right, value);
            }
        }
        bool rContains(int value) { 
            return rContains(root, value); 
        } 
    Node* rInsert(Node* currentNode, int value) {
            if (currentNode == nullptr) return new Node(value);
        
            if (value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            } else if (value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            } 
            return currentNode;
        }
        void rInsert(int value) { 
            if (root == nullptr) root = new Node(value);
            rInsert(root, value); 
        } 
        int minValue(Node* currentNode) {
            while (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        } 
        Node* deleteNode(Node* currentNode,int value){
            if(currentNode==nullptr)return nullptr;
            if(value<currentNode->value){
                currentNode->left=deleteNode(currentNode->left,value);
            }else if(value>currentNode->value){
                currentNode->right=deleteNode(currentNode->right,value);
            }else{
                if(currentNode->left==nullptr&&currentNode->right==nullptr){
                    delete(currentNode);
                    return nullptr;
                }else if(currentNode->left==nullptr){
                    Node* temp=currentNode->right;
                    delete(currentNode);
                    return temp;
                }else if(currentNode->right==nullptr){
                    Node* temp=currentNode->left;
                    delete(currentNode);
                    return temp;
                }else{
                    int subTreeMin=minValue(currentNode->right);
                    currentNode->value=subTreeMin;
                    currentNode->right=deleteNode(currentNode->right,value);
                }
            }
            return currentNode;
        }
        void deleteNode(int value){
            root=deleteNode(root,value);
        }
};


int main(){
BinarySearchTree* myBST=new BinarySearchTree();
myBST->insert(47);
myBST->insert(21);
myBST->insert(76);
myBST->insert(18);
myBST->insert(27);
myBST->insert(52);
myBST->insert(82);
cout<<"\nBST contains 27:\n";
cout<<myBST->rContains(27);
cout<<"\nBST contains 17:\n";
cout<<myBST->rContains(17);


BinarySearchTree* myBST1=new BinarySearchTree();
myBST1->insert(2);
myBST1->insert(1);
myBST1->insert(3);
cout<<"\n\n\n--BST1 Insert--\n Root: "<<myBST1->getRoot()->value;
cout<<"\nRoot->left: "<<myBST1->getRoot()->left->value;
cout<<"\nRoot->right: "<<myBST1->getRoot()->right->value;


BinarySearchTree* myBST2=new BinarySearchTree();
myBST2->insert(47);
myBST2->insert(21);
myBST2->insert(76);
myBST2->insert(18);
myBST2->insert(27);
myBST2->insert(52);
myBST2->insert(82);
cout<<"\n\n\n--BST2--\nMinValue from root:\n";
cout<<myBST2->minValue(myBST2->root);
cout<<"\nMinValue from root->right:\n";
cout<<myBST2->minValue(myBST2->root->right);


BinarySearchTree* myBST3=new BinarySearchTree();
myBST3->insert(2);
myBST3->insert(1);
myBST3->insert(3);
/*
          2
         / \
        1   3
*/
cout<<"\n\n\n--BST3--\nBefore deleting (2) Node:\n";
cout<<"---------------------------------------";
cout<<"\nRoot: "<<myBST3->getRoot()->value<<endl;
cout<<"\nRoot->left: "<<myBST3->getRoot()->left->value<<endl;
cout<<"\nRoot->right: "<<myBST3->getRoot()->right->value<<endl;

myBST3->deleteNode(2);
/*
          3
         / \
        1   nullptr
*/
cout<<"\n\nAfter deleting (2) Node:\n";
cout<<"---------------------------------------";
cout<<"\nRoot: "<<myBST3->getRoot()->value<<endl;
cout<<"\nRoot->left: "<<myBST3->getRoot()->left->value<<endl;
cout<<"\nRoot->right: "<<myBST3->getRoot()->right<<endl;
}