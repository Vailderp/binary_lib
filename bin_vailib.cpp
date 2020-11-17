#include "bin_vailib.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
const int bitsy = 8;
int bin_vailib::BinToDec(string bin)
{
    int binlen = bin.length() - 1;
    int num = 0;
    for (size_t i = 0; i < bin.length(); i++)
    {
        if (bin[i] == '0')
        {
            num += 0;
        }
        else if (bin[i] == '1')
        {
            num += int(bin[i] - '0') * pow(2, binlen - i);
        }
    }
    return num;
}
string bin_vailib::DecToBin(int dec)
{
    string output = "";
    int len = 0;
    while (dec >> len > 0)
    {
        output += to_string((dec >> len) % 2);
        len++;
    }
    reverse(output.begin(), output.end());
    return output;
}
string bin_vailib::GetBinChar(char c) {
    int k = 128;
    string bin = "";
    while (k > 0) {
        bin += to_string(bool(c & k));
        k = k >> 1;
    };
    return bin;
};
string bin_vailib::GetBinText(string inputtxt)
{
    string bin_chars = "";
    string timermaptrext;
    for (size_t i = 0; i < inputtxt.length(); i++)
    {
        bin_chars += GetBinChar(inputtxt[i]);
    }
    return bin_chars;
}
string bin_vailib::GetBinFile(string path)
{
    string bin_chars = "";
    fstream mapfile;
    mapfile.open(path);
    string timermaptrext;
    string txt = "";
    while (getline(mapfile, timermaptrext)) {
        txt += timermaptrext;
    }
    for (size_t i = 0; i < txt.length(); i++)
    {
        bin_chars += GetBinChar(txt[i]);
    }
    return bin_chars;
    mapfile.close();
}
string bin_vailib::SetBinFile(string bin, string path)
{
    string output;
    fstream mapfile;
    mapfile.open(path);
    if (bin.length() % bitsy == 0)
    {
        for (size_t i = 0; i < bin.length() / bitsy; i++)
        {
            string tt = "";
            for (size_t l = 0; l < bitsy; l++)
            {
                tt += bin[i * bitsy + l];
            }
            char charset(BinToDec(tt));
            output += charset;
        }
    }
    else
    {
        cout << endl << "ERROR: BIN % 8 != 0";
    }
    mapfile << output;
    mapfile.close();
    return output;
}
string bin_vailib::SetBinString(string bin)
{
    string output;
    if (bin.length() % bitsy == 0)
    {
        for (size_t i = 0; i < bin.length() / bitsy; i++)
        {
            string tt = "";
            for (size_t l = 0; l < bitsy; l++)
            {
                tt += bin[i * bitsy + l];
            }
            char charset(BinToDec(tt));
            output += charset;
        }
    }
    else
    {
        cout << endl << "ERROR: BIN % 8 != 0";
    }
    return output;
}
string bin_vailib::CreateNSBin(string input, NUMBER_SYSTEM ns)
{
    string output = "";
    for (size_t i = 0; i < input.length(); i++)
    {
        string tt = "";
        tt = DecToBin(ns.chars.find_first_of(input[i]));
        while (tt.length() < 4)
        {
            tt = "0" + tt;
        }
        output += tt;
    }
    return output;
}
string bin_vailib::GetNSBin(string input, NUMBER_SYSTEM ns)
{
    string output = "";
    for (size_t i = 0; i < input.length(); i += ns.bitsy)
    {
        string bin = "";
        for (size_t l = 0; l < ns.bitsy; l++)
        {
            bin += input[i + l];
        }
        output += ns.chars[BinToDec(bin)];
    }
    return output;
}
