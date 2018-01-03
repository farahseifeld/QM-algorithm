#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Term.h"
#include "Container.h"
#include "Column.h"
using namespace std;



bool find(vector <int> v, int k) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == k)
			return true;
	return false;
}

bool isRepeated(vector <Term> &v, int i, string s) {
		for (int j = 0; j < i; j++)
			if (v[j].getBinary()== s)
				return true;
		return false;
}

bool isRepeated(vector <int> &v, int k) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == k)
			return true;
	return false;
}

int enterVariableNo() {

	int var;
	cout << "Enter the number of variables" << endl;

	do {
		while (!(cin >> var)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Enter the number of variables again." << endl;
		}
		if (var < 1 || var>16) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Make sure your number is more than 0 and less than 17" << endl;
		}

	} while (var <1 || var >16);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return var;
}

bool do_you_want_Minterms() {

	int choice;
	cout << "Do you want to input minterms? (Enter 0 for No, or 1 for Yes)" << endl;

	do {
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. (Enter 0 for No, or 1 for Yes)." << endl;
		}
		if (choice != 0 && choice != 1) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Make sure you enter either 0 or 1." << endl;
		}

	} while (choice !=0 && choice !=1);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == 0)
		return false;
	else
		return true;

}

bool do_you_want_dontcares() {

	int choice;
	cout << "Do you want to input dont care terms? (Enter 0 for No, or 1 for Yes)" << endl;

	do {
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. (Enter 0 for No, or 1 for Yes)." << endl;
		}

		if (choice != 0 && choice != 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Make sure you enter either 0 or 1." << endl;
		}
	} while (choice != 0 && choice != 1);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == 0)
		return false;
	else
		return true;
}


bool do_you_want_Steps() {

	int choice;
	cout << "Do you want to show the steps? (Enter 0 for No, or 1 for Yes)" << endl;

	do {
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. (Enter 0 for No, or 1 for Yes)." << endl;
		}

		if (choice != 0 && choice != 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Make sure you enter either 0 or 1." << endl;
		}
	} while (choice != 0 && choice != 1);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == 0)
		return false;
	else
		return true;
}

bool do_you_want_Again() {

	int choice;
	cout << "Do you want to enter another function? (Enter 0 for No, or 1 for Yes)" << endl;

	do {
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. (Enter 0 for No, or 1 for Yes)." << endl;
		}

		if (choice != 0 && choice != 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID INPUT. Make sure you enter either 0 or 1." << endl;
		}
	} while (choice != 0 && choice != 1);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == 0)
		return false;
	else
		return true;
}


//check for repeated values  - done
void enterMinterms(int var, vector <int> &mins) {

	int n;
	bool repeated = false;
	cout << "Enter the minterms" << endl;
	int max = pow(2, var);
	bool flag = true;
	bool failed = false;

	while (flag) {
		flag = false;
		failed = false;

		do {

			while (!(cin >> n)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				mins.clear();
				flag = true;
				cout << "INVALID INPUT. Make sure you are inputting integers." << endl;
				failed = true;
				break;

			}

			if (failed)
				break;

			if (n < 0 || n >= max) {


				mins.clear();
				cout << "INVALID INPUT. Make sure your minterms are between 0 and " << max - 1 << " inclusive." << endl;
				flag = true;


			}
			if (isRepeated(mins, n)) {


				repeated = true;
				mins.clear();
				cout << "INVALID INPUT. Make sure you do not have any repeated minterms." << endl;
				flag = true;

			}

			repeated = isRepeated(mins, n);

			if (!flag)
				mins.push_back(n);


		} while (cin.peek() != '\n');


	}


	sort(mins.begin(), mins.end());
}


