//
//  main.cpp
//  StochasticProcess


#include <cmath>
#include <iostream>
#include <algorithm> //For function max
#include <fstream> //For writing results in file

#include "StochProc.h"

using namespace std;

int main()
{
    cout << "Welcome to the Sample Path Generation session! \n";
    // Set the seed of the random number generator using time
    //void srand ( unsigned int seed );
    srand((unsigned)time(0));
    //cout << "time(0)=" << time(0) <<"\n";
    //srand(1.0);  //Could also use such a seed. This is useful if you would like to reproduce you results;
    
    BM mybrownian;
    GBM mygeombrownian;
    double timehorizon=1.0;
    double initialX=100.0;
    int stepnum=10;
    double Y1, Y2;
    
    Y1 = mybrownian.get_terminalvalue(timehorizon, stepnum, initialX);
    cout << "Terminal value of Brownian Motion is " << Y1 << "\n";
    
    Y2 = mygeombrownian.get_terminalvalue(timehorizon,stepnum,initialX);
    cout << "Terminal value of Geometric Brownian Motion is " << Y2 << "\n";
    
    double *path1,*path2;
    path1 = new double[stepnum+1];
    path2 = new double[stepnum+1];
    
    mybrownian.get_samplepath(timehorizon,stepnum,initialX,path1);
    mybrownian.get_samplepath(timehorizon,stepnum,initialX,path2);
    
    cout << "Path of Brownian motion: \n";
    for(int i=0;i < stepnum+1;i++)
    {
        cout<<path1[i]<< "\n ";
    }
    
    cout << "Path of Geometric Brownian motion: \n";
    for(int i=0;i < stepnum+1;i++)
    {
        cout<<path2[i]<< "\n ";
    }
    
    //Very simple method of writing data into a file.
    //You could do some more checks here.
    //Currently you would just overwrite the file "Samplepathfile.txt".
    
    ofstream myfile1;
    myfile1.open("Samplepathfile.txt");
    for (int i=0; i<stepnum+1; i++)
    {
        myfile1 << path2[i] << "\n";
    }
    myfile1 << "\n";
    myfile1.close();
    
    system("PAUSE");
    
    return 0;
    
}
