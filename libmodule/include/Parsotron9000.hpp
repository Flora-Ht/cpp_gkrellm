//
// parsotron9000.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 00:10:09 2017 Benjamin Grange
// Last update Sun Jan 22 07:07:38 2017 Benjamin Grange
//

#ifndef PARSOTRON9000_HPP
# define PARSOTRON9000_HPP

# include <vector>
# include <sstream>
# include <string>

namespace parsotron {

    template<typename T>
    T fromString(std::string const &ref) {
        T ret;
        std::stringstream stream(ref);

        stream >> ret;
        return (ret);
    }

    template<typename T>
    void split(std::vector<T> &v, std::string const &ref, char delim) {
        size_t i = 0;
        size_t pos = ref.find(delim);
        while (pos != std::string::npos) {
            v.push_back(fromString<T>(ref.substr(i, pos - i)));
            i = ++pos;
            pos = ref.find(delim, pos);
            if (pos == std::string::npos) {
                v.push_back(fromString<T>(ref.substr(i, ref.length())));
            }
        }
    }

    template<typename T>
    void split_all(std::vector<T> &v, std::string const &ref, char delim) {
        std::stringstream ss(ref);
        std::string word;
        while (getline(ss, word, delim)) {
            if (word.size() > 0) {
                v.push_back(fromString<T>(word));
            }
        }
    }
}
#endif /* !PARSOTRON9000_HPP */
