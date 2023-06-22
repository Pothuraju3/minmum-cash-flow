#include <bits/stdc++.h> 

using namespace std;

int minCashFlow(vector<vector<int>>& money, int n)
{
   int exc[n] = {0};

   for(int ii = 0; ii < n; ii++)
   {
      for(int jj = 0; jj < n; jj++)
      {
         exc[ii] += money[jj][ii]-money[ii][jj];
      }
   }

   int amount = 0;

   priority_queue<int> p,q;

   for(int ii = 0; ii <n; ii++)
   {
      if(exc[ii] > 0)
      {
         p.push(exc[ii]);
      }
      else if(exc[ii] < 0)
      {
         q.push((-1)*exc[ii]);
      }
   }

   int x,y;

   while(!p.empty())
   {
      x = p.top();
      p.pop();
      y = q.top();
      q.pop();

      amount += min(x,y);

      if(x > y)
      {
         p.push(x-y);
      }
      else if(y > x)
      {
         q.push(y-x);
      }
   }

   return amount;
}


int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> v(n,vector<int>(n,0));
    
    int payments;
    cin >> payments;
    
    int sen,rec,amount;
    
    for(int ii = 0; ii < payments; ii++)
    {
        cin >> sen >> rec >> amount;
        v[sen][rec] += amount;
    }
    
    cout << minCashFlow(v,n) << endl;
    
    
    return 0;
}
