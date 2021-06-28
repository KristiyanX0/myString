#include "myString.h"
#pragma warning(disable : 4996)

myString::myString() : text(nullptr) {
}


myString::myString(const char* text) {
	int length = strlen(text);
	this->text = new char[length + 1];
	strcpy(this->text, text);
	this->text[length] = '\0';
}

myString::myString(const myString& other) {
	copy_from(other);
}

myString::~myString() {
	free();
}

void myString::free() {
	if (text != nullptr)
		delete[] text;
}

void myString::copy_from(const myString& other) {
	int length = strlen(other.text);
	text = new char[length + 1];
	strcpy(text, other.text);
	text[length] = '\0';
}

myString& myString::operator=(const myString& other) {
	if (this != &other) {
		free();
		copy_from(other);
	}
	return *this;
}

char& myString::operator[](size_t t) {
	return text[t];
}

myString& myString::operator+=(const myString& other) {
	size_t oldlength = strlen(text);
	size_t newLength = strlen(text) + strlen(other.text);
	resize(newLength + 1);
	for (size_t i = oldlength; i < newLength; ++i)
		this->text[i] = other.text[i - oldlength];
	text[newLength] = '\0';
	return *this;
}

myString& myString::operator+=(const char other) {
	size_t newLength = strlen(text) + 1;
	resize(newLength + 1);
	text[newLength - 1] = other;
	text[newLength] = '\0';
	return *this;
}

myString& myString::operator*=(size_t scalar) {
	if (scalar > 0) {
		size_t oldlength = strlen(text);
		size_t newLength = strlen(text)*scalar;
		resize(newLength + 1);
		for (size_t i = oldlength, j = 0; i < newLength; i++, j++)
			text[i] = text[j];
		text[newLength] = '\0';
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const myString& v) {
	os << v.text;
	return os;
}

std::istream& operator>>(std::istream& is, myString& str) {
	char* ptr = new char[128];
	is >> ptr;
	str = myString(ptr);
	return is;
}

const myString operator+(const myString& lhs, const myString& rhs) {
	myString lhsCopy(lhs);
	lhsCopy += rhs;
	return lhsCopy;
}

const myString operator+(const myString& lhs, const char rhs) {
	myString lhsCopy(lhs);
	lhsCopy += rhs;
	return lhsCopy;
}

const myString operator*(const myString& lhs, size_t scalar) {
	myString copy(lhs);
	copy *= scalar;
	return copy;
}

bool operator>(const myString& lhs, const myString& rhs) {
	return lhs.size() > rhs.size();
}

bool operator<(const myString& lhs, const myString& rhs) {
	return lhs.size() < rhs.size();
}

bool operator<=(const myString& lhs, const myString& rhs) {
	return lhs.size() <= rhs.size();
}

bool operator>=(const myString& lhs, const myString& rhs) {
	return lhs.size() >= rhs.size();
}

bool operator==(const myString& lhs, const myString& rhs) {
	return lhs.size() == rhs.size();
}

bool operator!=(const myString& lhs, const myString& rhs) {
	return lhs.size() != rhs.size();
}

bool myString::is_substr(const char* text) const {
	return strstr(this->text, text);
}

myString myString::substr(size_t position1) const {
	return text + position1;
}

myString myString::substr(size_t position1, size_t position2) const {
	char* copy_text = new char[position2 - position1 + 1];
	for (size_t i = position1, j = 0; i < position2; i++, j++)
		copy_text[j] = text[i];
	myString newText(copy_text);
	delete[] copy_text;
	return newText;
}

const size_t myString::size() const {
	if (text == nullptr)
		return 0;
	return strlen(text);
}

const char* myString::return_char_ptr() const {
	return text;
}

void myString::resize(const size_t addlength) {
	char* temp = new char[addlength];
	for (size_t i = 0; i < size(); ++i)
		temp[i] = text[i];
	free();
	text = temp;
}
