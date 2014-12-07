// 'Hello World!' program 
 
#include <iostream>
 
#include <cmath>


 long   double mat  [1001][1001][2]; 
long long int problem343(long long int k/*,long   double*** mat*/) {
	 long long int xi;
	 long long int yi;
	long long int n = 0;
	long double x = 1;
	long double y = k;
	long  double t;
		 
 	while (y > 0 && x <= k && n == 0) {
		t = x / y;
		if (t - round(t) == 0.0) {

			n = t;
		}
		
		xi=static_cast<long long int>(x);
		yi=static_cast<long long int>(y);
		/*if(( mat[xi][yi][0]==0.0)&&( mat[xi][yi][1]==0.0)){*/
		if ((x!=1)&&((y / x) - round((y / x)) == 0.0)) {
			y = y / x;
			x = 1;
		} else {
			x++;
			y--;
		}
	/*	mat[xi][yi][0]=x;
		mat[xi][yi][1]=y;
		}
		else{
		
	x=mat[xi][yi][0];
		y=mat[xi][yi][1];
		}*/
		
   //std::cout << "t"<<t<< "x"<<x<< "y"<<y<< "n"<<n << std::endl;
		//alert("t"+t+"n"+n+"x"+x+"y"+y);
	}
 
	return n; 
}

int main()
{

long long int somma=0;
long long int partial=0;
long long int somma1=0;
long long int partial1=0;
 long long  int  max= (pow(10.0,6.0))*2;
 max=130;
 /*
for (long long  i = 0; i <= max; i++)
for (long long  j = 0; j <= max; j++){
  
  mat[i][j][0]=0.0;
  mat[i][j][1]=0.0;
  
 // std::cout << "i"<<i<< "j"<<j<< std::endl;
}*/




/*
mat=new long   double**[max];
for(long long int i=0;i<max;i++) mat[i]=new long   double*[max];
for (long long  i = 0; i < max; i++)
for (long long  j = 0; j < max; j++){
 
  mat[i][j]=new long   double[2];
  mat[i][j][0]=0.0;
  mat[i][j][1]=0.0;
  
}
*/
for (long k=1;k<=max;k++){
partial1=problem343(pow(k,3));
partial=problem343(k);
somma1=somma1+partial1;
somma=somma+partial;

  //std::cout << "partial"<<partial<<"\t\tk"<<k <<"\t\tsomma"<<somma <<"\t\t pow(k,3)"<< pow(k,3)<<"\t\t A "<< partial/3<<std::endl;
  std::cout << "partial"<<partial<< "-"<<partial1<<"\tk"<<k <<"\tpow(k,3)"<< pow(k,3)<<"\t somma"<<somma <<"-"<<somma1  <<std::endl;
  //std::cout  <<"\t\t somma/pow(k,3)"<< somma/pow(k,3)<<std::endl;
   

}  
 
  std::cout << "somma"<<somma << std::endl;
  return 0;
}
  


/*



For any positive integer k, a finite sequence ai of fractions xi/yi is defined by:
a1 = 1/k and
ai = (xi-1+1)/(yi-1-1) reduced to lowest terms for i>1.
When ai reaches some integer n, the sequence stops. (That is, when yi=1.)
Define f(k) = n.
For example, for k = 20:

1/20 ? 2/19 ? 3/18 = 1/6 ? 2/5 ? 3/4 ? 4/3 ? 5/2 ? 6/1 = 6

So f(20) = 6.

Also f(1) = 1, f(2) = 2, f(3) = 1 and Sf(k3) = 118937 for 1 = k = 100.

Find Sf(k3) for 1 = k = 2×106.





343 - 269533451410884183
 */ 


