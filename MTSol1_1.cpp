//MTSol1_1.cpp
#include<iostream>

void print_pyramid(int h)
{
  const char c='*', b=' ';    // characters to form the pyramid and blanks

  for(int i=1;i<=h;i++)
    {
      std::cout << '\n';
      for(int j=1;j<=h-i;j++)   // blanks to the left
        std::cout << b;
      for(int j=1;j<=i;j++)     // pyramid at level j
        std::cout << c << c;    // has 2j '*' characters
      std::cout << '\n';
    }
  std::cout << '\n';
}

int main()
{
  int height;

  std::cout << "How high would you like the pyramid?: ";
  while(true){
    std::cin >> height;
    if (height > 0 && height < 31)
      break;
    else
      std::cout << "Pick another height (must be between 1 and 30): ";
  }
  print_pyramid(height);
  system("PAUSE"); 
  return 0; 
}
