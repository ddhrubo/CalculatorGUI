#pragma once

#include "stdafx.h"
#include "CalculatorGUI.h"
#include "CalculatorGUIDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>

#include <Operation.h>
#include <OperationFactory.h>

using namespace std;

void CCalculatorGUIDlg::initStrings() {
	argument.clear();
	argument.push_back("");
	argument.push_back("");

	currentString = "";
	oprator = "";
}

void CCalculatorGUIDlg::refreshOutputText() {
	CWnd *mainShowText = GetDlgItem(MAIN_SHOW);
	mainShowText->SetWindowTextW(CString(currentString.c_str()));
}

void CCalculatorGUIDlg::addToString(char ch) {
	currentString += ch;
	refreshOutputText();
}

void CCalculatorGUIDlg::OnBnClickedPlusButton() {
	// TODO: Add your control notification handler code here
	if (currentString.size() && argument[0] == "") {
		argument[0] = currentString;
		currentString = "";
		oprator = "+";
	}
}

void CCalculatorGUIDlg::OnBnClickedMinusButton() {
	// TODO: Add your control notification handler code here
	if (currentString.size() && argument[0] == "") {
		argument[0] = currentString;
		currentString = "";
		oprator = "-";
	}
}

void CCalculatorGUIDlg::OnBnClickedMultiplyButton() {
	// TODO: Add your control notification handler code here
	if (currentString.size() && argument[0] == "") {
		argument[0] = currentString;
		currentString = "";
		oprator = "*";
	}
}

void CCalculatorGUIDlg::OnBnClickedDivideButton() {
	// TODO: Add your control notification handler code here
	if (currentString.size() && argument[0] == "") {
		argument[0] = currentString;
		currentString = "";
		oprator = "/";
	}
}


void CCalculatorGUIDlg::OnBnClickedAnsButton() {
	// TODO: Add your control notification handler code here
	if (currentString.size() && argument[0] != "" && oprator!="") {
		argument[1] = currentString;

		Operation* operation = nullptr;
		OperationFactory operationFactory;
		double result;

		operation = operationFactory.getOperation(oprator);

		if (operation != nullptr) {
			try {
				result = operation->operation(argument);
				char tmp[100];
				sprintf_s(tmp, "%lf", result);
				currentString = tmp;
				refreshOutputText();
				initStrings();
			} catch (const std::exception&) {
				initStrings();
				currentString = "Error occurred!";
				refreshOutputText();
			}
		}
	}
}

void CCalculatorGUIDlg::OnBnClickedClearButton() {
	// TODO: Add your control notification handler code here
	initStrings();
	refreshOutputText();
}


void CCalculatorGUIDlg::OnBnClickedButtonKey1() {
	// TODO: Add your control notification handler code here
	addToString('1');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey2() {
	// TODO: Add your control notification handler code here
	addToString('2');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey3() {
	// TODO: Add your control notification handler code here
	addToString('3');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey4() {
	// TODO: Add your control notification handler code here
	addToString('4');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey5() {
	// TODO: Add your control notification handler code here
	addToString('5');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey6() {
	// TODO: Add your control notification handler code here
	addToString('6');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey7() {
	// TODO: Add your control notification handler code here
	addToString('7');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey8() {
	// TODO: Add your control notification handler code here
	addToString('8');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey9() {
	// TODO: Add your control notification handler code here
	addToString('9');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey0() {
	// TODO: Add your control notification handler code here
	if (currentString.size()) {
		addToString('0');
	}
}
