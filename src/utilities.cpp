#include "../inc/utilities.h"
#include <string>


/**
 * @brief Construct a new Utilities:: Utilities object
 * 
 */
Utilities::Utilities()
{
}


/**
 * @brief Destroy the Utilities:: Utilities object
 * 
 */
Utilities::~Utilities()
{
}


/**
 * @brief 7 bits parsing
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::parsing7Bits(std::string data)
{
    std::string parsed;
    std::string binary;

    for (unsigned i = data.length(); i != 0; --i)
    {
        parsed += data[i-1];

        if (parsed.size()%7 == 0)
        {
            parsed += " ";
            binary += parsed;
            parsed = "";
        }
    }

    binary += parsed;

    reverse(binary.begin(),binary.end());

    return binary;
}


/**
 * @brief Add stop bits
 * 
 * @param data 
 * @param last 
 * @return std::string 
 */
std::string Utilities::addStopBit(std::string data, bool last)
{
    std::string bin;

    if (data.length() == 7)
    {
        if (last == true)
        {
            bin = "1" + data;
        }
        else
        {
            bin = "0" + data; 
        }
    }
    else
    {
        for (unsigned i = data.length(); i < 8; i++)
        {
            bin += "0";
        }

        bin += data;
    }

    return bin;
}


/**
 * @brief Convert hex char to binary
 * 
 * @param c 
 * @return const char* 
 */
const char* Utilities::conHexCharToBinary(char c)
{
    switch (std::toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    
    return "";
}


/**
 * @brief Convert binary to hex char
 * 
 * @param data 
 * @return const char* 
 */
const char* Utilities::conBinaryToHexChar(std::string data)
{
    if (data == "0000") return "0";
    if (data == "0001") return "1";
    if (data == "0010") return "2";
    if (data == "0011") return "3";
    if (data == "0100") return "4";
    if (data == "0101") return "5";
    if (data == "0110") return "6";
    if (data == "0111") return "7";
    if (data == "1000") return "8";
    if (data == "1001") return "9";
    if (data == "1010") return "A";
    if (data == "1011") return "B";
    if (data == "1100") return "C";
    if (data == "1101") return "D";
    if (data == "1110") return "E";
    if (data == "1111") return "F";

    return "";
}


/**
 * @brief Convert ascii to hex
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::conAsciiToHex(std::string data)
{
    std::ostringstream result;

    result << std::setw(2) << std::setfill('0') << std::hex << std::uppercase;

    std::copy(data.begin(), data.end(), std::ostream_iterator<unsigned int>(result));

    // std::cout << data << ":" << result.str() << std::endl;

    return result.str();
}


/**
 * @brief Convert decimal to binary
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::conDecToBinary(uint64_t data)
{
    std::string binary;

    while (data > 0)
    {
        binary += std::to_string(data%2);
        data = data/2;
    }

    reverse(binary.begin(),binary.end());

    return parsing7Bits(binary);
}


/**
 * @brief Convert hex to binary
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::conHexToBinary(std::string data)
{
    std::string bin;

    for (unsigned i = 0; i != data.length(); ++i)
    {
        bin += conHexCharToBinary(data[i]);
    }

    return parsing7Bits(bin);
}


/**
 * @brief Convert binary to hex
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::conBinaryToHex(std::string data)
{
    std::string hex;
    std::string bin;
    std::string word;

    for (auto x : data) 
    {
        if (x == ' ')
        {
            for (unsigned i = 0; i != word.length(); ++i)
            {
                bin += word[i];

                if (bin.size()%4 == 0)
                {
                    hex += conBinaryToHexChar(bin);
                    bin = "";
                }
            }

            hex += " ";

            word = "";
        }
        else 
        {
            word = word + x;
        }
    }

    for (unsigned i = 0; i != word.length(); ++i)
    {
        bin += word[i];

        if (bin.size()%4 == 0)
        {
            hex += conBinaryToHexChar(bin);
            bin = "";
        }
    }

    return hex;
}


/**
 * @brief Stop bit encoding
 * 
 * @param data 
 * @return std::string 
 */
std::string Utilities::stopBitEncoding(std::string data)
{
    std::string bin;
    std::string word;

    for (auto x : data) 
    {
        if (x == ' ')
        {
            bin += addStopBit(word, false) + " ";
            word = "";
        }
        else 
        {
            word = word + x;
        }
    }

    bin += addStopBit(word, true);

    return bin;
}
