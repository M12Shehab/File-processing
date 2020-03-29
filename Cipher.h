#pragma once
#include <string>
class Cipher {
	std::string text_orignal;
	std::string text_cipher;
	int shifts;
public:
	Cipher();
	~Cipher();

	std::string get_text_orignal();
	std::string get_text_cipher();

	void set_text_orignal(std::string);
	void set_text_cipher(std::string);
	void caesar_cipher();
};