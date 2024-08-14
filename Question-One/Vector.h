#pragma once
#include <iostream>
using namespace std;

// class with template for all types
template <class T>
class Vector
{
public:
	// constructors
	Vector();		  // with no parameter, default
	Vector(int Size); // with one paramter, with size

	// destructor
	~Vector(); // to return memory back

public:
	// public funtions
	void Resize(int newSize);		  // resize vector to new size
	void PushBack(T a);				  // add element at the end of vector
	void Insert(int index, T value);  // insert element at index
	void Remove(int index);			  // remove element from index
	int GetSize() { return m_size; }; // return size of vector
	T &operator[](int index);		  // overload [] operator like array

private:
	int m_size; // size of vector
	T *m_data;	// pointer to dynamic array for keeping the vector
};

// default constructor
template <class T>
inline Vector<T>::Vector()
{
	// initialize m_size with 0
	m_size = 0;

	// initailize m_data to nullptr (null pointer)
	m_data = nullptr;
}

// constructor with size
template <class T>
Vector<T>::Vector(int Size)
{
	m_size = Size;			// initailize size value in m_size
	m_data = new T[m_size]; // allocate memory with the Size
}

// resize vector with new size
template <class T>
inline void Vector<T>::Resize(int newSize)
{
	if (newSize == m_size) // if new size equals current size, return
		return;

	T *temp = m_data;		 // save current data
	m_data = new T[newSize]; // allocate a new memory array for new size

	int less = (newSize > m_size) ? m_size : newSize; // find how many number of elements to copy

	for (size_t i = 0; i < less; i++) // copy current elements to new array
	{
		m_data[i] = temp[i];
	}

	m_size = newSize; // update new size
	delete[] temp;	  // delete memory back
}

// add new element at the end of vector
template <class T>
void Vector<T>::PushBack(T a)
{
	// first resize, then copy new element
	Resize(m_size + 1);		// increase size with 1
	m_data[m_size - 1] = a; // add new element at the end (in last index, size - 1)
}

// destructor to return memory back to system
template <class T>
Vector<T>::~Vector()
{
	delete[] m_data; // free all memory back
}

// overload [] operator like array
template <class T>
T &Vector<T>::operator[](int index)
{
	if (index >= m_size) // check correct index, not out-of-bound
	{
		std::cout << "Array index out of bound, exit...";
		exit(0); // exit if index is out of bound
	}
	return m_data[index]; // return element at index
}

// insert an element at index
template <class T>
void Vector<T>::Insert(int index, T value)
{
	if (index < 0 || index > m_size) // check for out-of-bound index
	{
		std::cout << "Index out of bound, exit...";
		exit(1); // exit if index is out of bound
	}

	Resize(m_size + 1); // increase size with 1

	// move from last to index one by one
	for (int i = m_size - 1; i > index; --i) // move all elements one to right
	{
		m_data[i] = m_data[i - 1];
	}

	m_data[index] = value; // insert new element at index
}

// remove element from index
template <class T>
void Vector<T>::Remove(int index)
{
	if (index < 0 || index >= m_size) // check for out-of-bound index
	{
		std::cout << "Index out of bound, exit...";
		exit(1); // exit if index is out of bound
	}

	// move from index to end of vector (array)
	for (int i = index; i < m_size - 1; ++i) // move all elements to left
	{
		m_data[i] = m_data[i + 1];
	}

	Resize(m_size - 1); // decrease size with 1
}

/////////////////////////////

// overload << operator for print vector with cout
template <class T>
ostream &operator<<(std::ostream &out, Vector<T> &vector)
{
	int size = vector.GetSize();

	if (size > 0)
	{
		out << '\n';
		for (int i = 0; i < size; i++) // print each element with for loop
		{
			out << vector[i] << ", ";
		}
	}
	else
	{
		out << "\n empty! \n"; // print message if vector is empty
	}
	return out;
}