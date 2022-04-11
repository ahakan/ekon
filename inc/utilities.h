/**
 * @file utilities.h
 * @author ahmet hakan celik (mail@ahakan.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef UTILITIES_H
#define UTILITIES_H


// Standard library includes
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <bitset>
#include <string>
#include <bits/stdc++.h> 


/**
 * @brief Utilities class
 * 
 */
class Utilities
{
    private: 
        std::string         parsing7Bits(std::string data);
        std::string         addStopBit(std::string data, bool last);
        const char*         conHexCharToBinary(char c);
        const char*         conBinaryToHexChar(std::string data);

    public:
                            Utilities();
                            ~Utilities();


        std::string         conAsciiToHex(std::string data);
        std::string         conDecToBinary(uint64_t data);
        std::string         conHexToBinary(std::string data);
        std::string         conBinaryToHex(std::string data);
        std::string         stopBitEncoding(std::string data);

};


#endif