#pragma once

#include "stdafx.h"
#include "EditBoxTextParser.h"
#include <sstream>
using namespace std;

OperationData EditBoxTextParser::parseEditBoxText(string str) throw(exception)
{
	OperationData operationData;
	vector<string> stringParts;
	stringstream strStream(str);
	string strPart;

	while (strStream >> strPart)
	{
		stringParts.push_back(strPart);
	}

	operationData.operands.push_back(stringParts[0]);
	operationData.operands.push_back(stringParts[2]);

	operationData.oprator = stringParts[1];

	if (stringParts.size() > 3)
		throw exception();
	else return operationData;
}