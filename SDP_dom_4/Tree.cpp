#include "Tree.h"
#include <iostream>

Node::Node()
{

}

Node::Node(Node& other)
{
	value = other.value;
	children = other.children;
	cName = other.cName;
}

Node& Node::operator=(Node& other)
{
	if (this != &other)
	{
		value = other.value;
		children = other.children;
		cName = other.cName;
	}
	return *this;
}

Node::~Node()
{
	for (auto i : children)
		delete i;
}


Tree::Tree()
{
	root = NULL;
	depth = 0;
	size = 0;
}


Tree::~Tree()
{
	delete root;
}



void Tree::build(std::string input)
{
	
}