#include "Libraries.h"
#include <vector>
#include <string>
#include"LinkedList.h" 
#include <bitset>



#define LOG(x) std::cout << x << std::endl;




int main() 
{
	LinkedList<char> dude; 

	

	dude.insert_node('e');
	dude.insert_node('e');
	dude.insert_node('e');
	dude.insert_node('e');
	dude.insert_node('e');


	dude.PrintInfo();
	dude.DeleteLinkedList();

	


}