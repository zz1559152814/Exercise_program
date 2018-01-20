#include <iostream>
#include <SimChain.h>

template <class T>
class SimNode
{
	friend SimSpace<T>;
	friend SimChain<T>;
private:
	T data;
	int link;
};

template <class T>
class SimSpace
{
	friend 	SimSpace<T>& operate<<(iostream output,SimSpace<T>& simspace);
	friend SimChain<T>;
public:
	SimSpace(int MaxSpaceSize);
	~SimSpace() {delete []node;}
	int  Allocate();
	void Deallocate(int i);
	void Print();
	void Insert(int i,T& data);
	void Delete(int i);
private:
	int NumberOfNodes,first;
	SimSpace<T> *node;
};

SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes=MaxSpaceSize;
	node=new SimSpace<T>[NumberOfNodes];
	for(int i=0;i<NumberOfNodes-1;i++)
		node[i].link=i+1;
	node[NumberOfNodes-1].link=-1;
	first=0;
}

SimSpace<T>::~SimSpace()
{
	delete [] node;
	for(int i=0;i<NumberOfNodes-1;i++)
		node[i]=-1;
	first=-1;
}

int SimSpace<T>::Allocate()
{
	if(first==-1)
		throw NoMen;
	first=node[first].link;
	return first;
}

void SimSpace<T>::Deallocate(int i)
{
	if(i<0||i>NumberOfNodes)
		throw OutOfBound;
	int j=first;
	while(node[j].link!=i)
		j=node[j].link;
	node[j].link=node[i].link;
	node[i].link=-1;
}
