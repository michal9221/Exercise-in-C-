#pragma once
#include <string>
#include <iostream>
#include <queue>
#include "HuffmanNode.h"
using namespace std;

class HuffmanTree
{
protected:
	HuffmanNode* root;
	string theWord;
	int freq[26];
	int lettersNum;
	string letter;
	string structore;
	string theCode[26];
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> que;
	string endCode;
public:
	HuffmanTree()//c-tor
	{
		for (int i = 0; i < 26; i++)
		{
			freq[i] = 0;
			theCode[i] = "";
		}
		root = NULL;
	}
	~HuffmanTree()  //d-tor
	{
		for (int i = 0; i < 26; i++)
		{
			freq[i] = 0;
			theCode[i] = "";
		}
		root = NULL;
	}
	void buildTree(string& code, string& letters, HuffmanNode* node, bool& check);
	void buildHuffmanTree(string s);
	int getNum() { return lettersNum; }
	string getLetters() { return letter; }
	string getStruct() { return structore; }
	string getCode() { return endCode; }
	void treeConversion(int, string, string, string);
	string buildString(HuffmanNode* node, string theCode);

private:
	void buildTree();
	void letters(HuffmanNode* node, string& theCode);
	void structure(HuffmanNode* node, string& theCode);
	void code(HuffmanNode* node, string str);
	void endTheCode();
};
