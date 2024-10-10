/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;



//###INSERT CODE HERE -

typedef struct PROVINCE{
    int id, pop;
    string ten;
    double area;
}pro;

struct node {
    pro info;
    node* next;
};
struct List{
    node *head, *tail;
};

node *get_node(pro x){
	node *p = new node;
	p->info = x;
	p->next = nullptr;
	return p;
}

void add_tail(List &L, pro x) {
	node *p = get_node(x);
	if(L.head == nullptr) {
		L.head = L.tail = p;
	} else {
		L.tail->next = p;
		p->next = nullptr;
		L.tail = p;
	}
}

void inputProvinces(pro &x){
    cin >> x.id;
    cin.ignore();
    getline(cin, x.ten);
    cin >> x.pop;
    cin >> x.area;
}
void outputProvince(pro x){
    cout << x.id << '\t' << x.ten << '\t' << x.pop << '\t' << x.area << endl;
}


void inputListProvinces(List &l){
    int n; cin >>  n;
    for(int i = 0; i < n; i++){
        pro x;
        inputProvinces(x);
        add_tail(l, x);
    }
}
void outputListProvinces(List l) {
    node *p = l.head;
    while(p){
        outputProvince(p->info);
        p = p->next;
    }
}
void Init(List &l){
    l.head = l.tail = nullptr;
}

void outputProvincesMore1MillionPop(List &l){
    node *p = l.head;
    while(p){
        if(p->info.pop > 1000){
            outputProvince(p->info);
        }
        p = p->next;
    }
}
node *findProMaxArea(List l){
    if(l.head == nullptr){
        return nullptr;
    }
    node *max = l.head;
    node *p = l.head;
    while(p){
        if(p->info.area > max->info.area) max = p;
        p = p->next;
    }
    return max;
}

int main()
{
    // pro x;
    // inputProvinces(x);
    // outputProvinces(x);
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}


