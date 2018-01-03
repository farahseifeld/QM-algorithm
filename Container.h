#pragma once
#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include "Column.h"
#include "Term.h"



class Container {


public:

	vector <Column> cols;

	Container() {

	}

	Container(int var) {
		cols.resize(var + 1);
	}

	Container(vector <Column> t) {
		cols = t;
	}


	int size() {
		return cols.size();
	}


};

#endif