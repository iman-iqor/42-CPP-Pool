#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>

int is_valid_file(int argc, char **argv);
std::string delete_spaces(std::string s);
std::map<std::string, double> refDataMap(std::string fileName);
bool isValidDate(const std::string &date);
bool isValidAmount(const std::string &amount);



#endif