#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class bin_vailib
{
public:

	class NUMBER_SYSTEM
	{
		public:

			string chars = "0123456789ABCDEF";
			int len = 16;
			int bitsy = 4;

	};

	int BinToDec(string bin);

	string DecToBin(int dec); 

	string GetBinChar(char c);

	string GetBinText(string inputtxt);

	string GetBinFile(string path);

	string SetBinFile(string bin, string path);

	string SetBinString(string bin);

	string CreateNSBin(string input, NUMBER_SYSTEM ns);

	string GetNSBin(string input, NUMBER_SYSTEM ns);

};
