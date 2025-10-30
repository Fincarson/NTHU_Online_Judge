#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

typedef struct _family{
    int id;
    int people;
    int price;
    int waitTime;
    bool isGogo;
    bool isSpecial;
    struct _family *next;
    struct _family *prev;
}Node;

Node* addFamily (int *uniqueID, int A, int P, int place){
    Node *newFam = new Node;

    newFam->id = uniqueID[place]++;
    newFam->people = A;
    newFam->price = P;
    newFam->waitTime = 0;
    newFam->isGogo = (A >= 100) ? true : false;
    newFam->isSpecial = false;
    newFam->next = NULL;
    newFam->prev = NULL;

    return newFam;
}

void scanInput(Node **queueLine, Node **backLine, Node **registered, Node **noQuitZone, Node **firstNode, int *amountNodes, int *uniqueID, int *totalInQueue, int place, int X) {
    string input, syntax;
    getline(cin, input);
    if(input == "0" || input == "0 ") return;

    int A = 0, P = 0;
    Node *temp = NULL;
    stringstream input_stream(input);
    while(input_stream >> syntax){
        A = 0; P = 0;
        int coma = syntax.find(",");
        A = stoi(syntax.substr(0,coma));
        P = stoi(syntax.substr(coma + 1));
        temp = addFamily(uniqueID, A, P, place);

        totalInQueue[place] += temp->people;
        amountNodes[place]++;
        if(!queueLine[place] || !backLine[place]) {
            queueLine[place] = backLine[place] = temp;
            if(registered[place]){
                temp->prev = registered[place];
                registered[place]->next = temp;
            }
        }else{
            backLine[place]->next = temp;
            temp->prev = backLine[place];
            backLine[place] = temp;
        }
        if(!firstNode[place]) firstNode[place] = temp;
        if((X+1) == amountNodes[place]) noQuitZone[place] = backLine[place];
        else if(amountNodes[place] < (X+1)) noQuitZone[place] = NULL;
        else if(amountNodes[place] > (X+1)) noQuitZone[place] = noQuitZone[place];
    }
    return;
}


void registerFamily(Node **queueLine, Node **backLine, Node **registered, Node **noQuitZone, Node **specialFamily, bool *specialAssigned, int *amountNodes, int *totalMoney, int *totalPeople, int *totalInQueue, int *registerTime, int place){
    if(!queueLine[place]) return;
    if(registerTime[place] == 1) {registerTime[place]++; return;}
    else registerTime[place] = 1;

    totalMoney[place] += (!queueLine[place]->isSpecial) ? queueLine[place]->price : 0;
    totalPeople[place] += queueLine[place]->people;

    totalInQueue[place] -= queueLine[place]->people;
    amountNodes[place]--;

    if(queueLine[place]->isSpecial) specialAssigned[place] = false;
    registered[place] = queueLine[place];
    queueLine[place] = (queueLine[place]->next) ? queueLine[place]->next : NULL;
    noQuitZone[place] = (noQuitZone[place] && noQuitZone[place]->next) ? noQuitZone[place]->next : NULL;
    if(!queueLine[place]) backLine[place] = NULL;

    return;
}

void updateWaitTime(Node **queueLine, int place){
    if(!queueLine[place]) return;

    for(Node *cur = queueLine[place]; cur; cur = cur->next) cur->waitTime++;

    return;
}

void handleQuitting(Node **queueLine, Node **backLine, Node **noQuitZone, Node **specialFamily, int *amountNodes, int *totalQuit, int *totalInQueue, int X, int place){
    if(!queueLine[place] || !noQuitZone[place] || noQuitZone[place] == backLine[place]) return;

    Node *last = backLine[place];
    while(last->waitTime >= 60 && !last->isSpecial && last != noQuitZone[place]){
        if(last->isGogo){last = last->prev; continue;}
        totalQuit[place] += last->people;
        totalInQueue[place] -= last->people;
        amountNodes[place]--;

        if(backLine[place] == last){
            backLine[place] = backLine[place]->prev;
            backLine[place]->next = NULL;
            delete(last); last = backLine[place];
        }else{
            Node *temp = last;
            last = last->prev;
            last->next = temp->next;
            temp->next->prev = last;
            delete (temp); temp = NULL;
        }
    }
    return;
}

