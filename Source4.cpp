//lydia fritz
//this is my own work.

#include <iostream>
#include <vector>
using namespace std;

class Sequence {
private:
	double firstTerm;

public:
	Sequence(double ft) { firstTerm = ft; }
	void setFirstTerm(double ft) { firstTerm = ft; }
	double getFirstTerm()const { return firstTerm; }
	//pure virtual function - class is now abstract
	virtual void displaySequence()const = 0;
};

class ArithmeticSequence : public Sequence {
private:
	double commonDifference;
public:
	ArithmeticSequence(double ft, double cd) : Sequence(ft) {
		commonDifference = cd;
	}

	double getCommonDiff()const { return commonDifference; }
	void setCommonDiff(double cd) { commonDifference = cd; }
	void displaySequence()const {
		double term = getFirstTerm();
		cout << "The first 5 terms in the arithmetic sequence are ";
		for (int i = 1; i <= 4; i++) {
			cout << term << ", ";
			term = term + commonDifference;
		}
		cout << term << endl;
	}
};

class GeometricSequence : public Sequence {
private:
	double commonRatio;
public:
	GeometricSequence(double ft, double r) :Sequence(ft) {
		commonRatio = r;
	}
	void setRatio(double r) { commonRatio = r; }
	double getRatio()const { return commonRatio; }
	void displaySequence()const {
		double term = getFirstTerm();
		cout << "The first 5 terms in the geometric sequence are ";
		for (int i = 1; i <= 4; i++) {
			cout << term << ", ";
			term = term * commonRatio;
		}
		cout << term << endl;
	}
};

//can add other classes
class Fibonacci : public Sequence {
public:
	Fibonacci() :Sequence(1) {}
	void displaySequence()const {
		cout << "The first 5 terms in the Fibonacci sequence are 1, 1, 2, 3, 5." << endl;
	}
};

int main() {


	ArithmeticSequence a_seq(10, -2);
	GeometricSequence g_seq(10, .5);
	ArithmeticSequence a_seq1(1.5, -.5);
	GeometricSequence g_seq1(100, .1);
	Fibonacci f_seq;
	ArithmeticSequence a_seq2(0, 100);
	GeometricSequence g_seq2(1024, .5);
	ArithmeticSequence a_seq3(5, -10);
	GeometricSequence g_seq3(1000, .2345);


	vector<Sequence*> sequences;

	sequences.push_back(&a_seq);
	sequences.push_back(&g_seq);
	sequences.push_back(&a_seq1);
	sequences.push_back(&g_seq1);
	sequences.push_back(&a_seq2);
	sequences.push_back(&g_seq2);
	sequences.push_back(&a_seq3);
	sequences.push_back(&g_seq3);
	sequences.push_back(&f_seq);

	for (size_t i = 0; i < sequences.size(); i++)
	{
		sequences[i]->displaySequence();
	}

	return 0;
}