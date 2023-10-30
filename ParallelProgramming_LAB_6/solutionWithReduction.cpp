#include "solutionWithReduction.h"

void withReduction(const int N, std::vector<int> A, std::vector<int> B)
{
    int i;
    int localMax;
    int total = 0;
    #pragma omp parallel shared(A, B) 
    {

        #pragma omp for private(i, localMax) reduction(+:total) 
        for (i = 0; i < N; i++)
        {
            localMax = std::max(A[i] + B[i], 4 * A[i] - B[i]);
            //std::cout << "Iteration number " + std::to_string(i) + " " + std::to_string(A[i] + B[i]) + " " + std::to_string(4 * A[i] - B[i]) + "\n";
            if (localMax > 1)
            {
                total = total + localMax;
            }

        }
    }



    std::cout << total << std::endl;
    std::cout << "runtime = " << clock() / 1000.0 << std::endl;
}
