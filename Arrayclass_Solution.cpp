//Arrayclass_Solution.cpp
//Solution to Worksheet 2
#include<iostream>
#include<cstdlib>  //for EXIT_SUCCESS and EXIT_FAILURE

using std::cout;

class array{
public:
  array(int size);  // constructor
  ~array();         // destructor
  array(const array& a); //copy constructor

  int get_size(void);
  double &element(int i);
  double &operator[](int i);
  static int number_of_arrays(void);
private:
  int elements;
  static int total;
  double *pt;
};

int array::total = 0;


array::array(int size)
{
 elements=size;
 pt = new double[elements];
 ++total;
}

array::array(const array& a)
{
 elements=a.elements;
 pt = new double[elements];
 ++total;
 for(int i=0; i < elements; i++)
 {
         pt[i]=a.pt[i];
 }
}

array::~array()
{
 delete [] pt;
 --total;
}

int array::get_size(void)
{
 return elements;
}

double &array::element(int i)
{
 if ((i < 1)||(i>elements))
 {
  cout << "Index of array" << i <<" out of bounds! \n";
  exit(EXIT_FAILURE);
 }
 return pt[i-1];
}

double &array::operator[](int i)
{
 if ((i < 1)||(i>elements))
    {
    cout << "Index of array" << i <<" out of bounds! \n";
    exit(EXIT_FAILURE);
    }
 return pt[i-1];

}

int array::number_of_arrays(void)
{
    return total;
}


int main(){

    srand((unsigned)time(0));   // initialise random number generator

    cout << "There are currently " << array::number_of_arrays() <<  " arrays. \n";
    array testarray(100); //create object testarray of type array
    cout << "There are currently " << array::number_of_arrays() <<  " arrays. \n";

    cout << "The array of length " << testarray.get_size() << " contains the following numbers: \n";
    for(int i=1; i<=100;i++){
      testarray.element(i)=rand();
      cout << testarray.element(i) <<" ";
    }
 cout << "\n";

 array A(3);
 cout << "There are currently " << array::number_of_arrays() <<  " arrays. \n";
 A.element(1)=1.0;
 A.element(2)=2.0;
 A.element(3)=3.0;

 array B(A);
 cout << "There are currently " << array::number_of_arrays() <<  " arrays. \n";
 cout << "B.element(2)=" << B.element(2) << "\n";
 B[3]=7.0;
 cout << "B[3]=" << B[3] << "\n";

 system("PAUSE");
 return (EXIT_SUCCESS);
}
