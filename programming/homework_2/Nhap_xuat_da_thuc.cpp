#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


Node *get_donthuc(double hs, int sm) {
	Node *p = new Node;
	p->data = new DONTHUC;
	p->data->heso = hs;
	p->data->somu = sm;
	p->next = nullptr;
	return p;
}

void Nhap(DATHUC &l, double heso, int somu) {
    Node*p = get_donthuc(heso, somu);
    if (l.head == nullptr) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;   
        l.tail = p;
    }
}

void Xuat(DATHUC &l) {
	Node *p = l.head;
	while (p) {
		// if(p->data->heso == 0 && p == l.head){
		// 	cout << '0';
		// 	p = p->next;
		// 	continue;	
		// }
		if(p->data->heso == 0){
			p = p->next;
			continue;	
		}
		else if(p->data->heso == 1 && p->data->somu == 0) {
			cout << "+1";
			p = p->next;
			continue;
		}
		else if(p->data->heso == -1 && p->data->somu == 0) {
			cout << "-1";
			p = p->next;
			continue;
		}
		else if(p->data->heso == 1 && p != l.head) cout << '+';
		else if(p->data->heso == -1) cout << '-';
		else {
			if(p->data->heso > 0 && p == l.head) cout << p->data->heso;
			if(p->data->heso < 0) cout << p->data->heso;
			if(p->data->heso > 0 && p != l.head) cout << '+' << p->data->heso;
		}
		if(p->data->somu == 0) {
			p = p->next;
			continue;				
		}
		else if(p->data->somu == 1) cout << 'x';
		else {
			cout << "x^" << p->data->somu;
		}
		p = p->next;
	}
	p = l.head;
	while(p) {
		if(p->data->heso != 0)
			return;
		p = p->next;	
	}
	cout << '0';
}
double TinhDaThuc(DATHUC l, double x) {
	double sum = 0;
	Node *p = l.head;
	while(p) {
		sum += (p->data->heso) * pow(x, 1.0 * (p->data->somu)); 
		p = p->next;
	}
	return sum;
}



int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
