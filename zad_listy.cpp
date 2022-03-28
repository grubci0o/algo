#include <iostream>
#include <cmath> //dla funckji abs
using namespace std;
struct node {
	int x;
	int y;
	node* next;

};
void addBegging(node*&head, int c, int d) {
	node*p = new node;
	p->x = c;
	p->y = d;
	p->next = head;
	head = p;


}
void show(node*head) {
	if (head == NULL) {
		cout << "Lista jest pusta" << endl;
	}
	node*p = head;
	while (p != NULL) {
		cout << '(' << p->x << ',' << p->y << ')' << "->";
		p = p->next;
	}
	cout << "NULL";
	cout << "\n";
}
void sum(node*head) {
	int sum_x = 0;
	int sum_y = 0;
	node*p = head;
	if (head == NULL) {
		return;
	}
	else
	{
		while (p != NULL) {
			sum_x = sum_x + p->x;
			sum_y = sum_y + p->y;
			p = p->next;


		}


	}
	cout << "Suma x to " << sum_x << endl;
	cout << "Suma y to " << sum_y << endl;

}
int maxDiff(node*head) {
	node*p = head;
	int diff = abs(p->y - p->x);
	while (p != NULL) {
		if (diff<abs(p->y - p->x)) {
			diff = abs(p->y - p->x);
		}
		p = p->next;


	}
	//cout<<"Maksymalna roznica to "<<diff;
	return diff;

}

void deleteDiff(node*&head) {
	int diff = maxDiff(head);
	if (head == NULL) {//pusta lista
		return;
	}
	else if (diff == head->y - head->x) {//usuwamy z poczatku
		node*d = head;
		head = head->next;
		delete d;
	}
	else {
		node*p = head;
		node*e = new node;
		while (diff != abs(p->next->y - p->next->x)) {//szukamy w liscie

			p = p->next;

		}
		e = p->next;
		p->next = e->next;
		delete e;
	}
}
int main()
{
	node*head = NULL;
	for (int i = 1; i<11; i++) {
		addBegging(head, i, 2 * i);
	}
	show(head);
	sum(head);
	int rzn = maxDiff(head);
	cout << "Maksymalna roznica to " << rzn << endl;
	deleteDiff(head);
	show(head);
	return 0;
}
