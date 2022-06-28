#include "headers/etl.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    ETL etl(argv[0], argv[1], argv[2]);//filename, delimiter, headers?

    std::vector<std::vector< std::string>> data_string;
    data_string = etl.ReadCSV();

    data_string;
    return 0;

}