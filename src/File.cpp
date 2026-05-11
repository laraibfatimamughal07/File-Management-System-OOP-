#include"File.h"
File::File(string name, Node* parent) :Node(name, parent)
{
	currentLine = 0;	//Start of File, Empty File created, line no = 0
}
bool File::isFolder()
{
	return false;
}
File::~File()
{

}