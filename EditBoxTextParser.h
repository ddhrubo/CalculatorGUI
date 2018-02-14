#pragma once

#include "stdafx.h"
#include <vector>
#include <string>
#include <exception>
using namespace std;

struct OperationData
{
	vector<string> operands;
	string oprator;
};

class EditBoxTextParser
{
public:
	OperationData parseEditBoxText(string str) throw(exception);
};