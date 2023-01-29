/* Code calcualates approximate values of log(1+x) via
 * two methids. One is from integral form using Trapezoidal rule, 
 * another is from taylor series expansion.
 *
 * Caution: My kinda first cpp code ever, May be not the best way of writing stuff. 
 * 
 * Sahil ( Jan 29, 2023) 
 *
 */


#include<iostream>
#include<cmath>

using namespace std;


// ************************
// Functions 
// ************************


//Function for the Trapezoidal rule

float f(float x){
    float fx;
    fx = 1/(1+x);
   // fx = x*x ;
    return fx; 
}



// Taylor expansion of log(1+x)
float logox(float x, int n){
  float ss;
  int i;

  ss = 0;


  for(i=1;i<=n;i++){
    //ss = ss + pow((-1),i+1) * pow(x,i) / i ;
    ss +=  pow((-1),i+1) * pow(x,i) / i ;
    //ss = ss +  ((-1)^(i+1)) * (x^i) / i;
  }

  return ss;

}

// *********************************************************
// Main Code
// *********************************************************
//
int main(){
    int i,j;
    float ff, h, a, b,r, n;
    float midsum;
    float tlog;
    float td, logtwo;
    float fss;


    r = 8;


// Trapezoidal happening. 
// **********************************************************
    
    a = 0;
    b = r/100.0;
    n = 100;

    h = (b-a)/n;


    midsum = 0;
    for(i=1;i<n;i++){
        midsum = midsum + f(a+h*i);
    }


    ff = 0.5 * h * (f(a) + f(b) + 2 * midsum);

// *********************************************************

    if(b>1){
      cout << "Taylor series doesn't converge for x>1 \n";
    }
    else{
      tlog = logox(b,n);
      cout << "Taylor approx: " << tlog << "\n" ;
    }

// *********************************************************
// Rule of 72 
// *********************************************************
// Here we assume b% interest. That means time taken would be
// T = b*log(2)/log(1+b/100); This should reach 72. 
// *******************************************************
    
    td = r*log(2)/ff;
    


//Printing
    
    cout << "Trapezoid approx: " << ff << "\n";
    cout << "log(1+" << b << ") from math.h : " << log(1+b) << "\n"; 
    cout << "Time taken for the amount to be double: " << td << "\n";

    return 0;
}



