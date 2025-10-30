#include <iostream>
#include <string>
using namespace std;

struct Node{
    int num;
    Node *pNext;
    Node *pPrev;
    Node(int x): num(x), pNext(nullptr), pPrev(nullptr) {}
};

class QueueLine{
public:
    // Constructor
    QueueLine(){
        pDummyHead = new Node(-1);
        pDummyTail = new Node(-1);
        pDummyHead->pNext = pDummyTail;
        pDummyHead->pPrev = pDummyTail;
        pDummyTail->pNext = pDummyHead;
        pDummyTail->pPrev = pDummyHead;

        pCurNode = nullptr;
        pDelNode = nullptr;
        newNode = nullptr;

        queue_size = 0;
    }

    // Destructor
    ~QueueLine(){
        pCurNode = pDummyHead->pNext;
        while(pCurNode != pDummyTail && pCurNode){
            pDelNode = pCurNode;
            pCurNode = pCurNode->pNext;

            pDelNode->pPrev->pNext = pDelNode->pNext;
            pDelNode->pNext->pPrev = pDelNode->pPrev;
            pDelNode->pNext = nullptr;
            pDelNode->pPrev = nullptr;

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

        queue_size = 0;
    }

    // New Normal Customer
    inline void NewNormalCustomer(int N){
        newNode = new Node(N);
        pCurNode = pDummyTail->pPrev;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        queue_size++;
    }

    // New Selfish Customer
    inline void NewSelfishCustomer(int N, int P){
        newNode = new Node(N);
        pCurNode = pDummyHead;
        while(P--) pCurNode = pCurNode->pNext;

        newNode->pNext = pCurNode->pNext;
        newNode->pPrev = pCurNode;
        pCurNode->pNext->pPrev = newNode;
        pCurNode->pNext = newNode;

        queue_size++;
    }

    // Done Customer
    inline void DoneCustomer(){
        if(!queue_size) return;
        pCurNode = pDummyHead->pNext;

        pCurNode->pPrev->pNext = pCurNode->pNext;
        pCurNode->pNext->pPrev = pCurNode->pPrev;
        pCurNode->pNext = nullptr;
        pCurNode->pPrev = nullptr;
        
        delete pCurNode;
        pCurNode = nullptr;

        queue_size--;
    }

    // Print
    inline void Print(){
        for(pCurNode = pDummyHead->pNext; pCurNode != pDummyTail && pCurNode; pCurNode = pCurNode->pNext){
            cout << pCurNode->num;
            if(pCurNode->pNext && pCurNode->pNext != pDummyTail) cout << " ";
        }
        cout << '\n';
    }

private:
    Node *pDummyHead = nullptr;
    Node *pDummyTail = nullptr;
    Node *pCurNode = nullptr;
    Node *pDelNode = nullptr;
    Node *newNode = nullptr;

    int queue_size = 0;
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 0; cin >> T;
    int N = 0, P = 0;

    QueueLine Queue;
    string cmd;

    while(T--){
        cin >> cmd;
        if(cmd == "new_normal_customer"){
            cin >> N;
            Queue.NewNormalCustomer(N);
        } else if(cmd == "new_selfish_customer"){
            cin >> N >> P;
            Queue.NewSelfishCustomer(N, P);
        } else if(cmd == "done_customer"){
            Queue.DoneCustomer();
        } else if(cmd == "print"){
            Queue.Print();
        }
    }
    return 0;
}