//dont cares
void enterDontcares(int var, vector <int> &mindontcare, vector <int> &mins) {

	bool repeated = false;
	int n;
	cout << "Enter the dont care terms" << endl;
	int max = pow(2, var);
	bool flag = true;
	bool failed = false;
	
	while(flag){
		flag = false;
	failed = false;
		do {
			while (!(cin >> n)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				mindontcare.clear();
				flag = true;
				failed = true;
				cout << "INVALID INPUT. Make sure you are inputting integers." << endl;
				break;
			}

			if (failed)
				break;


			if (n < 0 || n >= max) {

				mindontcare.clear();
				cout << "INVALID INPUT. Make sure your dont care terms are between 0 and " << max - 1 << " inclusive." << endl;
				flag = true;

			}

			if (isRepeated(mindontcare, n)) {

				repeated = true;
				mindontcare.clear();
				cout << "INVALID INPUT. Make sure you do not have any repeated dont cares." << endl;
				flag = true;

			}

			if (isRepeated(mins, n)) {
				repeated = true;
				mindontcare.clear();
				cout << "INVALID INPUT. Make sure that your dont care terms have not been entered as minterms." << endl;
				flag = true;
			}
			repeated = isRepeated(mins, n) || isRepeated(mindontcare, n);


			if (!flag)
				mindontcare.push_back(n);

		} while (cin.peek() != '\n');

	}
}

void getFunction(int &var, vector <int> &mins, vector <int> &mindontcare) {

	var = enterVariableNo();
	if(do_you_want_Minterms())
	enterMinterms(var, mins);

	if(do_you_want_dontcares())
	enterDontcares(var, mindontcare, mins);

	for (int i = 0; i < mins.size(); i++)
		mindontcare.push_back(mins[i]);

	sort(mindontcare.begin(), mindontcare.end());
}

// turn minterms in Term to vector
void generateMinterms(int var, vector <int> &mins, vector <Term> &minterms) {
	
	int j = 0;

		while (j < mins.size()) {
			minterms[j].setMinterms(mins[j]);
			minterms[j].setBinary(minterms[j].dectobin(var));
			j++;
		}

}


void compare(vector <Container> &big, int s, int m) {

	Term t;
	for (int i = 0; i < big[s - 1].cols[m].terms.size(); i++) {
		for (int j = 0; j < big[s - 1].cols[m + 1].terms.size(); j++) {

			if (t.isAdjacent(big[s - 1].cols[m].terms[i], big[s - 1].cols[m + 1].terms[j])) {
				if (!isRepeated(big[s].cols[t.countOnes()].terms, big[s].cols[t.countOnes()].terms.size(), t.getBinary())) {
					big[s].cols[t.countOnes()].terms.push_back(t);
				}
			
			}
		}
	}


}


void generateFirstCol(vector <Container> &big, int var, vector <int> mins, vector <Term> &minterms) {

	generateMinterms(var, mins, minterms);

	for (int i = 0; i < minterms.size(); i++)
		big[0].cols[minterms[i].countOnes()].terms.push_back(minterms[i]);

}



void generateNextCol(vector <Container> &big, int s) {
	

	for (int m = 0; m < big[s - 1].size() - 1; m++)
		compare(big, s, m);
	

}

//check extra empty columns
void generateAll(vector <Container> &big, int var,  vector <int> mins, vector <Term> &minterms){


	generateFirstCol(big, var, mins, minterms);

		for (int s = 1; s < big.size(); s++)
		generateNextCol(big, s);
	
		
}


void generatePrimeImplicants(vector <Container> big, vector <Term> &prime) {

	for (int s = 0; s < big.size(); s++) 
		for (int m = 0; m < big[s].cols.size(); m++) 
			for (int i = 0; i < big[s].cols[m].terms.size(); i++) 
				if (!big[s].cols[m].terms[i].isTicked()) {
					prime.push_back(big[s].cols[m].terms[i]);
				}

			
}



