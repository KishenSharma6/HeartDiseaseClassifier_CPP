//Implementation goes into cpp files
#include "../headers/etl.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <eigen3/Eigen/Dense>



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
        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
        result.push_back(vec);
    }
    file.close();
    
    
    return result;
}

Eigen::MatrixXd ETL::CSVtoEigen(std::vector<std::vector<std::string>> dataset, int rows, int cols)
{
    Eigen::MatrixXd datamat(rows, cols);

    if (containsHeader == true)
    {
        rows =rows -1;
    }
    for (int i=0;i<rows ;i++)
    {
        for (int j =0; j <cols; j ++)
        {
            datamat(i, j)= atof(dataset[i][j].c_str());
        }
    }
    return datamat;
}