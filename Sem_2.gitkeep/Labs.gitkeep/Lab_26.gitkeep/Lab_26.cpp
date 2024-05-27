#include <iostream>
#include "Dialog.h"
#include "tree.h"
using namespace std;

int main() {
	Print* p = new Print;
	p->Input();
	p->Show();

	Magazin* s = new Magazin;
	s->Input();
	s->Show();

	Tree t(10);
	Object* o = p;
	t.Add();
	o = s;
	t.Show();
	t.Del();
	cout << "\nTree: " << t() << endl;

	Dialog D;
	D.execute();
	return 0;
}