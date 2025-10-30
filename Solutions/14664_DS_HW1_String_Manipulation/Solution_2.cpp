#include <iostream>
#include <string>
using namespace std;

struct Node{
    char ch;
    Node *pNext;
    Node *pPrev;
    Node(char x): ch(x), pNext(nullptr), pPrev(nullptr) {}
};

class CircularLinkedList{
public:
    // Contructor
    CircularLinkedList(){
        pDummyHead = new Node('x');
        pDummyHead->pNext = pDummyHead;
        pDummyHead->pPrev = pDummyHead;
        pCurNode = pDummyHead;
        pDeleteNode = pDummyHead;
        newNode = nullptr;

        i = 0;
        linked_list_size = 0;
        middle_position = 0;

        in_reverse_mode = false;
        use_back = false;

        output = "";
    }

    // Destructor
    ~CircularLinkedList(){
        pDeleteNode = pDummyHead->pNext;
        while(pDeleteNode != pDummyHead){
            pCurNode = pDeleteNode->pNext;
            delete pDeleteNode;
            pDeleteNode = pCurNode;
        }
        delete pDummyHead;
        pDummyHead = nullptr;
        pCurNode = nullptr;
        pDeleteNode = nullptr;
        newNode = nullptr;
    }

    // Insert
    inline void Insert(char ch, int pos){
        newNode = new Node(ch);

        pos = !in_reverse_mode ? pos : linked_list_size - pos;
        use_back = (pos > middle_position);

        if(!use_back){
            pCurNode = pDummyHead;
            for(i = 0; i < pos; i++) pCurNode = pCurNode->pNext;
        } else {
            pCurNode = pDummyHead->pPrev;
            for(i = 0; i < linked_list_size - pos; i++) pCurNode = pCurNode->pPrev;
        }

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        linked_list_size++;
        middle_position = linked_list_size >> 1;
        use_back = false;
    }

    // Insert Front
    inline void Insert_Front(char ch){
        newNode = new Node(ch);
        pCurNode = !in_reverse_mode ? pDummyHead : pDummyHead->pPrev;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        linked_list_size++;
        middle_position = linked_list_size >> 1;
    }

    // Insert Back
    inline void Insert_Back(char ch){
        newNode = new Node(ch);
        pCurNode = !in_reverse_mode ? pDummyHead->pPrev : pDummyHead;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        linked_list_size++;
        middle_position = linked_list_size >> 1;
    }

    // Delete
    inline void Delete(int pos){
        if(!linked_list_size) return;

        pos = !in_reverse_mode ? pos : linked_list_size - pos - 1;
        use_back = (pos > middle_position);

        if(!use_back){
            pCurNode = pDummyHead->pNext;
            for(i = 0; i < pos; i++) pCurNode = pCurNode->pNext;
        } else {
            pCurNode = pDummyHead->pPrev;
            for(i = 0; i < linked_list_size - pos - 1; i++) pCurNode = pCurNode->pPrev;
        }

        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pNext = nullptr;
        pCurNode->pNext = nullptr;

        delete pCurNode;
        pCurNode = pDummyHead;

        linked_list_size--;
        middle_position = linked_list_size >> 1;
    }

    // Delete Front
    inline void Delete_Front(){
        if(!linked_list_size) return;

        pCurNode = !in_reverse_mode ? pDummyHead->pNext : pDummyHead->pPrev;

        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pNext = nullptr;
        pCurNode->pNext = nullptr;

        delete pCurNode;
        pCurNode = pDummyHead;

        linked_list_size--;
        middle_position = linked_list_size >> 1;
    }

    // Delete Back
    inline void Delete_Back(){
        if(!linked_list_size) return;

        pCurNode = !in_reverse_mode ? pDummyHead->pPrev : pDummyHead->pNext;

        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pNext = nullptr;
        pCurNode->pNext = nullptr;

        delete pCurNode;
        pCurNode = pDummyHead;

        linked_list_size--;
        middle_position = linked_list_size >> 1;
    }

    // Reverse
    inline void Reverse(){
        in_reverse_mode = !in_reverse_mode;
    }

    // Print
    inline void Print(){
        output.clear();
        output.reserve(linked_list_size);
        for(pCurNode = !in_reverse_mode ? pDummyHead->pNext : pDummyHead->pPrev; pCurNode != pDummyHead && pCurNode != nullptr; pCurNode = !in_reverse_mode ? pCurNode->pNext : pCurNode->pPrev)
            output.push_back(pCurNode->ch);
        cout << output << '\n';
    }


private:
    Node *pDummyHead = nullptr;
    Node *pCurNode = nullptr;
    Node *pDeleteNode = nullptr;
    Node *newNode = nullptr;

    string output;

    int linked_list_size = 0;
    int middle_position = 0;
    int i = 0;

    bool in_reverse_mode = false;
    bool use_back = false;
};



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    string cmd;
    char ch; int pos;
    CircularLinkedList lst;

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