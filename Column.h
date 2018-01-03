#pragma once
#ifndef COLUMN_H
#define COLUMN_H
#include <string>
#include <vector>
#include "Term.h"

class Column {


	public:
		vector <Term> terms;

		Column() {
		
		}
		
		Column(vector <Term> t) {
			terms = t;
		}


		int size() {
			return terms.size();
		}

		

};

#endif