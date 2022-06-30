#include "headers/etl.h"
#include <iostream>
#include <vector>

#include <eigen3/Eigen/Dense>

int main(int argc, char *argv[])
{
    ETL etl(argv[1], argv[2], argv[3]);//filename, delimiter, headers?

    std::vector<std::vector< std::string>> dataset = etl.ReadCSV();

    int rows= dataset.size();
    int cols= dataset[0].size();
    
    Eigen::MatrixXd datamat= etl.CSVtoEigen(dataset, rows, cols);
    std::cout << datamat<< std::endl;

    return 0;

}