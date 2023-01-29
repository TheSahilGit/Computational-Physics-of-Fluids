/* Code calculates square root of number using Bakshali Method.
 * Which looks like higher order approximation of Newton-Rapson , but I'm not sure
 * need to check. 
 * 
 *
 * Sahil (Jan 29, 2023)
 *
 */

#include<iostream>
#include<cmath>

using namespace std;



int main(){
  int i,j,n;
  double x, q, xoi, a;
  double err, all_err, root;

  a = 14.0;
  root = sqrt(a);
  
  x = 10.0;


  q = (a-x*x)/(2*x);
  x = x +  q - q*q / (2*(q+x)) ;

  err = abs(x - root);
  all_err = 1.0e-4;
  i = 1; 

  while(err>all_err){
    q = (a-x*x)/(2*x);
    x +=  q - q*q / (2*(q+x));
    err = abs(x-root);
    ++i;
  }

/*
  for(i=1;i<=n;i++){
  q = (a-x*x)/(2*x);
  x += q - q*q / (2*(q+x)) ;
  }
*/


  cout << "Calculated sqrt(" << a << ") is: " << x << "\n"; 
  cout << "sqrt(" << a << ") [From cmath] is: " << root << "\n";
  cout << "No. of iterations taken: " << i << "\n" ;






}
