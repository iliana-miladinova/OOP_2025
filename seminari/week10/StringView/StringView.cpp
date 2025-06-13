#include "StringView.h"

StringView::StringView(const char* begin, const char* end) :begin(begin), end(end) {

}

StringView::StringView(const char* str) :StringView(str, str + strlen(str)) {

}

StringView::StringView(const MyString& str) :StringView(str.c_str()) {

}

size_t StringView::length() const {
	return end - begin;
}

const char StringView::operator[](size_t ind) const {
	if (begin + ind > end) {
		throw std::length_error("Invalid ind");
	}
	return begin[ind];
}

StringView StringView::substr(size_t from, size_t count) {
	if (begin + from + count > end) {
		throw std::length_error("Invalid ind");
	}

	return StringView(begin + from, begin + from + count);
}

std::ostream& operator<<(std::ostream& os, const StringView& str) {
	const char* iter = str.begin;
	while (iter != str.end) {
		os << *iter;
		iter++;
	}
	return os;
	{

	}
}

bool operator==(const StringView& lhs, const StringView& rhs) {
	if (lhs.length()!=rhs.length())
	{
		return false;
	}
	for (size_t i = 0; i < lhs.length(); i++)
	{
		if (lhs[i]!=rhs[i])
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const StringView& lhs, const StringView& rhs) {
	return !(lhs == rhs);
}