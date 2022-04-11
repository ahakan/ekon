/**
 * @file main.cpp
 * @author ahmet hakan celik (mail@ahakan.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Standard library includes
#include <iostream>
#include <string>
#include <memory>


// Headers
#include "../inc/utilities.h"


// Struct
struct data
{
    uint64_t A      = 1649689334333;
    std::string B   = "DOLAR22";
    int64_t C       = -45678559022;
}exchange_data;


/**
 * @brief Main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    std::unique_ptr<Utilities> pUtil;
    
    std::string decimalToBin = pUtil.get()->conDecToBinary(exchange_data.A);

    std::cout << "Decimal to Binary(7 Bits): " << decimalToBin << std::endl;

    std::string binaryWithStopBit = pUtil.get()->stopBitEncoding(decimalToBin);

    std::cout << "Binary with Stop Bit(8 Bits): " << binaryWithStopBit << std::endl;

    std::string binaryToHex = pUtil.get()->conBinaryToHex(binaryWithStopBit);

    std::cout << "Binary to Hex: " << binaryToHex << std::endl;

    std::cout << " ------------------- " << std::endl;

    std::string asciiToHex = pUtil.get()->conAsciiToHex(exchange_data.B);

    std::cout << "ASCII to Hex: " << asciiToHex << std::endl;

    std::string hexToBinary = pUtil.get()->conHexToBinary(asciiToHex);

    std::cout << "Hex to Binary (7 Bits): " << hexToBinary << std::endl;

    std::string binaryWithStopBit2 = pUtil.get()->stopBitEncoding(hexToBinary);

    std::cout << "Binary with Stop Bit(8 Bits): " << binaryWithStopBit2 << std::endl;

    std::string binaryToHex2 = pUtil.get()->conBinaryToHex(binaryWithStopBit2);

    std::cout << "Binary to Hex: " << binaryToHex2 << std::endl;

    std::cout << " ------------------- " << std::endl;

    std::string decimalToBin2 = pUtil.get()->conDecToBinary(exchange_data.C);

    std::cout << "Decimal to Binary(7 Bits): " << decimalToBin2 << std::endl;

    std::string binaryWithStopBit3 = pUtil.get()->stopBitEncoding(decimalToBin2);

    std::cout << "Binary with Stop Bit(8 Bits): " << binaryWithStopBit3 << std::endl;

    std::string binaryToHex3 = pUtil.get()->conBinaryToHex(binaryWithStopBit3);

    std::cout << "Binary to Hex: " << binaryToHex3 << std::endl;


    std::cout << " ------------------- " << std::endl;

    std::cout << "Message: " << binaryToHex <<  " " << binaryToHex2 << " " << binaryToHex3 << std::endl;

    return 0;
}