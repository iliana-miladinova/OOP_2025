#pragma once
#include <iostream>

class Bitset {
public:
	Bitset() = default;
	explicit Bitset(unsigned n);

	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	~Bitset();

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print() const;

	//size_t getElementsCount() const;
	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);

	friend Bitset UnionOfSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset IntersectionOfSets(const Bitset& lhs, const Bitset& rhs);
private:
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void copyFrom(const Bitset& other);
	void free();
	void resize(unsigned cap);

	unsigned getBucket(unsigned num) const;
	unsigned getPos(unsigned num) const;

	unsigned getNeededBuckets(unsigned num) const;
};