/*
 * String.cpp
 *
 *  Created on: May 5, 2019
 *      Author: yHowa
 */

#include "String.h"

String::~String(){
	delete [] str_arra;
	str_arra = nullptr;
}

// constructor that takes in a string literal (ie. String("Hello"))
String::String(const char &c){
	size_t ind = 0;
	str_arra = new char;
	if(*c == '\0'){
		*str_arra = *c;
		leng = 0;
		break;
	}

	while(*c != '\0'){
		str_arra[ind] = *c;
		ind++;
	}
	str_arra[ind + 1] = '\0';
	leng = ind + 1;
}

// Check if two String objects are equal
bool String::equal(const String &s){
	if (leng != s.leng)
		return false;
	else{
		for(size_t i = 0; i < leng - 1; i++){
			if(str_arra[i] != s.str_arra[i])
				return false;
		}
		return true;
	}
}

// return a String that is substring from a starting position and a length
String String::sub(size_t start, size_t length){
	if (length + start > leng){
		String s;
		//cout << "wrong input: required string length > actual string length" << endl;
		return s;
	}
	else{
		char* temp = new char;
		for(size_t i = 0; i < length; i++)
			temp[i] = str_arra[i + start];
		temp[length] = '\0';
		String newS(temp);
		delete [] temp;
		return newS;
	}
}

// return -1 if cannot find a subString;
// otherwise return the index of the first character of that substring
int String::findSub(const String &s){
	if(leng < s.leng)
		return -1;
	else{
		for(size_t i = 0; i <= leng - s.leng; i++){
			String mystr = this->sub(i, s.leng);
			if(mystr.equal(s))
				return i;
			delete [] mystr;
		}
		return -1;
	}
}

// concatenate two Strings together and returns a new String object
String String::concatenate(const String &s){
	String newS = this->str_arra + s.str_arra;
	return newS;
}

// displayed with cout
ostream& operator<<(ostream& consoleOut, const String& s){
	consoleOut << s.str_arra << endl;
	return consoleOut;
}

// copy String types from one to another
// Set the String and string literals to a new string using operator equals
String& String::operator=(const String &s){
	if(str_arra){
		delete [] str_arra;
		str_arra = nullptr;
		leng = 0;
	}
	str_arra = new char;
	for(size_t i = 0; i < s.leng; i++){
		str_arra[i] = s.str_arra[i];
		leng = i + 1;
	}
}

// Append a character to the string
String& String::operator+(char c){
	str_arra[leng] = c;
	leng += 1;
	return *this;
}

// Append a String object to the current String
String& String::operator+(String &s){
	if(s.str_arra == '\0')
		return *this;
	else if(this->leng == 0)
		return *s;
	else{
		size_t count = 0;
		for(size_t i = leng; i < leng + s.leng; i++){
			str_arra[i] = s.str_arra[count];
			count++;
		}
		str_arra[leng + s.leng] = '\0';
		leng += s.leng;
		return *this;
	}
}
