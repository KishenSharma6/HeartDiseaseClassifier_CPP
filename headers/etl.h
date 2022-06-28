//Class declaration goes into header files

#ifndef ETL_H
#define ETL_H

#include <iostream>
#include <vector>

class ETL
{
    std::string filename;
    std::string delimiter;
    bool containsHeader;

public:

    ETL(std::string name, std::string seperator, bool header);
    std::vector< std::vector<std::string>> ReadCSV();

};



#endif