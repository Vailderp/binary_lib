#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
class bin_vailib
{
public:

	class NUMBER_SYSTEM
	{
	public:

		string chars = "0123456789ABCD;=";
		string closecharbin = "1110";
		int len = 16;
		int bitsy = 4;

	};

	int BinToDec(string bin);

	string DecToBin(int dec);

	string ReadFile(string path);

	void WriteFile(string input, string path);

	string GetBinChar(char c);

	string GetBinText(string inputtxt);

	string GetBinFile(string path);

	void SetBinFile(string bin, string path);

	string SetBinString(string bin);

	string CreateNSBin(string input, NUMBER_SYSTEM ns);

	string GetNSBin(string input, NUMBER_SYSTEM ns);

	map<string, string> ReadConf(string input);

	map<string, string> ReadConfFile(string path);

	string WriteConf(map<string, string> input);

	void WriteConfFile(map<string, string> input, string path);
	
	string BeautiferConf(string input);
};
