//Implementation goes into cpp files
#include "../headers/etl.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>


ETL::ETL(std::string name, std::string seperator, bool header)
{
    filename= name;
    delimiter= seperator;
    containsHeader= header;
    
}

std::vector< std::vector<std::string>> ETL::ReadCSV()
{
    
    std::vector< std::vector<std::string>> result;

    //open source file
    std::ifstream file(filename);

    std::string line= "";

    while (getline(file, line))
    {
        std::vector<std::string> vec;
        result.push_back(row);
    }
    
    return result;
}