void Coverage_Chart(vector<Term> vecPrime, vector<int> vecMinterms, vector<Term> &Essential, bool flag)
{
	int count;
	Term temp;
	int N = vecPrime.size();
	int M = vecMinterms.size();
	int** ary = new int*[N];

	for (int i = 0; i < N; ++i)
		ary[i] = new int[M];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			ary[i][j] = 0;

	vector <int> getminterms;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			vecPrime.at(i).getMinterms(getminterms);
			if (find(getminterms, vecMinterms.at(j)))
				ary[i][j] = 1;

		}

	if(flag)
	{
	for (int i = 0; i < vecPrime[0].getBinary().size(); i++)
		cout << " ";
	for (int i = 0; i < M; i++)
		//5 is the max number of digits
		cout << setw(3) << vecMinterms.at(i) << "  ";

	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << vecPrime.at(i).getBinary();
		for (int j = 0; j < M; ++j)
		{
			if (ary[i][j] == 1)
				cout << "  x  ";
			else
				cout << "  -  ";
		}
		cout << endl;
	}

}
	for (int j = 0; j < M; ++j) {
		count = 0;
		for (int i = 0; i < N; ++i)
		{
			if (ary[i][j] == 1)
			{
				count++;
				temp = vecPrime.at(i);
			}

		}
		if (count == 1 && !isRepeated(Essential,Essential.size(),temp.getBinary()))
			Essential.push_back(temp);
	}
}



void printColumns(vector <Container> big) {

	cout << endl;

	for (int s = 0; s < big.size(); s++) {


		if (big[s].cols.size()>0){
			cout << "Column " << s + 1 << endl;
			cout << endl;
		}
		

			for (int m = 0; m < big[s].cols.size(); m++) {

				for (int i = 0; i < big[s].cols[m].terms.size(); i++) {
					big[s].cols[m].terms[i].print();
				}

				if (big[s].cols[m].terms.size() > 0)
					cout << endl;
			}

		cout << "-------------------" << endl;

	}

}



void QM() {

	int var;

	vector <int> mins;
	vector <int> mindontcare;

	getFunction(var, mins, mindontcare);

	if (mindontcare.size() == pow(2, var)) {
		cout << endl;
		cout << "Your function is always equal 1. F = 1 " << endl;
		cout << endl;
	}
	else if (mins.size() == 0) {
		cout << endl;
		cout << "Your function is always equal to 0. F = 0" << endl;
		cout << endl;
	}
	else if (mins.size() == pow(2, var)) {
		cout << endl;
		cout << "Your function is always equal 1. F = 1" << endl;
		cout << endl;
	}

	else {

		vector <Term> minterms;
		minterms.resize(mindontcare.size());

		vector <Container> big;
		big.resize(var);

		for (int i = 0; i < big.size(); i++)
			big[i].cols.resize(var + 1);

		generateAll(big, var, mindontcare, minterms);


		bool choice = do_you_want_Steps();

		if(choice)
		//print cols
		printColumns(big);

		cout << endl;

		vector <Term> prime;
		generatePrimeImplicants(big, prime);

		cout << "Prime Implicants:" << endl;

		
		for (int i = 0; i < prime.size(); i++) {
			cout << prime[i].letters() << " ";
			prime[i].print();
		}

		cout << endl;
		cout << endl;


		vector <Term> essential;

		if(choice)
		cout << "Coverage Chart:" << endl;
		Coverage_Chart(prime, mins, essential, choice);
		cout << endl;

		cout << "Essential Prime Implicants:" << endl;
		if (essential.size() > 0)
			for (int i = 0; i < essential.size(); i++) {
				cout << essential[i].letters() << " ";
				essential[i].print();
			}
		else
			cout << "There are no essential prime implicants." << endl;
		cout << endl;

		

	}
}


int main() {

	bool choice = false;
	cout << endl;
	cout << "* ** *** **** ***** WELCOME TO QUINE-MCCLUSKEY GENERATOR ***** **** *** ** *" << endl;
	cout << endl;
	
	do {

		QM();
		choice = do_you_want_Again();

	}while (choice);
	

	system("pause");
	return 0;

}