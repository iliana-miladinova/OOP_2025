#include <iostream>

template <typename T>
class HeterogeneousContainer {
public:
	HeterogeneousContainer();
	HeterogeneousContainer(const HeterogeneousContainer& other);
	HeterogeneousContainer<T>& operator=(const HeterogeneousContainer& other);
	HeterogeneousContainer(HeterogeneousContainer&& other) noexcept;
	HeterogeneousContainer<T>& operator=(HeterogeneousContainer&& other) noexcept;
	~HeterogeneousContainer();

	void addObj(T* obj);
	void addObj(const T& obj);

	size_t getSize() const;

	void remove(size_t ind);

	const T* operator[](size_t ind) const;
	T* operator[](size_t ind);

	void swap(int ind1, int ind2);
private:
	T** objects = nullptr;
	size_t size = 0;
	size_t cap = 8;

	void copyFrom(const HeterogeneousContainer& other);
	void moveFrom(HeterogeneousContainer&& other) noexcept;
	void free();

	void resize(size_t new cap);
};

template <typename T>
HeterogeneousContainer<T>::HeterogeneousContainer() {
	objects = new T * [cap] {};
}

template <typename T>
void HeterogeneousContainer<T>::copyFrom(const HeterogeneousContainer& other) {
	size = other.size;
	cap = other.cap;
	objects = new T * [cap] {};
	for (size_t i = 0; i < size; i++)
	{
		objects[i] = other.objects[i]->clone();
	}
}

template <typename T>
void HeterogeneousContainer<T>::moveFrom(HeterogeneousContainer&& other) noexcept {
	objects = other.objects;
	other.objects = nullptr;

	size = other.size;
	cap = other.cap;
	other.size = other.cap = 0;
}

template <typename T>
void HeterogeneousContainer<T>::free() {
	for (size_t i = 0; i < size; i++)
	{
		delete objects[i];
	}
	delete[] objects;
	objects = nullptr;
}

template <typename T>
void HeterogeneousContainer<T>::resize(size_t newCap) {
	T** resized = new T * [newCap] {};
	for (size_t i = 0; i < size; i++)
	{
		resized[i] = objects[i];
	}
	delete[] objects;
	objects = resized;
	cap = newCap;
}

template <typename T>
HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer& other) {
	copyFrom(other);
}

template <typename T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(const HeterogeneousContainer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
HeterogeneousContainer<T>::HeterogeneousContainer(HeterogeneousContainer&& other) noexcept {
	moveFrom(std::move(other));
}

template <typename T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(HeterogeneousContainer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
HeterogeneousContainer<T>::~HeterogeneousContainer() {
	free();
}

template <typename T>
size_t HeterogeneousContainer<T>::getSize() const {
	return size;
}

template <typename T>
const T* HeterogeneousContainer<T>::operator[](size_t ind) const {
	if (ind >= size) {
		throw std::invalid_argument("Invalid ind");
	}
	return objects[ind];
}

template <typename T>
T* HeterogeneousContainer<T>::operator[](size_t ind) {
	if (ind >= size) {
		throw  std::invalid_argument("Invalid ind");
	}
	return objects[ind];
}

template <typename T>
void HeterogeneousContainer<T>::addObj(T* obj) {
	if (!obj) {
		throw std::exception("Nullptr");
	}
	if (size >= cap) {
		resize(cap * 2);
	}
	objects[size++] = obj;
}

template <typename T>
void HeterogeneousContainer<T>::addObj(const T& obj) {
	if (size>=cap)
	{
		resize(cap * 2);
	}
	objects[size++] = obj.clone();
}

template <typename T>
void HeterogeneousContainer<T>::remove(size_t ind) {
	if (ind >= size) {
		throw std::out_of_range("Invalid ind");
	}
	delete objects[ind];
	for (size_t i = ind; i < size-1; i++)
	{
		objects[i] = objects[i + 1];
	}
	objects[size - 1] = nullptr;
	size--;
}

template <typename T>
void HeterogeneousContainer<T>::swap(int ind1, int ind2) {
	std::swap(objects[ind1], objects[ind2]);
}