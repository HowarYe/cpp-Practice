/*
 * String.h
 *
 *  Created on: May 5, 2019
 *      Author: yHowa
 */

#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;

class String{
public:
	String();
	String(const char c[]);
	~String();

	// Check if two String objects are equal
	bool equal(const String &s);

	// return -1 if cannot find a subString
	int findSub(const String &s);

	// concatenate two Strings together and returns a new String object
	String concatenate(String &s);

	// return a String that is substring from a starting position and a length
	String sub(size_t start, size_t length);

	// displayed with cout
	friend ostream& operator<<(ostream& consoleOut, const String& s);

	// copy String types from one to another
	// Set the String and string literals to a new string using operator equals
	// 传入str为空则第二个，不空则第一个，同样要先清空原memory
	String& operator=(const String &s);

	// Append a character to the string
	String& operator+(char c);

	// Append a String object to the current String
	String& operator+(String &s);

	// return the character at an index (index starts from 0)
	inline char charIndex(size_t i){return str_arra[i];}
	// return the length of the String object
	inline size_t length(const String& s){return s.leng;}
	// return a const char* version of the string
	inline const char* getString(){return str_arra;}


private:
	char* str_arra;
	size_t leng;

};

#endif /* STRING_H_ */
