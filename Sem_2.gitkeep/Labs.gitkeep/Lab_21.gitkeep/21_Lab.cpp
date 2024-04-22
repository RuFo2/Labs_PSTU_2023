#include <iostream>
using namespace std;

class Pair {
	int first;
	double second;
public:
	Pair(int n,double q){
		first = n;
		second = q;
	}
	Pair() {
		first = 20;
		second = 4;
	}
	Pair(const Pair& tmp){
		first = tmp.first;
		second = tmp.second;
	}

	void setFirst(int n) { first = n; }
	void setSecond(double q) { second = q; }

	int getFirst() { return first; }
	double getSecond() { return second; }

	Pair& operator-(const Pair& tmp){
		Pair* k = new Pair;
		k->setFirst(first);
		k->setSecond(second);
		k->first -= tmp.first;
		k->second -= tmp.second;
		return *k;
	}

	void operator+(int n) { first += n; }
	void operator+(double q) { second += q; }

	void Show() {
		cout << first << ' ' << second << endl;
	}
	~Pair(){}
};

int main()
{
	Pair pairOne(30, 8);
	Pair pairTwo;
	Pair pairThree = pairOne - pairTwo;
	pairThree.Show();
	pairThree + 87;
	pairThree + 34.5;
	pairThree.Show();
}
