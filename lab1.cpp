#include <iostream>
#include <fstream>

#define OK 100

using namespace std;

void kiir(int*);
void backtrek(int *);
int backtrek_keres(int*,int);
int backtrek_mvrforw(int*,int);
int *h, n = 0;
ofstream file;

int main()
{
    
    cout << "Adja meg a tabla meretet: ";
    cin >> n;
    h= new int[n+1];
    int *tomb = new int[n];
    
    for(int i=0; i<=n;++i)
    {
        h[i]=1;
    }   
    backtrek(tomb);
    fflush(stdin);
    system("pause");
	return 0;
}

void kiir(int *tomb)
{ 

    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        { 
                if (tomb[i] == j+1)
                file << "1";
                else
                file << "*";
        }
        file << endl;
    }
file << endl;
}

void backtrek(int *tomb)
{
    int s=0;
    file.open("ki.txt");
	while(1)
	{
		cout << endl << "1:  backtarcking" << endl;
		cout << "2: backtarcking + MVR + Forward checking" << endl;
		cout << "3: kilepes "<<endl;
		cout << endl << "Kerem a kivant modszert:";
		cin >> s;
		switch(s)
		{
			case 1:
				backtrek_keres(tomb,0);
				break;
			case 2:
				backtrek_mvrforw(tomb,0);
				break;
			case 3:
				break;
		}
		if(s == 3)
			break;
	}
		cout << "Backtreking vege";
		file.close();
}

int backtrek_keres(int *tomb, int poz)
{
  

    if ( poz == n)
    {
        kiir(tomb);
        return OK;
    }

    
    for(int ert=1; ert<=n; ++ert)
    {
        tomb[poz]=ert;
        int res=0;
        if (poz==0)
        {
            res= backtrek_keres(tomb,poz+1);
        }
        else
        {
            bool chck=true;
            for (int i=0;i<poz;++i)
            {
                if (tomb[i]==tomb[poz])
                {
                    chck=false;
                    break;
                }
                if (abs(tomb[poz]-tomb[i])==poz-i )
                {
                    chck=false;
                    break;
                }
            }
            if (chck==true) 
            { 
                res = backtrek_keres(tomb,poz+1); 
            } 
        }
    
        if (res == OK)
        return OK;
    }

        tomb[poz]=-1;
        return 0;
}

int backtrek_mvrforw(int *tomb, int poz)
{
    

    if ( poz == n)
    {
        kiir(tomb);
        return OK;
    }

    for(int ert=1; ert<=n; ++ert)
    {
        if(h[(ert+poz+1)%n]==1)
        {
            h[ert]=0;
            tomb[poz]=(ert+poz+1)%n;
            
            int res=0;
            if (poz==0)
            {
                res = backtrek_mvrforw(tomb,poz+1);
            }
            else
            {
                bool chck=true;
                for (int i=0;i<poz;++i)
                {
                    if (tomb[i]==tomb[poz])
                    {
                        chck=false;
                        break;
                    }
                    if (abs(tomb[poz]-tomb[i])==poz-i )
                    {
                        chck=false;
                        break;
                    }
                } 
                if (chck==true) 
                { 
                    res = backtrek_mvrforw(tomb,poz+1); 
                } 
                }
               
            if (res == OK)
            {
                return OK;
            }
            h[ert]=1;
            
        }
    }
 
    tomb[poz]=-1;
    return 0;
}