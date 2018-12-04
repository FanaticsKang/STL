#include<iostream>
#include<memory>
#include<string>


using namespace std;

int main(int argc, char **argv)
{
	std::unique_ptr<string> pname(new string("HelloWorld"));
	
	//For C++14
	auto pname_make = std::make_unique<string>(3, '?');
	
	cout << *pname <<endl;
	
	cout << *pname_make <<endl;
	
	std::shared_ptr<string> p_sharedName(new string("HelloWorld_shared_ptr"));
	std::shared_ptr<string> p_sharedName2 = p_sharedName;
	
	cout << *p_sharedName <<endl;	
	
	cout << *p_sharedName2 <<endl;

}
