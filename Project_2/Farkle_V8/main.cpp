
/* 
 * File:   main.cpp
 * Author: Noel Verduzco
 * Created on November 1, 2018, 6:59 PM
 * Purpose: Farkle Game
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <ctime>    //Unique Seed Value Library
#include <cstdlib>  //Random Value Library
#include <fstream>  //File Input/Output
#include <string>   //String library
#include <iomanip>  //Formatting Library
#include <cmath>    //Math Library

using namespace std;

//User Libraries

//Global Constants: Math, Physics, Science, Conversions, 2-D Array C

//Function Prototypes
void rules();
void scores(string, string, float, float, float, float, float, float);
void getName(string &, string &);
bool isRun(int);
int dieRoll();
void plyrOne(string, string, string &, string &);
void fillArr(int, int []);

//Execution begins Here!
int main(int argc, char** argv) {
    //Set the random number seed 
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float fScore1,fScore2,iScore1,iScore2;  //The scores for player 1 and 2
    int ini1,ini2,                          //Initial roll to see who goes 1st
        t1,t2,t3,t4,t5,t6,                  //Each time the dice is thrown
        w1,los1,w2,los2,                    //Win and loss for player 1 and 2
        ones,twos,threes,fours,fives,sixes, //Counter for the dice rolls
        choice;                             //Choice for the menu
    char dec;                               //Decision for cashing in points
    bool first;                             //Test to choose player 1
    string name1,name2,                     //Input for player names
           player1,player2;                 //Determines which player goes 1st
    const int SIZE = 6;
    int array[SIZE];
    
    //Initialize Variables
    fScore1=0;
    fScore2=0;
    iScore1=0;
    iScore2=0;
    w1=0;
    w2=0;
    los1=0;
    los2=0;
    ini1=0;
    ini2=0;
    
    //Display the rules at game beginning
    rules();
    
    //Get the names of the players
    getName(name1,name2);
    
    //Determine whether to run the game
    if(isRun(choice)==false){
        exit(0);
    }

    //Determine who player 1 will be
    plyrOne(name1,name2,player1,player2);
    
    //Fill the array with random dice rolls for player 1
    fillArr(SIZE,array);
    
    //Cout array values to make sure it works properly
    for(int i=0; i<SIZE; i++){
        cout<<array[i];
    }
    cout<<endl;
    
    //The bulk of the game
    while(fScore1<=10000&&fScore2<=10000){
            cout<<"========================================="<<endl;
            cout<<"It is "<<player1<<"'s turn!"<<endl;
            cout<<"Rolling dice..."<<endl;
            t1=rand()%6+1;
            t2=rand()%6+1;
            t3=rand()%6+1;
            t4=rand()%6+1;
            t5=rand()%6+1;
            t6=rand()%6+1;//The rolls
            cout<<player1<<"'s rolls are "<<t1<<        
                    " "<<t2<<
                    " "<<t3<<
                    " "<<t4<<
                    " "<<t5<<
                    " "<<t6<<endl;

            //Scoring Player 1
            iScore1=fScore1;
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
            
            cout<<setw(2)<<ones<<setw(5)<<twos<<setw(7)<<threes<<setw(6)<<fours<<
                    setw(6)<<fives<<setw(6)<<sixes<<endl;
            
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
                        fScore1+=ones*100;
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
                        fScore1+=fives*100;
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
                        fScore1+=200;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 2s"<<endl;
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
                        fScore1+=400;
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
                        fScore1+=600;
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
                        fScore1+=800;
                    }
                    if(dec=='N'){
                        cout<<"You did not cash out your 6s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            if((iScore1-fScore1)==0){
                cout<<"Farkle! You lose half your points."<<endl;
                fScore1=fScore1/2;
            }
            //Announcing the player 1's score
            cout<<player1<<"'s score is "<<ceil(fScore1)<<endl;

            //Player 2's turn
            
            t1=0;
            t2=0;
            t3=0;
            t4=0;
            t5=0;
            t6=0;
  
            cout<<"========================================="<<endl;
            cout<<"It is "<<player2<<"'s turn!"<<endl;
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
            iScore2=fScore2;
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
                        fScore2+=ones*100;
                    }if(dec=='N'){
                        cout<<"You did not cash out your 1s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
                
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
                        fScore2+=fives*100;
                    }if(dec=='N'){
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
                        fScore2+=200;
                    }if(dec=='N'){
                        cout<<"You did not cash out your 2s"<<endl;
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
                        fScore2+=400;
                    }if(dec=='N'){
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
                        fScore2+=600;
                    }if(dec=='N'){
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
                        fScore2+=800;
                    }if(dec=='N'){
                        cout<<"You did not cash out your 6s"<<endl;
                    }
                }while(dec!='Y'&&dec!='N');
            }
            if((iScore2-fScore2)==0){
                cout<<"Farkle! You lose half your points."<<endl;
                fScore2=fScore2/2;
            }
            cout<<player2<<"'s score is "<<ceil(fScore2)<<endl;
        }   
    
    //Display Outputs
    if(fScore1>=10000){
        w1++;
        los2++;
    }
    else if(fScore2>=10000){
        w2++;
        los1++;
    }
    else{
        w1=w1;
        w2=w2;
        los1=los1;
        los2=los2;
    }
    
    scores(player1,player2,fScore1,fScore2,w1,w2,los1,los2);
    
    //Exit Program!
    return 0;
}

void rules(){
    //Display the game rules and scoring guide
    string line;
    ifstream inputFile;
    inputFile.open("GameRules.txt");
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            cout<<line<<"\n";
        }
    inputFile.close();
    }
}

void scores(string p1, string p2, float s1, float s2, float w1,
        float w2, float los1, float los2){
    //Save scores and win/losses count to text file
    ofstream outputFile;
    outputFile.open("Scores.txt");
    outputFile<<p1<<"'s score, wins, and losses: "
            <<s1<<" / "<<w1<<" / "<<los1<<"\r\n";
    outputFile<<p2<<"'s score, wins, and losses: "
            <<s2<<" / "<<w2<<" / "<<los2;
    outputFile.close();
}

void getName(string &n1, string &n2){
    //Get the names of player 1 and player 2
    cout<<"Enter player 1's name"<<endl;
    cin>>n1;
    cout<<"========================================="<<endl;
    cout<<"Enter player 2's name"<<endl;
    cin>>n2;
    cout<<"========================================="<<endl;
}

bool isRun(int choice){
    //Game menu
    cout<<"This program can play the dice game Farkle."<<endl;
    cout<<"Press 1 to play or 0 to exit"<<endl;
    do{
        cin>>choice;
        
        //Input Validation
        if(choice!=1 && choice!=0){
            cout<<"Invalid input, please select either 1 or 0."<<endl;
        }
    }while(choice!=1 && choice!=0);
    cout<<"========================================="<<endl;
    
    if(choice==0){
        cout<<"Exiting program..."<<endl;
        return false;
    }
    
    return true;
}

int dieRoll(){
    static int numRoll=0;
    numRoll++;
    cout<<"Number of total dice rolls = "<<numRoll<<endl;
    
    int roll;    
    roll=rand()%6+1;
    return roll;
}

void plyrOne(string n1, string n2, string &p1, string &p2){
    int die1,
        die2;
    //Do while loop for determining which player goes first
    cout<<"Both players will now roll the dice"
            " to determine who will go first"<<endl;
    cout<<"========================================="<<endl;
    do{
        cout<<n1<< ", press any number to roll the dice"<<endl;
        cin>>die1;//Placeholder variable until roll
        die1=dieRoll();
        cout<<"You rolled a "<<die1<<endl;
        cout<<"========================================="<<endl;
        
        cout<<n2<<", press any number to roll the dice"<<endl;
        cin>>die2;//Placeholder variable until roll
        die2=dieRoll();
        cout<<"You rolled a "<<die2<<endl;
        cout<<"========================================="<<endl;
        
        if(die1==die2){
            cout<<"You both got the same number, roll again."<<endl;
            cout<<"========================================="<<endl;
        }
    }while(die1==die2);
    
    if(die1>die2){
        p1=n1;
        p2=n2;
        cout<<n1<<" is player 1"<<endl;
        cout<<n2<<" is player 2"<<endl;
    }else{
        p2=n1;
        p1=n2;
        cout<<n2<<" is player 1"<<endl;
        cout<<n1<<" is player 2"<<endl;
    }
}

void fillArr(int size, int A[]){
    for(int i=0; i<size; i++){
        A[i]=dieRoll();
    }
}