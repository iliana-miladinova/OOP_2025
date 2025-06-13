#pragma once
#include "MyString.h"

class StringView {
private:
	const char* begin;
	const char* end;

public:
	StringView() = default;
	StringView(const char* begin, const char* end);
	StringView(const char* str);
	StringView(const MyString& str);

	size_t length() const;

	const char operator[](size_t ind) const;

	StringView substr(size_t from, size_t count);

	friend std::ostream& operator<<(std::ostream& os, const StringView& str);
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);