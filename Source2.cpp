////lydia fritz
////this is my own work.
//
//#include <iostream>
//using namespace std;
//
//class Sequence {
//private:
//	double firstTerm;
//
//public:
//	Sequence(double ft) { firstTerm = ft; }
//	void setFirstTerm(double ft) { firstTerm = ft; }
//	double getFirstTerm()const { return firstTerm; }
//	//pure virtual function - class is now abstract
//	virtual void displaySequence()const = 0;
//};
//
//class ArithmeticSequence : public Sequence {
//private:
//	double commonDifference;
//public:
//	ArithmeticSequence(double ft, double cd) : Sequence(ft) {
//		commonDifference = cd;
//	}
//
//	double getCommonDiff()const { return commonDifference; }
//	void setCommonDiff(double cd) { commonDifference = cd; }
//	void displaySequence()const {
//		double term = getFirstTerm();
//		cout << "The first 5 terms in the arithmetic sequence are ";
//		for (int i = 1; i <= 4; i++) {
//			cout << term << ", ";
//			term = term + commonDifference;
//		}
//		cout << term << endl;
//	}
//};
//
//class GeometricSequence : public Sequence {
//private:
//	double commonRatio;
//public:
//	GeometricSequence(double ft, double r) :Sequence(ft) {
//		commonRatio = r;
//	}
//	void setRatio(double r) { commonRatio = r; }
//	double getRatio()const { return commonRatio; }
//	void displaySequence()const {
//		double term = getFirstTerm();
//		cout << "The first 5 terms in the geometric sequence are ";
//		for (int i = 1; i <= 4; i++) {
//			cout << term << ", ";
//			term = term * commonRatio;
//		}
//		cout << term << endl;
//	}
//};
//
//int main() {
//
//	
//	ArithmeticSequence a_seq(10, -2);
//	GeometricSequence g_seq(10, .5);
//
//	//with a pure virtual function 
//	Sequence* s;
//	s = &a_seq;
//	s->displaySequence();
//
//	s = &g_seq;
//	s->displaySequence();
//
//	return 0;
//}