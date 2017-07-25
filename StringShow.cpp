/*
* file: StringShow.cpp
* testdrive
* written: 22/02/2017
* last modified: 02/03/2017
* by N. Skilkov
*/
#include "StringList.h"

int main() {
	int i;

	cout << "Test constructors" << "\n";
	cString s1;
	s1.Print();
	cString s2("abcdef");
	s2.Print();
	cString s3(s1);
	s3.Print(); 
	cString s4("kcd");
	s4.Print();
	cString s5("");
	s5.Print();

	cout << "\n";
	
	cout << "Test GetLength" << "\n";
	printf("For s1: %d", s1.GetLength());
	cout << "\n";
	printf("For s2: %d", s2.GetLength());
	cout << "\n";
	printf("For s3: %d", s3.GetLength());
	cout << "\n";
	printf("For s4: %d", s4.GetLength());
	cout << "\n";
	printf("For s5: %d", s5.GetLength());
	cout << "\n";

	cout << "\n";

	cout << "Test IsEmpty" << "\n";
	if (s1.IsEmpty())
		cout << "s1 - empty string" << "\n";
	else
		cout << "s1 - not empty" << "\n";
	if (s2.IsEmpty())
		cout << "s2 - empty string" << "\n";
	else
		cout << "s2 - not empty" << "\n";
	if (s3.IsEmpty())
		cout << "s3 - empty string" << "\n";
	else
		cout << "s3 - not empty" << "\n";
	if (s4.IsEmpty())
		cout << "s4 - empty string" << "\n";
	else
		cout << "s4 - not empty" << "\n";
	if (s5.IsEmpty())
		cout << "s5 - empty string" << "\n";
	else
		cout << "s5 - not empty" << "\n";
	cout << "\n";
	
	cout << "\n";
	
	cout << "Test Empty" << "\n";
	s3.Empty();
	printf("mem  = %d; size = %d", s3.GetMem(), s3.GetLength());
	cout << "\n";
	cout << "\n";
	cout << "Test SetAt" << "\n";
	cout << "For s1" << "\n";
	s1.SetAt(2, 'k');
	s1.Print();
	cout << "For s2" << "\n";
	s2.SetAt(2, 'k');
	s2.Print();
	cout << "For s3" << "\n";
	s5.SetAt(2, 'k');
	s5.Print();
	cout << "\n";

	cout << "Test Compare (s1 and s2)" << "\n";
	if (s2.Compare(s1) == 1)
		cout << "s2 bigger" << "\n";
	else
		if (s2.Compare(s1) == -1)
			cout << "s1 bigger" << "\n";
		else
			cout << "equal" << "\n";
	cout << "Test Compare (s4 and s5)" << "\n";
	if (s4.Compare(s5) == 1)
		cout << "s4 bigger" << "\n";
	else
		if (s2.Compare(s1) == -1)
			cout << "s5 bigger" << "\n";
		else
			cout << "equal" << "\n";

	cout << "\n";
	
	cout << "Test Find (symbol)" <<"\n";
	printf("c in s1 = %d\n", s1.Find('c'));
	printf("c in s2 = %d\n", s2.Find('c'));
	printf("c in s5 = %d\n", s5.Find('c'));
	cout << "\n";

	cout << "Test Find (substring)" << "\n";
	printf("%s in s1 = %d\n", "def", s1.Find("def"));
	printf("%s in s2 = %d\n", "def", s2.Find("def"));
	printf("%s in s2 = %d\n", "dek", s2.Find("dek"));
	printf("%s in s5 = %d\n", "dek", s5.Find("dek"));
	
	cout << "\n";
	
	cout << "Test Mid" << "\n";
	if (s2.Mid(1, 3) == s4)
		cout << "s4 is s2 of 1,3\n";
	else
		cout << "s4 is not mid(1,3) of s2\n";
	if (s5.Mid(1, 3) == s4)
		cout << "s4 is s5 of 1,3\n";
	else
		cout << "s4 is not mid(1,3) of s5\n";
	if (s1.Mid(1, 3) == s4)
		cout << "s4 is s1 of 1,3\n";
	else
		cout << "s4 is not mid(1,3) of s1\n";

	cout << "\n";
	
	cout << "Operator == (cString)" <<"\n";
	if (s3 == s2)
		cout << "s2 and s3 are equal" << "\n";
	else
		cout << "s2 and s3 are not equal" << "\n";

	cout << "\n";

	cout << "Operator = (s3 = s2)" << "\n";
	s3 = s2;
	s3.Print();

	cout << "\n";

	cout << "Operator = (s3 = cat)" << "\n";
	s3 = "cat";
	s3.Print();

	cout << "\n";
	
	cout << "Operator += (s3+=s2)" << "\n";
	s3 += s2;
	s3.Print();
	cout << "Operator += (s1+=s2)" << "\n";
	s1 += s2;
	s1.Print();
	cout << "\n";
	
	cout << "Operator []" << "\n";
	printf("s1[2] = %c\n", s1[2]);
	printf("s2[2] = %c\n", s2[2]);
	printf("s5[2] = %c\n", s5[2]);
	
	cout << "s4 = s2 + s3" <<"\n";
	s4 = s2 + s3;
	s4.Print();

	cout << "s2 = s5 + s1" << "\n";
	s2 = s5 + s1;
	s2.Print();

	system("pause");
	return 0;
};
