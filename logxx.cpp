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

//Declaration of function. 

float f(float x);
float logox(float x, int n);

// Main Code

int main(){
    int i,j;
    float ff, h, a, b, n;
    float midsum;
    float tlog;

    a = 0;
    b = 0.5;
    n = 100;

    h = (b-a)/n;


    midsum = 0;
    for(i=1;i<n;i++){
        midsum = midsum + f(a+h*i);
    }


    ff = 0.5 * h * (f(a) + f(b) + 2 * midsum);

    tlog = logox(b,n);

//Printing
    
    cout << "Trapezoid approx: " << ff << "\n";
    cout << "Taylor approx: " << tlog << "\n" ;

    return 0;
}

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
    ss = ss + pow(-1,i+1)*pow(x,i)/i;
  }

  return ss;



}



