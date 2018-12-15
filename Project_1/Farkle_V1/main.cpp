
/* 
 * File:   main.cpp
 * Author: Noel Verduzco
 * Created on November 1, 2018, 6:59 PM
 * Purpose: Farkle Game
 */

//System Libraries
#include <iostream> //I/O Library -> cout, endl
#include <ctime>    //Time library
#include <cstdlib>  //Random Number
#include <fstream>  //Input/Output to files
#include <string>   //String library

using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array C

//Function Prototypes

//Execution begins Here!
int main(int argc, char** argv) {
    //Set the random number seed 
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float scre1,scre2;                      //The scores for player 1 and 2
    int ini1,ini2,                          //Initial roll to see who goes 1st
        t1,t2,t3,t4,t5,t6,                  //Each time the dice is thrown
        w1,los1,w2,los2,                    //Win and loss for player 1 and 2
        games,                              //Number of user inputted games
        fark1,fark2,                        //Farkle Counter for player 1 and 2
        ones,twos,threes,fours,fives,sixes, //Counter for the dice rolls
        choice;                             //Choice for the menu
    char dec;                               //Decision for cashing in points
    bool run;                               //Test to continue running the game
    string name1,name2,                     //Input for player names
           plyr1,plyr2;                     //Determines which player goes 1st
    
    
    //Initialize player
    
            //Inputting Player's Name
    cout<<"Enter player 1's name"<<endl;
    getline(cin,name1);
    cout<<"====================="<<endl;
    cout<<"Enter player 2's name"<<endl;
    getline(cin,name2);
    
    //Game menu
    do{
        cout<<"This program can play the dice game Farkle."<<endl;
        cout<<"Press 1 to play or 0 to exit"<<endl;
        cin>>choice;
        
        //Input Validation
        if(choice!=1&&choice!=0){
            cout<<"Invalid input, please select either 1 or 0."<<endl;
        }
    }while(choice!=1&&choice!=0);
    if(choice==0){
        cout<<"Exiting program..."<<endl;
        return 0;
    }
    
    //Do while loop for determining which player goes first
    cout<<"Both players will now roll the dice"
            " to determine who will go first"<<endl;
    do{
        cout<<name1<< " , press 1 to roll the dice"<<endl;
        cin>>ini1;//Placeholder variable until roll
        ini1=rand()%6+1;
        cout<<"You rolled a "<<ini1<<endl;
        cout<<"=============================="<<endl;
        
        cout<<name2<<" , press 1 to roll the dice"<<endl;
        cin>>ini2;//Placeholder variable until roll
        ini2=rand()%6+1;
        cout<<"You rolled a "<<ini2<<endl;
        
        if(ini1==ini2){
            cout<<"========================================="<<endl;
            cout<<"You both got the same number, roll again."<<endl;
            cout<<"========================================="<<endl;
        }
    }while(ini1==ini2);
    
    if(ini1>ini2){
        plyr1=name1;
        plyr2=name2;
    }else{
        plyr2=name2;
        plyr1=name1;
    }
    
    while(scre1<=10000&&scre2<=10000){
            cout<<"================================="<<endl;
            cout<<"It is "<<plyr1<<"'s turn!"<<endl;
            cout<<"Rolling dice..."<<endl;
            t1=rand()%6+1;
            t2=rand()%6+1;
            t3=rand()%6+1;
            t4=rand()%6+1;
            t5=rand()%6+1;
            t6=rand()%6+1;//The rolls
            cout<<plyr1<<"'s rolls are "<<t1<<        
                    " "<<t2<<
                    " "<<t3<<
                    " "<<t4<<
                    " "<<t5<<
                    " "<<t6<<endl;

            //Scoring Player 1

            ones=0;
            twos=0;
            threes=0;
            fours=0;
            fives=0;
            sixes=0;

            //Determining the value given for the 1st throw
            if(t1==1){
                ones+=1;
            }if(t1==2){
                twos+=1;
            }if(t1==3){
                threes+=1;
            }if(t1==4){
                fours+=1;
            }if(t1==5){
                fives+=1;
            }if(t1==6){
                sixes+=1;
            }

            //Determining the value given for the 2nd throw
            if(t2==1){
                ones+=1;
            }if(t2==2){
                twos+=1;
            }if(t2==3){
                threes+=1;
            }if(t2==4){
                fours+=1;
            }if(t2==5){
                fives+=1;
            }if(t2==6){
                sixes+=1;
            }

            //Determining the value given for the 3rd throw
            if(t3==1){
                ones+=1;
            }if(t3==2){
                twos+=1;
            }if(t3==3){
                threes+=1;
            }if(t3==4){
                fours+=1;
            }if(t3==5){
                fives+=1;
            }if(t3==6){
                sixes+=1;
            }

            //Determining the value given for the 4th throw
            if(t4==1){
                ones+=1;
            }if(t4==2){
                twos+=1;
            }if(t4==3){
                threes+=1;
            }if(t4==4){
                fours+=1;
            }if(t4==5){
                fives+=1;
            }if(t4==6){
                sixes+=1;
            }

            //Determining the value given for the 5th throw
            if(t5==1){
                ones+=1;
            }if(t5==2){
                twos+=1;
            }if(t5==3){
                threes+=1;
            }if(t5==4){
                fours+=1;
            }if(t5==5){
                fives+=1;
            }if(t5==6){
                sixes+=1;
            }

            //Determining the value given for the 6th throw
            if(t6==1){
                ones+=1;
            }if(t6==2){
                twos+=1;
            }if(t6==3){
                threes+=1;
            }if(t6==4){
                fours+=1;
            }if(t6==5){
                fives+=1;
            }if(t6==6){
                sixes+=1;
            }
            
            cout<<"Ones "<<"Twos "<<"Threes "
                    <<"Fours "<<"Fives "<<"Sixes "<<endl;
            
            cout<<" "<<ones<<"    "<<twos<<"     "<<threes<<"      "<<fours<<
                    "     "<<fives<<"     "<<sixes<<endl;
            
            //Player deciding how to score points
            
            if(ones>0){
                do{
                    cout<<"Would you like to cash in your 1s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1=ones*100;
                    }if(dec=='N'){
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
                
            }
            if(fives>0){
                do{
                    cout<<"Would you like to cash in your 5s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1=fives*100;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 5s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
                
            }
            //Decision to cash in 3s for points
            if(twos==3){
                do{
                    cout<<"Would you like to cash in your 2s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1+=200;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            //Decision to cash in 3s for points
            if(threes==3){
                do{
                    cout<<"Would you like to cash in your 3s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1+=400;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 3s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            //Decision to cash in 4s for points
            if(fours==3){
                do{
                    cout<<"Would you like to cash in your 4s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1+=600;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 4s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            if(sixes==3){
                do{
                    cout<<"Would you like to cash in your 6s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre1+=800;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            else{
                cout<<"Farkle! You lose half your points."<<endl;
                scre1=scre1/2;
            }
            //Announcing the player 1's score
            cout<<plyr1<<"'s score is"<<scre1<<endl;

            //Player 2's turn
            
            t1=0;
            t2=0;
            t3=0;
            t4=0;
            t5=0;
            t6=0;
  
            cout<<"=================================="<<endl;
            cout<<"It is "<<name2<<"'s turn!"<<endl;
            cout<<"Rolling dice..."<<endl;
            t1=rand()%6+1;
            t2=rand()%6+1;
            t3=rand()%6+1;
            t4=rand()%6+1;
            t5=rand()%6+1;
            t6=rand()%6+1;//The rolls
            cout<<"Player 2's rolls are "<<t1<<        
                    " "<<t2<<
                    " "<<t3<<
                    " "<<t4<<
                    " "<<t5<<
                    " "<<t6<<endl;

            //Scoring player 2

            ones=0;
            twos=0;
            threes=0;
            fours=0;
            fives=0;
            sixes=0;

            //Determining the value given for the 1st throw
            if(t1==1){
                ones+=1;
            }if(t1==2){
                twos+=1;
            }if(t1==3){
                threes+=1;
            }if(t1==4){
                fours+=1;
            }if(t1==5){
                fives+=1;
            }if(t1==6){
                sixes+=1;
            }

            //Determining the value given for the 2nd throw
            if(t2==1){
                ones+=1;
            }if(t2==2){
                twos+=1;
            }if(t2==3){
                threes+=1;
            }if(t2==4){
                fours+=1;
            }if(t2==5){
                fives+=1;
            }if(t2==6){
                sixes+=1;
            }

            //Determining the value given for the 3rd throw
            if(t3==1){
                ones+=1;
            }if(t3==2){
                twos+=1;
            }if(t3==3){
                threes+=1;
            }if(t3==4){
                fours+=1;
            }if(t3==5){
                fives+=1;
            }if(t3==6){
                sixes+=1;
            }

            //Determining the value given for the 4th throw
            if(t4==1){
                ones+=1;
            }if(t4==2){
                twos+=1;
            }if(t4==3){
                threes+=1;
            }if(t4==4){
                fours+=1;
            }if(t4==5){
                fives+=1;
            }if(t4==6){
                sixes+=1;
            }

            //Determining the value given for the 5th throw
            if(t5==1){
                ones+=1;
            }if(t5==2){
                twos+=1;
            }if(t5==3){
                threes+=1;
            }if(t5==4){
                fours+=1;
            }if(t5==5){
                fives+=1;
            }if(t5==6){
                sixes+=1;
            }

            //Determining the value given for the 6th throw
            if(t6==1){
                ones+=1;
            }if(t6==2){
                twos+=1;
            }if(t6==3){
                threes+=1;
            }if(t6==4){
                fours+=1;
            }if(t6==5){
                fives+=1;
            }if(t6==6){
                sixes+=1;
            }

            //Outputting the dice rolls in columns
            
            cout<<"Ones "<<"Twos "<<"Threes "
                    <<"Fours "<<"Fives "<<"Sixes "<<endl;
            
            cout<<" "<<ones<<"    "<<twos<<"     "<<threes<<"      "<<fours<<
                    "     "<<fives<<"     "<<sixes<<endl;
            
            //Player 2 deciding how to score points
            
            if(ones>0){
                do{
                    cout<<"Would you like to cash in your 1s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2=ones*100;
                    }else{
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y');
                
            }
            //Decision to cash in 5s for points
            if(fives>0){
                do{
                    cout<<"Would you like to cash in your 5s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2=fives*100;
                    }else{
                        cout<<"You did not cash out your 5s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
                
            }
            //Decision to cash in 3s for points
            if(twos==3){
                do{
                    cout<<"Would you like to cash in your 2s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2+=200;
                    }else{
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            //Decision to cash in 3s for points
            if(threes==3){
                do{
                    cout<<"Would you like to cash in your 3s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2+=400;
                    }else{
                        cout<<"You did not cash out your 3s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            //Decision to cash in 4s for points
            if(fours==3){
                do{
                    cout<<"Would you like to cash in your 4s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2+=600;
                    }else{
                        cout<<"You did not cash out your 4s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            if(sixes==3){
                do{
                    cout<<"Would you like to cash in your 6s for points?"<<endl;
                    cout<<"Type in 'Y' for yes and 'N' for no."<<endl;
                    cin>>dec;
                    //Input Validation
                    if(dec!='Y'&&dec!='N'){
                        cout<<"Invalid Input, please input 'Y' or 'N'."<<endl;
                    }
                    if(dec=='Y'){
                        scre2+=800;
                    }else{
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            else{
                cout<<"Farkle! You lose half your points."<<endl;
                scre2=scre2/2;
            }
            cout<<plyr2<<"'s score is"<<scre2<<endl;
        }   
    //Display Outputs
    if(scre1>=10000){
        w1++;
        los2++;
    }
    //Output scores and win/losses to a file
    ofstream outputFile;
    outputFile.open("Scores.txt");
    outputFile<<plyr1<<"'s score : "<<scre1<<endl;
    outputFile<<plyr2<<"'s score : "<<scre2<<endl;
    
    //Close the file
    outputFile.close();
    
    //Exit Program!
    return 0;
}

