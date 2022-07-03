//Class declaration goes into header files

#ifndef ETL_H
#define ETL_H

#include <iostream>
#include <vector>

#include <eigen3/Eigen/Dense>


class ETL
{
    std::string filename;
    std::string delimiter;
    

public:

    ETL(std::string name, std::string seperator);
    std::vector< std::vector<std::string>> ReadCSV();
    Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> dataset, int rows, int cols);
    std::tuple< Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > TrainTestSplit(Eigen::MatrixXd data, float split);


};



#endif