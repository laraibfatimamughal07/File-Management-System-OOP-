#include"File.h"
File::File(string name, Node* parent) :Node(name, parent)
{
	currentLine = 0;
}
bool File::isFolder()
{
	return false;
}
File::~File()
{

}