
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
void chkRoll(int, int [], int &, int &, int &, int &, int &, int &);
void sorting(int [], int);
void sorting(int [], int, int);

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
    choice=2;
    
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
    
    //The bulk of the game
    while(fScore1<=10000&&fScore2<=10000){
        cout<<"========================================="<<endl;
        cout<<"It is "<<player1<<"'s turn!"<<endl;
        cout<<"Rolling dice..."<<endl;

        //Fill the array with random dice rolls for player 1
        fillArr(SIZE,array);

        //Scoring Player 1
        iScore1=fScore1;

        //Check the number of same die rolled
        chkRoll(SIZE,array,ones,twos,threes,fours,fives,sixes);

        //Sort the array using a selection sort
        sorting(array,SIZE);
        
        //Display the numbers rolled after being sorted
        cout<<"You rolled the following numbers:"<<endl;
        for(int i=0; i<SIZE; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
        
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

        //==================================================================
        //==================================================================
        //==================================================================


        //Player 2's turn
        cout<<"========================================="<<endl;
        cout<<"It is "<<player2<<"'s turn!"<<endl;
        cout<<"Rolling dice..."<<endl;

        //Fill the array with random dice rolls for player 1
        fillArr(SIZE,array);

        //Scoring Player 1
        iScore2=fScore2;

        //Check the number of same die rolled
        chkRoll(SIZE,array,ones,twos,threes,fours,fives,sixes);
        
        //Sort the array using a bubble sort
        sorting(array,SIZE,choice);
        
        //Display the numbers rolled after being sorted
        cout<<"You rolled the following numbers:"<<endl;
        for(int i=0; i<SIZE; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;

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

        //Announcing the player 2's score
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
    //Return a random die roll and count the total number of dice rolled
    static int numRoll=0;
    numRoll++;
    cout<<"***** Number of total dice rolls = "<<numRoll<<endl;
    
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
    //Fill the array with 6 random dice rolls and display the dice rolled
    for(int i=0; i<size; i++){
        A[i]=dieRoll();
    }
}

void chkRoll(int size, int A[], int &ones, int &twos, int &threes, int &fours,
        int &fives, int &sixes){
    //Tally the number of same dice rolled and display those numbers
    ones=0;
    twos=0;
    threes=0;
    fours=0;
    fives=0;
    sixes=0;
    int num;
    for(int i=0; i<size; i++){
        num=A[i];
        switch(num){
            case 1: ones++;break;
            case 2: twos++;break;
            case 3: threes++;break;
            case 4: fours++;break;
            case 5: fives++;break;
            case 6: sixes++;break;
        }
    }
    cout<<"Ones "<<"Twos "<<"Threes "
            <<"Fours "<<"Fives "<<"Sixes "<<endl;
            
    cout<<setw(2)<<ones<<setw(5)<<twos<<setw(7)<<threes<<setw(6)
            <<fours<<setw(6)<<fives<<setw(6)<<sixes<<endl;
}

void sorting(int A[], int n){
    //This is a selection sort
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=A[pos];
        for(int i=pos+1;i<n;i++){
            if(A[i]<min){
                min=A[i];
                indx=i;
            }
        }
        //Perform the swap
        A[indx]=A[pos];
        A[pos]=min;
    }
}

void sorting(int A[], int n, int null){
    //This is a bubble sort
    //Keep looping and comparing until no swaps are left
    bool swap;
    null=0;
    do{
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                int temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}