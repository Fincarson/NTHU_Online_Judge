#include <iostream>
#include <string>
using namespace std;

struct Node{
    char ch;
    Node *pNext;
    Node *pPrev;
    Node(char x): ch(x), pNext(nullptr), pPrev(nullptr) {}
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

        pCurNode = nullptr;
        pDelNode = nullptr;
        newNode = nullptr;

        output = "";

        linked_list_size = 0;

        in_reverse_mode = false;
    }

    // Destructor
    ~DoublyLinkedList(){
        pCurNode = pDummyHead->pNext;
        while(pCurNode != pDummyHead && pCurNode != pDummyTail && pCurNode != nullptr){
            pDelNode = pCurNode;
            pCurNode = pCurNode->pNext;
            
            delete pDelNode;
            pDelNode = nullptr;
        }
        delete pDummyHead;
        delete pDummyTail;
        pDummyHead = nullptr;
        pDummyTail = nullptr;
        pCurNode = nullptr;
        pDelNode = nullptr;
        newNode = nullptr;
        linked_list_size = 0;
    }

    // Insert
    inline void Insert(char ch, int pos){
        newNode = new Node(ch);
        pCurNode = !in_reverse_mode ? pDummyHead : pDummyTail->pPrev;
        for(int i = 0; i < pos; i++) pCurNode = !in_reverse_mode ? pCurNode->pNext : pCurNode->pPrev;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;
        
        linked_list_size++;
    }

    // Insert Front
    inline void Insert_Front(char ch){
        newNode = new Node(ch);
        pCurNode = !in_reverse_mode ? pDummyHead : pDummyTail->pPrev;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        linked_list_size++;
    }

    // Insert Back
    inline void Insert_Back(char ch){
        newNode = new Node(ch);
        pCurNode = !in_reverse_mode ? pDummyTail->pPrev : pDummyHead;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        linked_list_size++;
    }

    // Delete
    inline void Delete(int pos){
        if(!linked_list_size) return;

        pCurNode = !in_reverse_mode ? pDummyHead->pNext : pDummyTail->pPrev;
        for(int i = 0; i < pos; i++) pCurNode = !in_reverse_mode ? pCurNode->pNext : pCurNode->pPrev;

        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext = nullptr;
        pCurNode->pPrev = nullptr;

        delete pCurNode;
        pCurNode = nullptr;

        linked_list_size--;
    }

    // Delete Front
    inline void Delete_Front(){
        if(!linked_list_size) return;

        pCurNode = !in_reverse_mode ? pDummyHead->pNext : pDummyTail->pPrev;

        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext = nullptr;
        pCurNode->pPrev = nullptr;

        delete pCurNode;
        pCurNode = nullptr;

        linked_list_size--;
    }

    // Delete Back
    inline void Delete_Back(){
        if(!linked_list_size) return;

        pCurNode = !in_reverse_mode ? pDummyTail->pPrev : pDummyHead->pNext;

        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext = nullptr;
        pCurNode->pPrev = nullptr;

        delete pCurNode;
        pCurNode = nullptr;

        linked_list_size--;
    }

    // Reverse
    inline void Reverse(){
        in_reverse_mode = !in_reverse_mode;
    }

    // Print
    inline void Print(){
        output.clear();
        output.reserve(linked_list_size);
        for(pCurNode = !in_reverse_mode ? pDummyHead->pNext : pDummyTail->pPrev; pCurNode != pDummyHead && pCurNode != pDummyTail && pCurNode != nullptr; pCurNode = !in_reverse_mode ? pCurNode->pNext : pCurNode->pPrev)
            output.push_back(pCurNode->ch);
        cout << output << '\n';
    }

private:
    Node *pDummyHead = nullptr;
    Node *pDummyTail = nullptr;
    Node *pCurNode = nullptr;
    Node *pDelNode = nullptr;
    Node *newNode = nullptr;

    string output = "";

    int linked_list_size = 0;

    bool in_reverse_mode = false;
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    DoublyLinkedList lst;
    string cmd = "x";
    char ch = 'x';
    int pos = 0;
    int T = 0;
    
    cin >> T;
    
    while(T--){
        cin >> cmd;
        if(cmd == "insert"){
            cin >> ch >> pos;
            lst.Insert(ch, pos);
        } else if(cmd == "insert_front"){
            cin >> ch;
            lst.Insert_Front(ch);
        } else if(cmd == "insert_back"){
            cin >> ch;
            lst.Insert_Back(ch);
        } else if(cmd == "delete"){
            cin >> pos;
            lst.Delete(pos);
        } else if(cmd == "delete_front"){
            lst.Delete_Front();
        } else if(cmd == "delete_back"){
            lst.Delete_Back();
        } else if(cmd == "reverse"){
            lst.Reverse();
        } else if(cmd == "print"){
            lst.Print();
        }
    }
    return 0;
}