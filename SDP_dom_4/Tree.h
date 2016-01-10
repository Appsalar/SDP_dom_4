#pragma once
#include <vector>
#include <string>

#ifdef SDP_DOM_4_EXPORTS
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif

struct Node
{
	int value;
	std::vector<Node*> children;
	std::string cName;

	Node();
	Node(Node&);
	Node& operator=(Node&);
	~Node();
};

class EXPORT Tree
{
private:
	Node* root;
	size_t depth;
	size_t size;

public:
	Tree();
	virtual ~Tree();

	void build(std::string);
};

