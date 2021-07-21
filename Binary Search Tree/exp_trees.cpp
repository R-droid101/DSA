/*
	Name: Raggav Subramani
	Registration number: 20BCT0127
	Purpose: To construct expression tree for a given infix expression.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class exp_tree
{
public:
	char data;
	exp_tree *left, *right;

public:
	exp_tree *new_node(char c)
	{
		exp_tree *n = new exp_tree;
		n->data = c;
		n->left = n->right = nullptr;
		return n;
	}

	exp_tree *create_tree(string &s) // function to create a expression tree from infix expression
	{
		stack<exp_tree *> stack_node; // stack to store nodes for tree
		stack<char> stack_characters; // stack to store characters in expression
		exp_tree *t, *t1, *t2;

		int priority[123] = {0}; // prioritising operators
		priority['+'] = priority['-'] = 1, priority['/'] = priority['*'] = 2, priority['^'] = 3,
		priority[')'] = 0;

		for (int i = 0; i < s.length(); i++) // iterating to each character in the string
		{
			if (s[i] == '(') 
				stack_characters.push(s[i]);

			else if (isalpha(s[i])) // if character is a alphabet, it pushes into stack
			{
				t = new_node(s[i]);
				stack_node.push(t);
			}
			else if (priority[s[i]] > 0) 
			{ // storing the operation in the tree
				while (!stack_characters.empty() && stack_characters.top() != '(' && ((s[i] != '^' && priority[stack_characters.top()] >= priority[s[i]]) || (s[i] == '^' && priority[stack_characters.top()] > priority[s[i]])))
				{
					t = new_node(stack_characters.top());
					stack_characters.pop();
					t1 = stack_node.top();
					stack_node.pop();
					t2 = stack_node.top();
					stack_node.pop();
					t->left = t2;
					t->right = t1;
					stack_node.push(t);
				}
				stack_characters.push(s[i]);
			}

			else if (s[i] == ')')
			{ // marking the end of an operation so storing it in the tree
				while (!stack_characters.empty() && stack_characters.top() != '(')
				{
					t = new_node(stack_characters.top());
					stack_characters.pop();
					t1 = stack_node.top();
					stack_node.pop();
					t2 = stack_node.top();
					stack_node.pop();
					t->left = t2;
					t->right = t1;
					stack_node.push(t);
				}
				stack_characters.pop();
			}
		}
		t = stack_node.top();
		return t;
	}

	void postorder(exp_tree *root)
	{ // function to print the postorder traversal of the tree
		if (root)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
	}

	void preorder(exp_tree *node)
	{ // function to print the preorder traversal of the tree
		if (node == NULL)
			return;
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}
};

int main() // main function to call functions and recieve input
{
	exp_tree obj;
	string s;
	cout << "Input infix string to create_tree expression tree: ";
	cin >> s;
	s = "(" + s + ")";
	exp_tree *root = obj.create_tree(s);
	cout << "Postorder traversal: ";
	obj.postorder(root);
	cout << endl;
	cout << "Preorder traversal: ";
	obj.preorder(root);

	return 0;
}
