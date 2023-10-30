/*RACHEL BERLIN 212316400
MICHAL HABIB 212329221*/
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
using namespace std;


int main()
{
	char choice;
	string word;
	int n;
	string letters, structure, enCode;

	HuffmanTree* t; 


	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
            t = new HuffmanTree();
			cout << "enter the original text" << endl;
			cin >> word;
			t->buildHuffmanTree(word);
			cout << "The encoded string is:\n";
			cout << t->getNum() << endl;
			cout << t->getLetters() << endl;
			cout << t->getStruct() << endl;
			cout << t->getCode() << endl;
			break;
		case 'D':
            t = new HuffmanTree();
			cout << "enter n " << endl;
			cin >> n;
			cout << "enter the letters " << endl;
			cin >> letters;
			cout << "enter the encoded structure " << endl;
			cin >> structure;
			cout << "enter the encoded text " << endl;
			cin >> enCode;
			t->treeConversion(n, letters, structure, enCode);
			break;
		}

	} while (choice != 'X');
	cout<<"bye";
	return 0;
}