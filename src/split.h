#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H

#include <string>
#include <sstream>
#include <vector>

// thanks to Evan Teran on stackoverflow
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

#endif