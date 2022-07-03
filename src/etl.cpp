//Implementation goes into cpp files
#include "../headers/etl.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>

#include <boost/algorithm/string.hpp>
#include <eigen3/Eigen/Dense>



ETL::ETL(std::string name, std::string seperator)
{
    filename= name;
    delimiter= seperator;
    
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

    for (int i=0;i<rows ;i++)
    {
        for (int j =0; j <cols; j ++)
        {
            datamat(i, j)= atof(dataset[i][j].c_str());
        }
    }
    return datamat;
}

std::tuple< Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > ETL::TrainTestSplit(Eigen::MatrixXd data, float split)
{
    int rows= data.rows();
    int cols= data.cols();
    int train_rows= round(rows * split);
    int test_rows= rows - train_rows;

    // Subset our training data
    Eigen::MatrixXd train(data.topRows(train_rows));

    Eigen::MatrixXd X_train = train.leftCols(cols - 1);
    Eigen::MatrixXd y_train = train.rightCols(1);
    
    //Subset our test data
    Eigen::MatrixXd test(data.bottomRows(test_rows));

    Eigen::MatrixXd X_test = test.leftCols(cols - 1);
    Eigen::MatrixXd y_test = test.rightCols(1);

    return std::make_tuple(X_train, y_train, X_test, y_test);

}