//
// Parsontron9000.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 06:17:44 2017 Benjamin Grange
// Last update Sun Jan 22 06:39:53 2017 Benjamin Grange
//

#include <vector>
#include <string>
#include "Parsotron9000.hpp"

namespace parsotron
{
template<>
void split(std::vector<std::string> &v, std::string const &ref, char delim) {
    size_t i = 0;
    size_t pos = ref.find(delim);
    while (pos != std::string::npos) {
        v.push_back(ref.substr(i, pos - i));
        i = ++pos;
        pos = ref.find(delim, pos);
        if (pos == std::string::npos) {
            v.push_back(ref.substr(i, ref.length()));
        }
    }
}
}
