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
#include "EditBoxTextParser.h"

using namespace std;

void CCalculatorGUIDlg::refreshAllStrings() {
	setMainEditText("");
	noHandleMainEditTextChange = false;
}

void CCalculatorGUIDlg::setOutputStaticText(string str)
{
	CWnd *outputStaticText = GetDlgItem(OUTPUT_STATIC_TEXT);
	outputStaticText->SetWindowTextW(CString(str.c_str()));
}

string CCalculatorGUIDlg::getMainEditText()
{
	CWnd *mainEditText= GetDlgItem(MAIN_EDIT_BOX);
	CString str = _T("");
	mainEditText->GetWindowTextW(str);
	CT2A convertString(str);
	string retStr(convertString);
	return retStr;
}

void CCalculatorGUIDlg::setMainEditText(string str)
{
	CWnd *mainEditText = GetDlgItem(MAIN_EDIT_BOX);
	mainEditText->SetWindowTextW(CString(str.c_str()));
}

void CCalculatorGUIDlg::moveMainEditTextCursorToEnd()
{
	CEdit *mainEditText = (CEdit*)GetDlgItem(MAIN_EDIT_BOX);
	mainEditText->SetSel(0,-1);
	mainEditText->SetSel(-1);
}

void CCalculatorGUIDlg::onChangeMainEditText()
{
	if (noHandleMainEditTextChange)
	{
		noHandleMainEditTextChange = false;
		return;
	}

	string currentString = getMainEditText();
	int len = currentString.size();
	if (!len)
		return;

	if (currentString[len-1] == '+')
	{
		currentString.erase(len-1,1);
		setMainEditText(currentString);
		moveMainEditTextCursorToEnd();
		
		OnBnClickedPlusButton();
	}
	else if (currentString[len - 1] == '-')
	{
		currentString.erase(len - 1, 1);
		setMainEditText(currentString);
		moveMainEditTextCursorToEnd();
		
		OnBnClickedMinusButton();
	}
	else if (currentString[len - 1] == '*')
	{
		currentString.erase(len - 1, 1);
		setMainEditText(currentString);
		moveMainEditTextCursorToEnd();

		OnBnClickedMultiplyButton();
	}
	else if (currentString[len - 1] == '/')
	{
		currentString.erase(len - 1, 1);
		setMainEditText(currentString);
		moveMainEditTextCursorToEnd();

		OnBnClickedDivideButton();
	}
	else if (currentString[len - 1] == ' ')
	{
		currentString.erase(len - 1, 1);
		setMainEditText(currentString);
		moveMainEditTextCursorToEnd();
	}
}

void CCalculatorGUIDlg::onPressedEnter()
{
	OnBnClickedAnsButton();
}

void CCalculatorGUIDlg::addToMainEditText(char ch) 
{
	setMainEditText(getMainEditText() + ch);
}

void CCalculatorGUIDlg::OnBnClickedPlusButton() {
	// TODO: Add your control notification handler code here
	noHandleMainEditTextChange = true;
	setMainEditText(getMainEditText() + " + ");
	moveMainEditTextCursorToEnd();
}

void CCalculatorGUIDlg::OnBnClickedMinusButton() {
	// TODO: Add your control notification handler code here
	noHandleMainEditTextChange = true;
	setMainEditText(getMainEditText() + " - ");
	moveMainEditTextCursorToEnd();
}

void CCalculatorGUIDlg::OnBnClickedMultiplyButton() {
	// TODO: Add your control notification handler code here
	noHandleMainEditTextChange = true;
	setMainEditText(getMainEditText() + " * ");
	moveMainEditTextCursorToEnd();
}

void CCalculatorGUIDlg::OnBnClickedDivideButton() {
	noHandleMainEditTextChange = true;
	setMainEditText(getMainEditText() + " / ");
	moveMainEditTextCursorToEnd();
}


void CCalculatorGUIDlg::OnBnClickedAnsButton() {
	// TODO: Add your control notification handler code here
	string currentString = getMainEditText();
	EditBoxTextParser editBoxTextParser;
	OperationData operationData;
	
	try
	{
		operationData = editBoxTextParser.parseEditBoxText(currentString);
	}
	catch (exception& e)
	{
		setOutputStaticText("Invalid input format!");
		refreshAllStrings();
		return;
	}
	
	Operation* operation = nullptr;
	OperationFactory operationFactory;
	double result;

	operation = operationFactory.getOperation(operationData.oprator);

	if (operation != nullptr)
	{
		try
		{
			result = operation->operation(operationData.operands);
			char tmp[100];
			sprintf_s(tmp, "%lf", result);
			setOutputStaticText(tmp);
			refreshAllStrings();
		}
		catch (exception& e)
		{
			setOutputStaticText(e.what());
			refreshAllStrings();
		}
	}
	else
	{
		setOutputStaticText("Invalid Operator");
		refreshAllStrings();
	}
}

void CCalculatorGUIDlg::OnBnClickedClearButton() {
	// TODO: Add your control notification handler code here
	refreshAllStrings();
	setOutputStaticText("");
}


void CCalculatorGUIDlg::OnBnClickedButtonKey1() {
	// TODO: Add your control notification handler code here
	addToMainEditText('1');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey2() {
	// TODO: Add your control notification handler code here
	addToMainEditText('2');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey3() {
	// TODO: Add your control notification handler code here
	addToMainEditText('3');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey4() {
	// TODO: Add your control notification handler code here
	addToMainEditText('4');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey5() {
	// TODO: Add your control notification handler code here
	addToMainEditText('5');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey6() {
	// TODO: Add your control notification handler code here
	addToMainEditText('6');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey7() {
	// TODO: Add your control notification handler code here
	addToMainEditText('7');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey8() {
	// TODO: Add your control notification handler code here
	addToMainEditText('8');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey9() {
	// TODO: Add your control notification handler code here
	addToMainEditText('9');
}


void CCalculatorGUIDlg::OnBnClickedButtonKey0() {
	// TODO: Add your control notification handler code here
	string currentString = getMainEditText();
	if (currentString.size()) {
		addToMainEditText('0');
	}
}
