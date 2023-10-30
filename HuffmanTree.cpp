#include <string>
#include <iostream>
#include <queue>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;


//function to return binary code to an accepted string:

void HuffmanTree::buildHuffmanTree(string s)//build the tree by string
{
	root = NULL;//initialize all the values that the HuffmanTree contain
	theWord = s;
	letter = "";
	structore = "";
	for (int i = 0; i < 26; i++)
		theCode[i] = "";
	int size = s.length();
	for (int i = 0; i < 26; i++)//find the frequencies of the letters
		freq[i] = 0;
	for (int i = 0; i < size; i++)
		if (freq[s[i] - 96]++ == 0)
			lettersNum++;
	for (int i = 0; i < 26; i++)
		if (freq[i] > 0)
		{
			HuffmanNode* node = new HuffmanNode;//build the queue
			node->str = i + 96;
			node->frequency = freq[i];
			que.push(node);
		}
	buildTree(); //build the tree by the frequencies and the queue that saved as a fields in the HuffmanTree that was build
	letters(root, letter);//find the letters by their order in the tree and sava it in the HuffmanTree in 'letter' 
	structure(root, structore);//find the binary code fo the structore and sava it in the HuffmanTree in 'structore' 
	code(root, "");//find the binary code of the whole letters and save it in the 'the conde'
	endTheCode();//find the binary code of the string and save it in the 'endCode'
}

void HuffmanTree::buildTree()
{
	while (true) {
		HuffmanNode* node1 = que.top();
		que.pop();
		HuffmanNode* node2 = que.top();
		que.pop();
		HuffmanNode* LocalRoot = new HuffmanNode;
		LocalRoot->frequency = node1->frequency + node2->frequency;
		LocalRoot->right = node2;
		LocalRoot->left = node1;
		if (node1->frequency == node2->frequency) {
			LocalRoot->right = node1;
			LocalRoot->left = node2;
		}
		if (que.empty()) {
			root = LocalRoot;
			return;
		}
		que.push(LocalRoot);
	}
}

void HuffmanTree::letters(HuffmanNode* node, string& theCode)
{
	if (node->left == NULL && node->right == NULL) {
		theCode += node->str;
		return;
	}
	letters(node->left, theCode);
	letters(node->right, theCode);
}

void HuffmanTree::structure(HuffmanNode* node, string& theCode)
{
	if (node->left == NULL && node->right == NULL) {
		theCode = theCode + '1';
		return;
	}
	structure(node->left, theCode += '0');
	structure(node->right, theCode);
}
void HuffmanTree::code(HuffmanNode* node, string s)//
{
	if (node->left == NULL && node->right == NULL) {
		theCode[node->str - 96] = s;
		return;
	}
	code(node->left, s + '0');
	code(node->right, s + '1');
}

void HuffmanTree::endTheCode()//end's code
{
	for (int i = 0; i < theWord.size(); i++)
		endCode += theCode[theWord[i] - 96];
}

//function to return a string to an accepted binary code 
void HuffmanTree::buildTree(string& code, string& letters, HuffmanNode* node, bool& check)   // build tree with a binary code
{
	if (code[0] == '0') {  //build a new node that has left node and right node
		node->left = new HuffmanNode;
		node->right = new HuffmanNode;
		string newStr = "";
		for (int i = 1; i < code.length(); i++)
			newStr += code[i];//cut the code by 1
		code = newStr;
		buildTree(code, letters, node->left, check);  // do it for the left
		buildTree(code, letters, node->right, check);  // do it for the right
	}
	else if (code[0] == '1') {  // if it is a leaf
		if (letters.length() == 0)  // if there are no letters any more
			check = false;
		node->str = letters[0];  // else get in it the letter
		string newStr = "";
		for (int i = 1; i < letters.length(); i++)
			newStr += letters[i];//cut the letter
		letters = newStr;
		newStr = "";
		for (int i = 1; i < code.length(); i++)
			newStr += code[i];
		code = newStr;
		return;
	}
}

void HuffmanTree::treeConversion(int n, string letter, string  structo, string enCode)//build the string from tree
{
	root = new HuffmanNode;
	bool check = true;   // check if the tree is not regular, send to the function by refernce
	buildTree(structo, letter, root, check);
	if (check) {
		string word = buildString(root, enCode);
		cout << "The decoded string is " << endl;
		cout << word << endl;
	}
	else
		cout << "ERROR" << endl;
}

string HuffmanTree::buildString(HuffmanNode* node, string theCode)
{
	{
		string decode = "";
		for (int i = 0; i <= theCode.length(); i++) {
			if (node->left == NULL && node->right == NULL) {  //when the node is a leaf this str will be enter to the string
				decode += node->str;
				node = root;
			}
			if (theCode[i] == '0')
				node = node->left;
			if (theCode[i] == '1')
				node = node->right;
		}
		return decode;
	}

}