// 
//
//  Lab session 10
//
//  Created by Mohammed Shehab on 3/29/20.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#include "Cipher.h"
#include <iostream>
using namespace std;
Cipher::Cipher()
{
	text_cipher = text_orignal = "";
	shifts = 5;
}

Cipher::~Cipher()
{
	cout << "+ Cipher finished.\n";
}

 string Cipher::get_text_orignal()
{
	return  this->text_orignal;
}

 string Cipher::get_text_cipher()
{
	return  this->text_cipher;
}

void Cipher::set_text_orignal(string text)
{
	this->text_orignal = text;
}

void Cipher::set_text_cipher(string text)
{
	this->text_cipher = text;
}

void Cipher::caesar_cipher()
{
	if (this->text_orignal.size() > 0)
	{
		// encryption process
		int len = this->text_orignal.size();
		for (int pos = 0; pos < len; ++pos)
		{
			this->text_cipher += this->text_orignal[(pos + shifts) % len];
		}
	}
	else if (this->text_cipher.size() > 0)
	{
		// decryption process
		int len = this->text_cipher.size();
		for (int pos = 0; pos < len; ++pos)
		{
			this->text_orignal += this->text_cipher[(len + pos - shifts) % len];
		}
	}
	else
	{
		cout << "- caesar cipher error, unknow process.\n";
	}
}
