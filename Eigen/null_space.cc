#include <iostream>

#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/SVD"

int main() {
  Eigen::MatrixXd matrix = Eigen::MatrixXd::Zero(4, 2);
  matrix << 1, 3, 1, 2, 1, -1, 2, 1;
  std::cout << "matrix: \n" << matrix << std::endl;
  Eigen::JacobiSVD<Eigen::MatrixXd> svd_helper(
      matrix, Eigen::ComputeFullU | Eigen::ComputeThinV);
  Eigen::MatrixXd U = svd_helper.matrixU();
  std::cout << "U: \n" << U << std::endl;
  Eigen::MatrixXd A = svd_helper.matrixU().rightCols(2);
  std::cout << "A: \n" << A << std::endl;
  std::cout << "A^T * matrix: \n" << A.transpose() * matrix << std::endl;
}