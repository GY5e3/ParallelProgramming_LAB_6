#include <iostream>
#include <string>
#include <vector>
#include <omp.h>

#include "solutionWithLocks.h"
#include "solutionWithReduction.h"
#include "solutionWithBarrier.h"

const int N = 10000000;
std::vector<int> A;
std::vector<int> B;
int main()
{
    setlocale(LC_ALL, "");
    
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        A.push_back(rand() % 100);
        B.push_back(rand() % 100);
       // std::cout << std::to_string(A[A.size() - 1]) + " " + std::to_string(B[B.size() - 1]) << std::endl;
    }
  // withReduction(N, A, B);
   // withLocks(N, A, B);
    withBarrier(N, A, B);

    //����� ���������� � �������������� ������: 6.05-6.3
    //����� ���������� � �������������� �������: 3.7-3.8
   // ����� ���������� � �������������� ��������: 3.6 - 3.8
 
}


