#include <eigen3/Eigen/Cholesky>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
  Eigen::Matrix4d A = Eigen::Matrix4d::Identity();
  A(2, 2) = 0.5;
  A(3, 3) = 1e-10;
  std::cout << "A \n" << A << std::endl;
  std::cout << "A inv \n" << A.inverse() << std::endl;
  Eigen::Matrix4d L = A.llt().matrixL();
  std::cout << "L \n" << L << std::endl;
  std::cout << "L inv \n" << L.inverse() << std::endl;
}
