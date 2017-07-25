/*
* file: StringList.cpp
* code of functions declared in StringList.h
* written: 22/02/2017
* last modified: 02/03/2017
* by N. Skilkov
*/
#include "StringList.h"
// constructors/destructors
cString::cString() {
	str = NULL;
	strSize = 0;
	memSize = 0;
}

cString::cString(const char *psz) {
	int i = 0;

	str = new char[strlen(psz)+1];
	strcpy(str, psz);
	str[strlen(psz)] = '\0';
	memSize = (strlen(psz) + 1) * sizeof(char);
	strSize = strlen(psz);
}

cString::cString(const cString& stringSrc) {
	int i = 0;

	if (stringSrc.IsEmpty()) {
		str = NULL;
		strSize = 0;
		memSize = 0;
	}
	else
	{
		str = new char[stringSrc.strSize + 1];
		strcpy(str, stringSrc.str);
		str[stringSrc.strSize] = '\0';
		strSize = stringSrc.strSize;
		memSize = (strSize + 1) * sizeof(char);
	};
};

cString::~cString() {
	Empty();
}

//methods

int cString::GetLength() const {
	return strSize;
}

bool cString::IsEmpty() const {
	return ((str == NULL)||(strSize == 0)) ? true : false;
};

void cString::Empty() {
	if ((str != NULL) && (strSize != 0) && (memSize != 0)) {
		delete[] str;
		strSize = 0;
		memSize = 0;
	};
}

void cString::SetAt(int nIndex, char ch) {
	if ((nIndex > 0) && (ch != '\0') && (str != NULL) && (nIndex < strSize))
		str[nIndex - 1] = ch;
	else
		printf("No such pos or ch invalid\n");
}

int cString::Compare(const cString& s) const {
	if (strSize > s.strSize)
		return 1;
	else if (strSize < s.strSize)
		return -1;
	else if ((strSize != 0)&&(s.strSize != 0))
		return strcmp(str, s.str);
	return 0;
}

int cString::Find(char ch) const {
	int i = 0;

	if (ch == '\0')
		return -1;
	while (i < strSize) {
		if (str[i] == ch)
			break;
		i++;
	};
	return (i == strSize) ? -1 : i;
}

int cString::Find(char *pszSub) const {
	int check = 0;

	if ((strSize < strlen(pszSub)) || (pszSub == "\0"))
		return -1;
	for (int i = 0; i < strSize - strlen(pszSub) + 1; i++) {
		for (int j = 0; j < strlen(pszSub); j++) {
			if (str[i + j] != pszSub[j]) {
				check = 0;
				break;
			}
			else
				check++;
		}
		if (check == strlen(pszSub))
			return i;
	};
	return -1;
}

cString cString::Mid(int nFirst, int nCount) const {
	cString *s = new cString;
	int i = 0;

	s->str = new char[nCount + 1];

	if ((strSize == 0) || (nFirst > strSize) || (nFirst<0) || (nCount<1) || ((nFirst + nCount - 1) > strSize) || (nCount > strSize)) {
		s->str = NULL;
		s->strSize = 0;
		s->memSize = 1;
		return *s;
	};

	while ((str[i] != '\0') && (i < nCount)) {
		s->str[i] = str[nFirst + i];
		i++;
	};

	s->str[nCount] = '\0';
	s->strSize = nCount;
	s->memSize = nCount * sizeof(char);
	return *s;
}

cString cString::Left(int nCount) const {
	return Mid(0, nCount);
}

cString cString::Right(int nCount) const {
	return Mid(strSize - nCount, strSize);
}
//additional

int cString::GetMem() const {
	return memSize;
}
//operators

cString& cString::operator=(const cString& stringSrc) {
	int i = 0;

	if (stringSrc.str == NULL) {
		Empty();
		str = NULL;
		strSize = 0;
		memSize = 0;
		return *this;
	};
	if (this == &stringSrc)
		return *this;
	Empty();
	str = new char[stringSrc.strSize + 1];
	strcpy(str, stringSrc.str);
	str[stringSrc.strSize] = '\0';
	strSize = stringSrc.strSize;
	memSize = stringSrc.memSize;
	return *this;
}

const cString& cString::operator=(const unsigned char* psz) {
	int i = 0;

	Empty();
	str = new char[strlen((char*)psz) + 1];
	strcpy(str, (char*)psz);
	str[strlen((char*)psz)] = '\0';
	strSize = strlen((char*)psz);
	memSize = (strSize + 1) * sizeof(char);
	return *this;
}

char cString::operator [](int indx) {
	return ((0 <= indx) && (indx < strSize)) ? str[indx] : '\0';
}

cString cString::operator +(const cString& string) {
	cString* s = new cString;
	int i = 0;

	s->str = new char[strSize + string.strSize + 1];
	for (i = 0; i < strSize; i++)
		s->str[i] = str[i];
	for (i = 0; i < string.strSize; i++)
		s->str[strSize + i] = string.str[i];
	//strcat(strcpy(s->str, str), string.str);
	s->str[strSize + string.strSize] = '\0';
	s->strSize = strSize + string.strSize;
	s->memSize = (strSize + string.strSize + 1) * sizeof(char);
	return *s;
}

cString& cString::operator +=(const cString& string) {
	int i = 0;

	if (!string.IsEmpty()) {
		char* tmp = new char[strSize + string.strSize + 1];
		for (i = 0; i < strSize; i++)
			tmp[i] = str[i];
		for (i = 0; i < string.strSize; i++)
			tmp[strSize + i] = string.str[i];
		tmp[strSize + string.strSize] = '\0';
		if (str != NULL)
			delete[] str;
		str = new char[strSize + string.strSize + 1];
		for (i = 0; i < strSize + string.strSize; i++)
			str[i] = tmp[i];
		str[strSize + string.strSize] = '\0';
		strSize += string.strSize;
		memSize += string.memSize;
		delete[] tmp;
	};
	return *this;
}

bool cString::operator ==(const cString& string) {
	bool f = true;
	if ((strSize > string.strSize) || (strSize < string.strSize)) {
		f = false;
		return f;
	};
	for (int i = 0; i < strSize; i++) {
		if (str[i] != string.str[i]) {
			f = false;
			break;
		};
	};
	return f;
}
//
void cString::Print() {
	int i = 0;
	cout << "String: ";
	if ((str == NULL) || (strSize == 0))
		cout << "empty";
	else {
		while (str[i] != '\0') {
			printf("%c", str[i]);
			i++;
		};
	};
	cout << "\n";
}
