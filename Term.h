#pragma once
#ifndef TERM_H
#define TERM_H
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

string reverse(string & s) {
	if (s.size() == 1)
		return s;
	else
		return reverse(s.substr(1, s.size() - 1)) + s[0];
}


class Term {

	private:
		vector <int> minterms;
		string binaryterm;
		bool ticked;

	public:

	//default constructor
	Term() {
		minterms;
		binaryterm = "";
		ticked = false;
	}
	//constructor
	Term(int m, int var) {
		//validate minterms
		//minterms.push_back(atoi(m.c_str()));
		minterms.push_back(m);
		ticked = false;
		binaryterm = dectobin(var);
	}
	//constructor
	//FIX THIS
	Term(int m, string b, bool c) {
		minterms.push_back(m);
		ticked = c;
		binaryterm = b;
	}

	//converts from decimal to binary
	string dectobin(int var) {

		string binaryterm = "";
		int num = minterms[0];

		while (num != 0) {
			binaryterm += to_string(num % 2);
			num = num / 2;
		}

		while (binaryterm.length() != var)
			binaryterm += "0";
		binaryterm = reverse(binaryterm);

		return binaryterm;

	}

	//counts 1s in binary 
	int countOnes() {
		int size = binaryterm.length();
		int i = 0;
		int cnt = 0;
		while (i < size) {
			if (binaryterm[i] == '1')
				cnt++;
			i++;
		}
		return cnt;
	}

	//setters
	void setBinary(string b) {
		binaryterm = b;
	}

	void setMinterms(vector <int> v) {
		minterms = v;
	}
	void setMinterms(int m) {
		minterms.push_back(m);
	}
	void tick() {
		ticked = true;
	}

	//getters
	bool isTicked() {
		return ticked;
	}

	string getBinary() {
		return binaryterm;
	}

	void getMinterms(vector <int> &mins) {
		mins = minterms;
	}

	//checks if 2 terms are adjacent and returns a 3rd term with the adjacent string 0X10
	bool isAdjacent(Term &t1, Term &t2) {

		string s1 = t1.binaryterm;
		string s2 = t2.binaryterm;
		bool flag = false;
		string sresult = "";
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == s2[i]) {
				sresult += s1[i];
			}
			else if (s1[i] != s2[i] && !flag) {
				sresult += 'X';
				flag = true;
			}
			else
				return false;
		}

		vector <int> vmin1;
		vector <int> vmin2;
		vector <int> vmresult;
		t1.getMinterms(vmin1);
		t2.getMinterms(vmin2);
		

		for (int i = 0; i < vmin1.size(); i++)
			vmresult.push_back(vmin1[i]);
		for (int i = 0; i < vmin2.size(); i++)
			vmresult.push_back(vmin2[i]);


		sort(vmresult.begin(), vmresult.end());

		minterms = vmresult;
		binaryterm = sresult;
		t1.ticked = true;
		t2.ticked = true;

		return true; 
	}

	void print() {
		string terms = "";
		for (int i = 0; i < minterms.size(); i++) 
			terms += to_string(minterms[i]) + ",";
		
		terms = terms.substr(0, terms.size() - 1);
		cout << terms << "   " << binaryterm << " ";
		if (ticked)
			cout << "#";
		cout << endl;
	}

	string letters() {

		string answer = "";

		for (int i = 0; i<binaryterm.size(); i++)
			if (binaryterm[i] != 'X')
				switch (i) {
				case 0:
					if (binaryterm[i] == '0')
						answer += "A'";
					else
						answer += "A";
					break;

				case 1:
					if (binaryterm[i] == '0')
						answer += "B'";
					else
						answer += "B";
					break;

				case 2:
					if (binaryterm[i] == '0')
						answer += "C'";
					else
						answer += "C";
					break;

				case 3:
					if (binaryterm[i] == '0')
						answer += "D'";
					else
						answer += "D";
					break;

				case 4:
					if (binaryterm[i] == '0')
						answer += "E'";
					else
						answer += "E";
					break;

				case 5:
					if (binaryterm[i] == '0')
						answer += "F'";
					else
						answer += "F";
					break;

				case 6:
					if (binaryterm[i] == '0')
						answer += "G'";
					else
						answer += "G";
					break;

				case 7:
					if (binaryterm[i] == '0')
						answer += "H'";
					else
						answer += "H";
					break;

				case 8:
					if (binaryterm[i] == '0')
						answer += "I'";
					else
						answer += "I";
					break;

				case 9:
					if (binaryterm[i] == '0')
						answer += "J'";
					else
						answer += "J";
					break;

				case 10:
					if (binaryterm[i] == '0')
						answer += "K'";
					else
						answer += "K";
					break;

				case 11:
					if (binaryterm[i] == '0')
						answer += "L'";
					else
						answer += "L";
					break;

				case 12:
					if (binaryterm[i] == '0')
						answer += "M'";
					else
						answer += "M";
					break;

				case 13:
					if (binaryterm[i] == '0')
						answer += "N'";
					else
						answer += "N";
					break;

				case 14:
					if (binaryterm[i] == '0')
						answer += "O'";
					else
						answer += "O";
					break;

				case 15:
					if (binaryterm[i] == '0')
						answer += "P'";
					else
						answer += "P";
					break;

				case 16:
					if (binaryterm[i] == '0')
						answer += "Q'";
					else
						answer += "Q";
					break;

				default:
					break;
				}

		return answer;
	}
};



#endif