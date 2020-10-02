//Vigenere Cipher 
#include<bits/stdc++.h> 
using namespace std; 

string generateKey(string str, string key) 
{ 
	int x = str.size();
	for (int i = 0; ; i++)
	{
		if (x == i) 
			i = 0; 
		if (key.size() == str.size()) 
			break; 
		key.push_back(key[i]); 
	} 
	return key; 
} 

string encrypt(string str, string key) 
{ 
	string cipher_text; 

	for (int i = 0; i < str.size(); i++) 
	{ 
		char x = (((str[i] + key[i]) %26) + 65);
		cipher_text.push_back(x); 
	} 
	return cipher_text; 
} 

string decrypt(string cipher_text, string key) 
{ 
	string orig_text; 

	for (int i = 0 ; i < cipher_text.size(); i++) 
	{ 
		char x = (((cipher_text[i] - key[i] + 26) %26) +65); 
		orig_text.push_back(x); 
	} 
	return orig_text; 
} 

int main() 
{ 

    string text="", keyword="", key=""; 
    int sel=0;
    char ch='y'; 
	cout<<"===VIGENERE CIPHER==="<<endl;
	
	do {
		cout<<"\nMenu\n1.Encrypt\n2.Decrypt\n";
		cout << "Enter the input : ";
		cin>>sel;
		switch(sel) {
			case 1:
				cout << "Enter the text : ";
				cin.ignore();
				getline(cin,text); 	
				cout<< "Enter the key: ";
				getline(cin,keyword);
				key = generateKey(text,keyword);
				cout << "Encrypted Text is(Cipher Text) : " << encrypt(text,key) <<endl;
				break;
			case 2:
				cout << "Enter the text : ";
				cin.ignore();
				getline(cin,text);
				cout<<"Using the key provided earlier"<<endl;
				key = generateKey(text,keyword);
				cout << "Decrypted Text is(Plain Text) : " << decrypt(text, key) <<endl;
				break;
			default:
				cout<<"Enter the correct option";
				break;
			}
			cout<<"If you wish to exit press n else press any key: ";
			cin>>ch;
		}while(ch!='n');
	return 0;
} 
