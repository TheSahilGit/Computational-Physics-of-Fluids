/* Code Calulates square root of a positive number using Egyptian Method
 * which is essentially Newton-Rapson method.  
 *
 *
 * Sahil (Jan 29, 2023)
 */

#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int i,j,n;
  double x,xo, a, root, err;
  double allowed_err;

  n = 100;
  a = 55;

  x = 10.0;

/*  
  for(i=1;i<=n;i++){
    x = (x*x + a)/(2*x);
  }
*/

  xo = (x*x + a)/(2*x);
  root = sqrt(a);
  err = abs(xo-root);
  i=1;
  allowed_err = 1.0e-4;
    

  while(err>allowed_err){
    x = (x*x + a)/(2*x);
    err = abs(root-x);
    ++i;
  }

  
  cout << "Sqrt"<<"(" << a<< ")= " <<  x << "\n";
  cout << "Sqrt"<<"(" << a<< ") [From math.h] = " << root << "\n" ;
  cout << "No of iteration taken " << i << "\n" ;


  return 0;

}
