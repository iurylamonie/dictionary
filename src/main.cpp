#include <iostream>

#include "dal.h"

class MyKeyComparator 
{
public :
	bool operator()( const int & lhs , const int & rhs ) const
	{
		return lhs < rhs ;
	}
};

int main()
{
	DAL<int, int, MyKeyComparator> d;
	d.insert(10,2);
	d.insert(10,3);
	d.insert(2,3);
	d.insert(3,3);
	int old;
	std::cout << d << std::endl;
	d.remove(10,old);
	std::cout << d << std::endl;
	d.insert(10,4);
	std::cout << d.min() << std::endl;
	std::cout << d.max() << std::endl;
	int key;
	std::cout << d << std::endl;
	d.sucessor(2, key);
	std::cout << key << std::endl;
	d.predecessor(2, key);
	std::cout << key << std::endl;
	d.sucessor(10, key);
	std::cout << key << std::endl;
	d.predecessor(3, key);
	std::cout << key << std::endl;
	return 0;
}