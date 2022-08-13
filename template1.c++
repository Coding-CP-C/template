#include<bits/stdc++.h>
using namespace std;
//------------Sudip Mukherjee----------//
//-----------BE-CSE 21-25------------//
#define int long long
typedef vector<int> vi;
typedef stack<int>si;
#define pb push_back
#define FOR(x) for(int i=0;i<x;++i)
int mod = 998244353;
const int Highest=1e7+10;
const int maxi=1e9+7;
const int mini=-100000;

//---------------------gcd-----------------------------------//
int gcd(int a,int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

//------------------------Modulo Inverse-----------------------//

int inv(int i) 
{
    if (i == 1) return 1; 
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

//--------------------Mod Multiplication----------------------//

int mod_mul(int a, int b) {
    a = a % mod; 
    b = b % mod; 
    return (((a * b) % mod) + mod) % mod;
}

//-------------------Factorial-------------------------------//

int *fact;
void calFact() {
    fact = new int[Highest];
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<Highest; i++) fact[i] = mod_mul(fact[i-1], i);
}


//-----------------------------ncr--------------------------//

int ncr(int n, int r) {
    int ans = fact[n];
    ans = mod_mul(ans, inv(fact[n-r]));
    ans = mod_mul(ans, inv(fact[r]));
    return ans;
}
//--------------isPowerof2---------------------------------//
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

//---------------isKth Bit set----------------------------//
bool isKthBitSet(int n, int  k)
{
    if (n & (1 << (k - 1))) return true;
    return false;
}

//-------------------isPrime------------------------------//

bool isPrime(int n)
{  
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

//-------------------PrimeSieve--------------------------//




void primesieve()
{
    int sieve[Highest];   // Highest=1e7+10;
    sieve[0]=false;
    sieve[1]=false;

    for(int i=2;i*i<=Highest;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=i*i;j<=Highest;j+=i)
            {
                sieve[j]=false;
            }
        }
    }


  


}



//---------------SEARCH FUNCTION----------------------------//

bool searching(vector<int>&v,int x,int index)
{
    int n=v.size();
    int start=index+1;
    int end=n-1;

    

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(v[mid]<=x and v[mid]!=v[index])
        {
         return true;     
        }
        else if(v[mid]>x)
        {
           end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }


  return false;

}

//-------------FAST EXPONENTIATION (WITHOUT MOD)---------------------------//

int power(double x,int n)
{
   double ans=1;
   long long m=n;

   if(m<0)
   {
      m=(-1*m);
   }

   while(m>0)
   {
    if(m&1)
    {
        ans=ans*x;
    }
    x=x*x;
    m=m>>1;
   }

   if(n<0)
   {
    ans=(double(1)/ans);
   }
   

   return ans;

}


//--------------FAST EXPONENTIATION (WITH MOD)------------------//

 int power_with_mod(long long x,unsigned int y,int M)
 {
    int res=1;
    x=x%M;
    if(x==0)
    {
        return M;
    }

    while(y>0)
    {
        if(y&1)
        {
            res=(res*x)%M;
        }
        y=y>>1;
        x=(x*x)%M;
    }

   return res;

 }


//-----------------MAIN FUNCTION----------------------------------//
