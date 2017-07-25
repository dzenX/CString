/*
* file: StringList.h
* StringList class declaration
* written: 22/02/2017
* last modified: 02/03/2017
* by N. Skilkov
*/

#pragma once

#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class cString {
public:

	//constructors/destructor
	cString();
	cString(const char *psz);
	cString(const cString& stringSrc);

	~cString();

	//methods
	
	int GetLength() const;
	bool IsEmpty()const;
	void Empty();
	void SetAt(int nIndex, char ch);
	int Compare(const cString& s) const;
	int Find(char ch) const;
	int Find(char *pszSub) const;

	cString Mid(int nFirst, int nCount) const;
	cString Left(int nCount) const;
	cString Right(int nCount) const;

	//additional functions
	int GetMem() const;
	//operators
	
	cString& operator=(const cString& stringSrc);
	const cString& operator=(const unsigned char* psz);
	char operator [](int indx);
	bool operator ==(const cString& string);
	cString operator +(const cString& string);
	cString& operator +=(const cString& string);
	
	//
	void Print();
private:
	//variables
	char* str;
	int strSize;//size of memory of cString
	int memSize;
};
