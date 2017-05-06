#include "Cpu_player.h"
#include "Human_player.h"

int main()
{
    string input;
    
    while(1){
     
     cout<<"****************************************************************"<<endl;
     cout<<endl;
     cout<<"                    CONNECT FOUR PROGRAM"<<endl;
     cout<<"Options:"<<endl;
     cout<<endl;
     cout<<"1) Play against a friend(Human vs Human)"<<endl;
     cout<<"2) Play against a computer(Human vs CPU)"<<endl;
     cout<<"3) Credits"<<endl;
     cout<<"4) Exit"<<endl;
     cout<<endl;
     cout<<"****************************************************************"<<endl;
     
     cin>>input;
     
     //Human vs human
     if(input=="1")
     {
        Human_player human;
        human.set_player_name(1);
        human.play();
     }
     
     //Human vs computer
     else if(input=="2")
     {
         Cpu_player comp;
         comp.set_player_name(2);
         comp.play();
     }
     
     //Shows credit
     else if(input=="3")
     {
         cout<<"Programmer: Hussain Dar"<<endl;
         cout<<"Graphics designer: Hussain Dar"<<endl;
         cout<<"Algorithm designer: Hussain Dar"<<endl;
         cout<<"Reference used: None"<<endl;
         cout<<"Total hours approximatly spent on the project: 33 hours"<<endl;
         cout<<"All copyrights are reserved since June 28th,2015"<<endl;
     }
        
    //Ends program
     else if(input=="4")
        break;

     //Displays the options again and then ask you to input a valid option otherwise the loop will continue
     else
        cout<<"Invalid input please try again"<<endl;
    }
}