/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


struct node {
    char info;
    node *next;
};

struct Stack {
    node *pHead;
};

void Init(Stack &S) {
    S.pHead = nullptr;
}

node* get_node(int x) {
    node*p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool isEmpty(Stack S) {
    if(!S.pHead)
        return true;
    return false;
}

void Push(Stack &S, int x) {
    node *p = get_node(x);
    if(isEmpty(S))
        S.pHead = p;
    else {
        p->next = S.pHead;
        S.pHead = p; 
    }
}

void Pop(Stack &S) {
    if(isEmpty(S))
        return;
    else {
        if(!S.pHead->next){
            S.pHead = nullptr;
        } else {
            node *p = S.pHead;
            S.pHead = S.pHead->next;
            p = nullptr;
        }
    }
}

bool isValid(string expr) {
    Stack S; Init(S);
    for(char ch : expr) {
        if(ch == '(' || ch == '{' || ch == '[')
            Push(S, ch);
        if(ch == ')' || ch == '}' || ch == ']'){
            node *p = S.pHead;
            if(isEmpty(S))
                return false;
            char topchar = S.pHead->info;
            if((ch == ')' && topchar != '(' )|| (ch == '}' && topchar != '{' ) || (ch == ']' && topchar != '[') )
                return false;
            Pop(S);
        }
    }
    return isEmpty(S);
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}


