#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *pNext;
    Node *pPrev;
    Node(char x) : data(x), pNext(nullptr), pPrev(nullptr) {}
};

class DoublyLinkedList{
public:
    // Constructor
    DoublyLinkedList(){
        pDummyHead = new Node('x');
        pDummyTail = new Node('x');

        pDummyHead->pNext = pDummyTail;
        pDummyHead->pPrev = pDummyTail;
        pDummyTail->pNext = pDummyHead;
        pDummyTail->pPrev = pDummyHead;
        pCurNode = pDummyHead;
        pNewNode = nullptr;

        output = "";
        in_reverse_mode = false;
        linked_list_size = 0;
    }

    // Decontructor
    ~DoublyLinkedList(){
        pDeleteNode = pDummyHead->pNext;
        while(pDeleteNode != pDummyTail){
            pCurNode = pDeleteNode->pNext;
            delete pDeleteNode;
            pDeleteNode = pCurNode;
        }
        delete pDummyHead;
        delete pDummyTail;
    }

    // Insert
    inline void Insert(char data, int pos){
        pCurNode = (!in_reverse_mode) ? pDummyHead : pDummyTail;
        while(pos--) pCurNode = (!in_reverse_mode) ? pCurNode->pNext : pCurNode->pPrev;

        pNewNode = new Node(data);
        linked_list_size++;
        if(!in_reverse_mode){
            pNewNode->pPrev = pCurNode;
            pNewNode->pNext = pCurNode->pNext;
            pCurNode->pNext->pPrev = pNewNode;
            pCurNode->pNext = pNewNode;
        } else {
            pNewNode->pNext = pCurNode;
            pNewNode->pPrev = pCurNode->pPrev;
            pCurNode->pPrev->pNext = pNewNode;
            pCurNode->pPrev = pNewNode;
        }
    }

    // Insert Front
    inline void Insert_Front(char data){
        pNewNode = new Node(data);
        linked_list_size++;

        if(!in_reverse_mode){
            pNewNode->pPrev = pDummyHead;
            pNewNode->pNext = pDummyHead->pNext;
            pDummyHead->pNext->pPrev = pNewNode;
            pDummyHead->pNext = pNewNode;
        } else {
            pNewNode->pNext = pDummyTail;
            pNewNode->pPrev = pDummyTail->pPrev;
            pDummyTail->pPrev->pNext = pNewNode;
            pDummyTail->pPrev = pNewNode;
        }
    }

    // Insert Back
    inline void Insert_Back(char data){
        pNewNode = new Node(data);
        linked_list_size++;

        if(!in_reverse_mode){
            pNewNode->pNext = pDummyTail;
            pNewNode->pPrev = pDummyTail->pPrev;
            pDummyTail->pPrev->pNext = pNewNode;
            pDummyTail->pPrev = pNewNode;
            
        } else {
            pNewNode->pPrev = pDummyHead;
            pNewNode->pNext = pDummyHead->pNext;
            pDummyHead->pNext->pPrev = pNewNode;
            pDummyHead->pNext = pNewNode;
        }
    }

    // Delete
    inline void Delete(int pos){
    if(!linked_list_size) return;
        pos++;
        pDeleteNode = (!in_reverse_mode) ? pDummyHead : pDummyTail;
        while(pos--) pDeleteNode = (!in_reverse_mode) ? pDeleteNode->pNext : pDeleteNode->pPrev;

        pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
        pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;
        
        delete pDeleteNode;
        pDeleteNode = nullptr;

        linked_list_size--;
    }

    // Delete Front
    inline void Delete_Front(){
        if(!linked_list_size) return;
        pDeleteNode = (!in_reverse_mode) ? pDummyHead->pNext : pDummyTail->pPrev;

        pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
        pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;
        
        delete pDeleteNode;
        pDeleteNode = nullptr;
        linked_list_size--;
    }

    // Delete Back
    inline void DeleteBack(){
        if(!linked_list_size) return;
        pDeleteNode = (!in_reverse_mode) ? pDummyTail->pPrev : pDummyHead->pNext;

        pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
        pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;
        
        delete pDeleteNode;
        pDeleteNode = nullptr;
        linked_list_size--;
    }

    // Reverse
    inline void Reverse(){
        in_reverse_mode = !in_reverse_mode;
    }

    // Print
    inline void Print() {
        output.clear(); output.reserve(linked_list_size);
        for (Node* cur = (!in_reverse_mode ? pDummyHead->pNext : pDummyTail->pPrev); cur != (!in_reverse_mode ? pDummyTail : pDummyHead); cur = (!in_reverse_mode ? cur->pNext : cur->pPrev)) output.push_back(cur->data);
        cout << output << '\n';
    }

private:
    Node *pDummyHead = nullptr;
    Node *pDummyTail = nullptr;
    Node *pCurNode = nullptr;
    Node *pNewNode = nullptr;
    Node *pDeleteNode = nullptr;
    string output = "";
    bool in_reverse_mode = false;
    int linked_list_size = 0;
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyLinkedList lst;
    string input;
    char chr;
    int pos, T;

    cin >> T;
    while(T--){
        cin >> input;
        if(input == "insert"){
            cin >> chr >> pos;
            lst.Insert(chr, pos);
        } else if(input == "insert_front"){
            cin >> chr;
            lst.Insert_Front(chr);
        } else if(input == "insert_back"){
            cin >> chr;
            lst.Insert_Back(chr);
        } else if(input == "delete"){
            cin >> pos;
            lst.Delete(pos);
        } else if(input == "delete_front"){
            lst.Delete_Front();
        } else if(input == "delete_back"){
            lst.DeleteBack();
        } else if(input == "reverse"){
            lst.Reverse();
        } else if(input == "print"){
            lst.Print();
        }
    }
    return 0;
}