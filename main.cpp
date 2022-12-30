#include <iostream>  
#include <string>         
#include <conio.h>        	  
#include "classes.h"                 
#include <Windows.h>    
#include<ctime>          
using namespace std;   
   
int main()     
{  
   system("color 0C");       
   system("title EMSI SYSTEM");      
   MaximizeOutputWindow();        
   FontSize(25);                    
   fontsize(25,25);       
   rect(114,21,7,10);           
   login *log = new login; 
   BankTitle(31,2);   
   log->log();          
   getch();
   return 0;
}





