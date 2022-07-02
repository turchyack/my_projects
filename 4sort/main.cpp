#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>


using namespace std;



int main(){


int N = 5;
cout << "пчёлка" << endl;

string S = "4sort/CreateFiles/";
string D =  ".txt";
srand(time(NULL));

cout << D << endl;

/*  for(int i = 0; i < N; ++i){

    string H = to_string(i+1);
    string G = S + H + D;

    cout << "Файл" << H <<  " создан " << G << endl;


    ofstream oFile (G);


  }
*/
 for(int i = 0; i < N; ++i){

    string H = to_string(rand());
    string Z = S + H + D;
    //  cout << "Файл" << H <<  " создан " << G << endl;


   // ofstream oFile (G);
    ofstream oFile (Z);


  }


}

