#include <iostream>
#include <malloc.h>
#include <string>
#include <LinearList.h>
#include <expection.h>

using namespace std;

template <class T>
class LinearList
{
private:
	int length;
	int MaxSize;
	T* element;
public:
	LinearList(int MaxListSize=10);
	~LinearList() {delete []element;}
	bool IsEmpty();
	int  length() const {return length;}
	bool Find(int k,T& x);
	int  Search(const T& x) const;
	LinearList<T>& Delete(int k,const T& x);
	LinearList<T>& Insert(int k,const T& x);
	LinearList<T>& operator<<(iostream output,LinearList<T>& list);
};

template <class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize=MaxListSize;
	element=new T[MaxSize];
	length=0;
}

template <class T>
bool LinearList<T>::IsEmpty()
{
	if(length==0)
		return true;
	else
		return false;
}

template <class T>
bool LinearList<T>::Find(int k,T& x)
{
	if(k<0||k>MaxSize)
	{
		throw OutOfBound;
		return false;
	}
	x=element[k-1];
	return true;
}

template <class T>
int LinearList<T>::Search(const T& x) const
{
	while(int i=length;i>0;i++)
	{
		if(element[i-1]==x)
			return i-1;
	}
	return 0;
}

template <class T>
LinearList<T>& LinearList<T>::Delete(int k,const T& x);
{
	if(k>length)
		throw OutOfBound;
	if(Find(k,x))
	{
		while(int i=k;i<length-1;i++)
			element[i]=element[i-1];
		--length;
		return *this;
	}
	else
		throw NoMen;
}

template <class T>
LinearList<T>& LinearList<T>::Insert(int k,const T& x);
{
	if(length+1>MaxSize)
		throw NoMen;
	if(k<0||k>length)
		throw OutOfBound;
	while(int i=length-1;i>=k;i--)
		element[i+1]=element[i];
	element[k]=x;
	++length;
	return *this;
}
