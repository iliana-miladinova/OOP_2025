#include "Bitset.h"

unsigned Bitset::getNeededBuckets(unsigned num) const {
	unsigned res = num / 8;
	if (num % 8 != 0) {
		res++;
	}
	return res;
}

unsigned Bitset::getBucket(unsigned num) const {
	return num / 8;
}

unsigned Bitset::getPos(unsigned num) const {
	return num % 8;
}

void Bitset::copyFrom(const Bitset& other) {
	bucketsCount = other.bucketsCount;
	buckets = new uint8_t[bucketsCount];
	N = other.N;
	for (size_t i = 0; i < bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}

}

void Bitset::resize(unsigned cap) {
	uint8_t* resized = new uint8_t[cap];
	for (size_t i = 0; i < bucketsCount; i++)
	{
		resized[i] = buckets[i];
	}
	delete[] buckets;
	buckets = resized;
	bucketsCount = cap;
}

void Bitset::free() {
	delete[] buckets;
}

Bitset::Bitset(unsigned n) {
	bucketsCount = getNeededBuckets(n);
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = n;
}

Bitset::Bitset(const Bitset& other) {
	copyFrom(other);
}

Bitset& Bitset::operator=(const Bitset& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Bitset::~Bitset() {
	free();
}

void Bitset::add(unsigned num) {
	unsigned bucketInd = getBucket(num);
	unsigned pos = getPos(num);
	if (bucketInd >= bucketsCount) {
		resize(bucketInd + 1);
	}
	uint8_t mask = 1 << pos;
	buckets[bucketInd] |= mask;
	N = std::max(N, num);
}

void Bitset::remove(unsigned num) {
	unsigned bucketInd = getBucket(num);
	unsigned pos = getPos(num);
	if (bucketInd >= bucketsCount) {
		throw std::invalid_argument("Invalid element to remove");
	}
	uint8_t mask = ~(1 << pos);
	buckets[bucketInd] &= mask;
}

bool Bitset::contains(unsigned num) const{
	if (num >= N) {
		return false;
	}
	unsigned bucketInd = getBucket(num);
	unsigned pos = getPos(num);
	uint8_t mask = 1 << pos;
	return buckets[bucketInd] & mask;
}

void Bitset::print() const {
	std::cout << "{";
	for (size_t i = 0; i <= N; i++)
	{
		if (contains(i)) {
			std::cout << i << " ";
		}
	}
	std::cout << "}" << std::endl;
}

Bitset UnionOfSets(const Bitset& lhs, const Bitset& rhs) {
	Bitset res(std::max(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (size_t i = 0; i < minBucketsCount; i++)
	{
		res.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}

	const Bitset& biggerN = (lhs.N > rhs.N ? lhs : rhs);
	for (size_t i = minBucketsCount; i < biggerN.bucketsCount; i++)
	{
		res.buckets[i] = biggerN.buckets[i];
	}
	return res;
	
}

Bitset IntersectionOfSets(const Bitset& lhs, const Bitset& rhs) {
	Bitset res(std::min(lhs.N, rhs.N));
	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (size_t i = 0; i < minBucketsCount; i++)
	{
		res.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}
	return res;
}

void Bitset::serialize(std::ostream& os) const {
	for (size_t i = 0; i < elementsInBucket*bucketsCount; i++)
	{
		if (contains(i)) {
			os << i << " ";
		}
	}
}

void Bitset::deserialize(std::istream& is) {
	unsigned num = 0;
	while (is >> num) {
		add(num);
	}
}