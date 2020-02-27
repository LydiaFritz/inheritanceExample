//lydia fritz
//this is my own work.

#include <iostream>
#include <vector>
#include <fstream>
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

	ifstream fin("INPUT.IN");
	if (!fin) {
		cerr << "file not found" << endl;
		exit(1);
	}

	vector<Sequence*> sequences;

	char seqType;
	Sequence* sPtr;
	double ft, cd, cr;
	//read sequences from the file
	while (fin >> seqType) {
		if (seqType == 'F')
			sPtr = new Fibonacci();
		else if (seqType == 'A') {
			fin >> ft >> cd;
			cout << ft << " " << cd << endl;
			sPtr = new ArithmeticSequence(ft, cd);
		}
		else {
			fin >> ft >> cr;
			cout << ft << "  " << cr << endl;
			sPtr = new GeometricSequence(ft, cr);
		}
		sequences.push_back(sPtr);
	}
	for(Sequence* var : sequences)		
	{
		var->displaySequence();
	}


	return 0;
}