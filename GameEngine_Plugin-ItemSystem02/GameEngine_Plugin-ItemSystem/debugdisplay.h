#ifndef __DEBUGDISPLAY_H__
#define __DEBUGDISPLAY_H__
//	Library includes
#include <vector>
#include <string>


//	Local includes


//	Class pre-declaration
class C_Item;


//	Function declarations
void Print(std::string _Text);
void Print(const char* _Text);
void Print(std::vector<C_Item*> _Vector);
void Print(std::vector<std::vector<C_Item*>> _Vector);


#endif