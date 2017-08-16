//MTSol1_2.cpp
#include<iostream>
#include<cstdlib>
int main()
{
  int n;

  std::cout << "Enter the maximum for my secret number: ";
  while(true)
    {
      std::cin >> n;
      if(n<1)
        std::cout << "A positive integer, please! ";
      else
        break;
    }

  srand((unsigned)time(0));   // initialise random number generator

  int secret=rand() % n + 1;  // choose the secret number in 1,...,n
  std::cout << "I have chosen my secret number!\n";

  int tries = 0;
  int guess = 0;

  while(guess!=secret)
    {
      tries++;
      std::cout << "Can you guess what my secret number is? (Try ";
      std::cout << tries << ") ";
      std::cin >> guess;
      if(guess>secret)	
        std::cout << "Your guess is larger than my secret number!\n";
      else if (guess < secret)
        std::cout << "Your guess is smaller than my secret number!\n";
    }

  std::cout << "Congratulations! You found it in ";
  std::cout << tries << " guesses!\n";
  system("PAUSE"); 
  return 0; 
}