void checkSpecial(Node **queueLine, Node **backLine, Node**specialFamily, Node **firstNode, bool *specialAssigned, int place, int Y){
    if(specialAssigned[place] || !queueLine[place] || Y == -1) return;
    Node *pointerA = (specialFamily[place] && specialFamily[place]->next) ? specialFamily[place]->next : firstNode[place];
    Node *pointerB = (specialFamily[place] && specialFamily[place]->next) ? specialFamily[place]->next : firstNode[place];

    int sum = (specialFamily[place] && specialFamily[place]->next) ? specialFamily[place]->next->price : firstNode[place]->price;
    while(sum != Y && pointerA && pointerB){
        if(sum < Y){
            pointerA = pointerA->next;
            sum += (pointerA) ? pointerA->price : 0;
        }
        if(sum > Y){
            if(pointerA == pointerB){
                pointerA = pointerA->next;
                sum += (pointerA) ? pointerA->price : 0;
            }else{
                sum -= (pointerB) ? pointerB->price : 0;
                pointerB = pointerB->next;
            }
        }
    }if(sum == Y && pointerA && pointerA->next){
        specialFamily[place] = pointerA->next;
        specialFamily[place]->isSpecial = true;
        specialAssigned[place] = true;
        if(specialFamily[place]->isGogo) specialFamily[place]->isGogo = false;
    }
    return;
}

void printSummary(Node **registered, int *totalMoney, int *totalPeople, int *totalQuit, int* totalInQueue, int place){
    cout << "Place " << place << " Summary" << endl;
    cout << "Total Money: " << totalMoney[place] << endl;
    cout << "Total People Entered: " << totalPeople[place] << endl;
    cout << "Total People Quit: " << totalQuit[place] << endl;
    cout << "Current People Queuing: " << totalInQueue[place] << endl << endl;

    cout << "Entered Families :"; cout << endl;
    for(Node *cur = registered[place]; cur; cur = cur->prev)
        cout << "Family " << cur->id << " with " << cur->people << " people" << endl;
    cout << endl;

    return;
}

void deleteMemory(Node **queueLine, Node **backLine, Node **registered, int place){
    if(!queueLine[place]) return;

    Node *temp = NULL, *cur = NULL;
    for(cur = queueLine[place]; cur ;){
        temp = cur; cur = cur->next;
        delete(temp); temp = NULL;
    }

    for(cur = registered[place]; cur;){
        temp = cur; cur = cur->prev;
        delete(temp); temp = NULL;
    }
    return;
}

int main(void){
    int F, X, Y, M;
    cin >> F >> X >> Y >> M;

    Node **queueLine = new Node*[F+1];
    Node **backLine = new Node*[F+1];
    Node **registered = new Node*[F+1];
    Node **noQuitZone = new Node*[F+1];
    Node **specialFamily = new Node*[F+1];
    Node **firstNode = new Node*[F+1];
    bool *specialAssigned = new bool[F+1];

    int *totalMoney = new int[F+1];
    int *totalPeople = new int[F+1];
    int *totalQuit = new int[F+1];
    int *totalInQueue = new int[F+1];
    int *amountNodes = new int [F+1];
    int *uniqueID = new int[F+1];
    int *registerTime = new int[F+1];

    int i = 0;
    for(i = 0; i < F; i++){
        queueLine[i] = NULL; backLine[i] = queueLine[i]; registered[i] = NULL; firstNode[i] = NULL;
        noQuitZone[i] = NULL; specialFamily[i] = NULL; specialAssigned[i] = false;
        uniqueID[i] = 1; amountNodes[i] = 0;
        totalMoney[i] = 0; totalPeople[i] = 0;
        totalQuit[i] = 0; totalInQueue[i] = 0;
        registerTime[i] = 1;
    }

    for(int minute = 0; minute <= M; minute++){
        cin.ignore();
        for(i = 0; i < F; i++) registerFamily(queueLine, backLine, registered, noQuitZone, specialFamily, specialAssigned, amountNodes, totalMoney, totalPeople, totalInQueue, registerTime, i);
        for(i = 0; i < F; i++) handleQuitting(queueLine, backLine, noQuitZone, specialFamily, amountNodes, totalQuit, totalInQueue, X, i);
        for(i = 0; i < F; i++) scanInput(queueLine, backLine, registered, noQuitZone, firstNode, amountNodes, uniqueID, totalInQueue, i, X);
        for(i = 0; i < F; i++) checkSpecial(queueLine, backLine, specialFamily, firstNode, specialAssigned, i, Y);
        for(i = 0; i < F; i++) updateWaitTime(queueLine, i);
    }

    for(i = 0; i < F; i++) printSummary(registered, totalMoney, totalPeople, totalQuit, totalInQueue, i);
    for(i = 0; i < F; i++) deleteMemory(queueLine, backLine, registered, i);
    delete[]queueLine; delete[]backLine; delete[]registered; delete[]noQuitZone;
    delete[]specialFamily; delete[]specialAssigned; delete[]firstNode;
    delete[]totalMoney; delete[]totalPeople;
    delete[]totalQuit; delete[]totalInQueue;
    delete[]amountNodes; delete[]uniqueID;
    delete[]registerTime;

    return 0;
}
