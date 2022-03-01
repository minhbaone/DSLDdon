/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
using namespace std;

struct NODE {
    int val;
    NODE *pnext;
};
struct LIST {
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &L){
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE *CreatNode(int x){
    NODE *p;
    p = new NODE;
    if(p == NULL) exit(1);
    p->val =x;
    p->pnext = NULL;
    return p;
}
void AddHead(LIST &L, int b){
    NODE *p = CreatNode(b);
    if(L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        p->pnext = L.pHead;
        L.pHead = p;
    }
}
void AddTail(LIST &L,NODE *p){
    if(L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        L.pTail ->pnext =p;
        L.pTail = p;
    }
}
void CreateList(LIST &L){
    int a,b;
    cin >> a >> b;
    do{
        if(a!=-1){
            if(a == 1) AddHead(L,b);
            else if(a==0) AddTail(L,CreatNode(b));
        }
    } while(a!= -1);
}
void PrintList(LIST L){
    NODE *p = L.pHead;
    if(p != NULL){
        while(p){
            cout << p->val << " ";
            p = p->pnext ;
        }
    } else cout << "Empty List.";
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList(L);

    return 0;
}
