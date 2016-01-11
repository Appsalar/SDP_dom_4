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
	std::string::iterator it = input.begin();

	addNote(input, it);
}


void Tree::addNote(std::string& input, std::string::iterator& it, Node* parent)
{
	++depth;
	Node* foo = NULL;
	while (it != input.end())
	{
		bool flag = false;
		if (*it == '(')
		{
			foo = new Node;
			++it;
			flag = true;
			++size;
		}

		if (it != input.end() && isdigit(*it))
		{
			foo->value = atoi(&(*it));
			std::advance(it, log10(foo->value) + 1);
			/*while (*it >= '0' && *it <= '9')
				++it;*/
		}

		while (it != input.end() && (*it == ' ' || *it == ')'))
			++it;

		if (!parent)
		{
			root = foo;
			parent = root;
			continue;
		}
		else if (flag)
			parent->children.push_back(foo);

		if (it != input.end() && *it == '{')
		{
			++it;
			if (*it == '}')
				++it;
			else
				addNote(input, it, foo);
		}

		if (it != input.end() && *it == '}')
		{
			++it;
			return;
		}
	}
}


void Tree::AssigCanonName()
{
	SetName(root);
}

const std::string& Tree::GetCanonName() const
{
	return root->cName;
}

const size_t Tree::GetDepth() const
{
	return depth;
}

const size_t Tree::GetSize() const
{
	return size;
}


void Isort(std::vector<Node*>& Arr)
{
	for (size_t i = Arr.size() - 1; i != 0; --i)
	{
		if (Arr[i - 1]->cName.compare(Arr[i]->cName) > 0)
		{
			Node* foo = Arr[i - 1];
			Arr[i - 1] = Arr[i];
			Arr[i] = foo;
		}
	}

	for (size_t i = 2; i < Arr.size(); ++i)
	{
		Node* foo = Arr[i];

		size_t j = i;
		while (Arr[j]->cName.compare(foo->cName) > 0)
		{
			Arr[j] = Arr[j - 1];
			--j;
		}
		Arr[j] = foo;
	}
}


void Tree::SetName(Node* target)
{
	if (!target)
		target = root;

	if (target->children.size() == 0)
		target->cName = "10";
	else
	{
		for (auto& i : target->children)
			SetName(i);

		std::vector<Node*> temp = target->children;
		Isort(temp);
		target->cName = "1";
		for (auto& i : temp)
			target->cName += i->cName;

		target->cName.push_back('0');
	}
}


bool Tree::AreIsomorphic(Tree& other)
{
	if (GetDepth() != other.GetDepth())
		return false;

	if (GetSize() != other.GetSize())
		return false;

	AssigCanonName();
	other.AssigCanonName();

	if (GetCanonName() != other.GetCanonName())
		return false;

	return true;
}

/*bool AreIsomorphic(Tree& a, Tree& b)
{
	if (a.GetDepth() != b.GetDepth())
		return false;

	if (a.GetSize() != b.GetSize())
		return false;

	a.AssigCanonName();
	b.AssigCanonName();

	if (a.GetCanonName() != b.GetCanonName())
		return false;

	return true;
}*/