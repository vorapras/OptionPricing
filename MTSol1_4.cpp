//MTSol1_4.cpp
#include<iostream>
#include<cstdlib>

const int N=10; // dimension of our matrices

void fillmatrix(int A[N][N], int maxvalue) // fill the matrix with
                                           // random runbers in 1,...,maxvalue
{
  for(int i=0; i < N; i++)
    for(int j=0; j < N; j++)
      A[i][j] = rand() % maxvalue + 1;  // random value in 1,...,maxvalue
}

void printmatrix(int A[N][N])
{
  for(int i=0; i<N; i++)
    {
      std::cout << '\n';
      for(int j=0; j<N; j++)
        std::cout << A[i][j] << " ";
    }
  std::cout << '\n';
}

void multiplymatrix(int A[N][N], int B[N][N], int C[N][N])
{
  for(int i=0; i < N; i++)
    for(int j=0; j < N; j++)
      {
        int sum = 0;       //auxiliary variable to compute inner product
        for(int k=0; k < N; k++)
          sum += A[i][k] * B[k][j];
        C[i][j]=sum;
      }
}


int main()
{
  const int maxentry=9;
  //void srand ( unsigned int seed );
  srand((unsigned)time(0));     // initilaising the random number generator


  int S[N][N];
  int T[N][N];
  int U[N][N];

  fillmatrix(S,maxentry);
  fillmatrix(T,maxentry);

  multiplymatrix(S,T,U);

  printmatrix(S);
  std::cout << "\ntimes\n";
  printmatrix(T);
  std::cout <<"\nis\n";
  printmatrix(U);
  
  system("PAUSE");
  return 0; 
}
