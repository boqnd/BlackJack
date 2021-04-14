#pragma once


template<typename T>
class Vector {
public:
	Vector();
	Vector(const Vector<T>& others);
	~Vector();
	
	
	const T operator[](int index) const;
	T& operator[](int index);
	Vector<T>& operator=(const Vector<T>& others);

	void print() const;
	void push_back(const T& value);
	void pop_back();
	void pop_front();

	int getSize() const;

private:
	T* data;
	int size;
};


template<typename T>
Vector<T>::Vector(){
	data = nullptr;
	size = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	data = new T[other.size];
	size = other.size;
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
Vector<T>::~Vector() {
	delete[] data;
}

template<typename T>
const T Vector<T>::operator[](int index) const {
	if(index < 0 || index > size - 1){
		std::cout << "Wrong index.";
		return data[0];
	}
	return data[index];
}
template<typename T>
T& Vector<T>::operator[](int index) {
	if (index < 0 || index > size - 1) {
		std::cout << "Wrong index.";
		return data[0];
	}
	return data[index];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		delete[] data;

		data = new T[other.size];
		size = other.size;
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template<typename T>
void Vector<T>::print() const {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << data[i] << "  ";
	}
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	temp[size++] = value;
	delete[] data;
	data = temp;
}

template<typename T>
void Vector<T>::pop_back() {
	size--;
	T* temp = new T[size];
	for (int i = 0; i < size ; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

template<typename T>
void Vector<T>::pop_front() {
	
	T* temp = new T[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = data[i + 1];
	}
	size--;
	delete[] data;
	data = temp;
}

template<typename T>
int Vector<T>::getSize() const {
	return this->size;
}