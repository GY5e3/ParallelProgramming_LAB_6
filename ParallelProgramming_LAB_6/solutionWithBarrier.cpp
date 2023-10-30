#include "solutionWithBarrier.h"

void withBarrier(const int N, std::vector<int> A, std::vector<int> B)
{
    int i;
    int localMax;
    int total = 0;
    omp_set_num_threads(3);
    #pragma omp parallel shared(A, B) 
    {

        #pragma omp for private(i, localMax) reduction(+:total) nowait
        for (i = 0; i < N; i++)
        {
            localMax = std::max(A[i] + B[i], 4 * A[i] - B[i]);

         //   std::cout << "Iteration number " + std::to_string(i) + " " + std::to_string(A[i] + B[i]) + " " + std::to_string(4 * A[i] - B[i]) + "\n";
            
            if (localMax > 1)
            {
                total = total + localMax;
            }
           
        }
        #pragma omp barrier
        /*std::cout << "Поток " + std::to_string(omp_get_thread_num()) + "достиг точки синхронизации\n";
       #pragma omp barrier
        std::cout << "Поток " + std::to_string(omp_get_thread_num()) + "достиг точки синхронизации\n";
#pragma omp barrier
        std::cout << "Поток " + std::to_string(omp_get_thread_num()) + "достиг точки синхронизации\n";
#pragma omp barrier
        std::cout << "Поток " + std::to_string(omp_get_thread_num()) + "достиг точки синхронизации\n";*/
    }



    std::cout << total << std::endl;
    std::cout << "runtime = " << clock() / 1000.0 << std::endl;
}
