#include <iostream>

using namespace std;


template <class T>
class SimChain<T>
{
public:
	SimChain() {first = -1;}
	~SimChain() {Destroy();}
	void Destroy();
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	SimChain<T>& Delete(int k, T& x);
	SimChain<T>& Insert(int k, const T& x);
	SimChain<T>& operate<<(iostream output,SimChain<T>& simchain);
private:
	int first;
	static SimSpace<T> S;
};

template <class T>
void SimChain<T>::Destory()
{
	int current;
	while(current!=-1)
	{
		current=S.node[first].link;
		S.Deallocate[current];
	}
	first=-1;
}

template <class T>
int SimChain<T>::Lenght()
{
	if(first==-1)
		throw NoMen;
	int length=1;
	int i=first;
	while(node[i].link!=-1)
	{
		i=node[i].link;
		++length;
	}
	return length;
}

template <class T>
bool SimChain<T>::Find(int k,T& x) const
{
	if(k<1||k>S.NumberOfNodes)
		throw OutOfBound;
	if(first==-1)
		throw NoMen;
	int nodecout=1;
	int i=first;
	while(nodecout!=k)
	{
		i=node[i].link;
		++k;
	}
	if(node[i].data!=x)
		return false;
	else
		return true;
}

template <class T>
int SimChain<T>::Search(const T& x) const
{
	if(first==-1)
		throw NoMen;
	int i=first;
	int nodecout=1;
	while(node[i].data==x||node[i].link!=-1)
	{
		i=node[i].link;
		++nodecout;
	}
	if(node[i].data==x)
		return nodecout;
}

template <class T>
SimChain<T>& SimChain<T>::Delete(int k,T& x)
{
	if(k<1||k>S.NumberOfNodes||first=-1)
		throw OutOfBound;
	int nodecout=1;
	int i=first;
	while(nodecout==k||S.node[i].link==-1)
	{
		i=S.node[i].link;
		++nodecout;
	}
	if(k==1)
	{
		x=S.node[first].data;
		first=S.node[first].link;
		--S.NumberOfNodes;
	}
	else if(k!=1&&nodecout==k)
	{
		int j;
		j=S.node[i].link;
		x=S.node[i].data;
		--S.NumberOfNodes;
		S.node[i].link=S.node[j].link
	}
	else if(nodecout!=k&&S.node[i].link==-1)
		throw NoMen;
	return *this;
}

template <class T>
SimChain<T>& SimChain<T>::Insert(int k, const T& x);
{

}
