#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "gradiente_coniugato.cpp"

// su modello test professor Vicini

double condA(const Eigen::MatrixXd& A)
{
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    Eigen::VectorXd singularValuesA = svd.singularValues();
    return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main() 
{
    const double tol = 1.0e-15;
    unsigned int n = 20; 

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (abs(B.determinant()) < tol)
        return -1;

    // A simmetrica e definita positiva (richiesto da gradiente coniugato)
    Eigen::MatrixXd A = B.transpose() * B;
    
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    const double res_tol = 1.0e-12;
    const unsigned int it_max = 10000;

    std::cout.precision(2);
    std::cout << std::scientific << "Matrix Cond: " << condA(A) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Eigen::VectorXd x = gradiente_coniugato(A, b, x0, res_tol, it_max);

    const auto err_rel = (x - x_ex).norm()/x_ex.norm();

    std::cout.precision(4);
    std::cout << std::scientific << "\nerr_rel (Errore Relativo):" << std::endl;
    std::cout << std::scientific << err_rel << std::endl;
    
    std::cout << std::scientific << "\nSoluzione calcolata x:" << std::endl;
    std::cout << std::scientific << x << std::endl;

    std::cout << std::scientific << "\nSoluzione esatta x_ex:" << std::endl;
    std::cout << std::scientific << x_ex << std::endl;

    return 0;
}