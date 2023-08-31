#include<iostream>

using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie=false;
void display(){
    
    

    cout<<"     |      |      "<<endl;
    cout<<"  "<<space[0][0]<<"  |  "<<space[0][1]<<"   |  "<<space[0][2]<<"  \n";
    cout<<"_____|______|______"<<endl;
    cout<<"     |      |      "<<endl;
    cout<<"  "<<space[1][0]<<"  |  "<<space[1][1]<<"   |  "<<space[1][2]<<"  \n";
    cout<<"_____|______|______"<<endl;
    cout<<"     |      |      "<<endl;
    cout<<"  "<<space[2][0]<<"  |  "<<space[2][1]<<"   |  "<<space[2][2]<<"  \n";
    cout<<"     |      |      "<<endl;
}

void input()
{
    int digit;
    if(token=='x')
    {
        cout<<"Player 1 please enter"<<endl;
        cin>>digit;
    }
    if(token=='o')
    {
        cout<<"Player 2 please enter"<<endl;
        cin>>digit;
    }

    switch(digit)
    {
       case 1: row=0;column=0;break;
       case 2: row=0;column=1;break;
       case 3: row=0;column=2;break;
       case 4: row=1;column=0;break;
       case 5: row=1;column=1;break;
       case 6: row=1;column=2;break;
       case 7: row=2;column=0;break;
       case 8: row=2;column=1;break;
       case 9: row=2;column=2;break;
       default :cout<<"Enter correct Value"<<endl;
    }

    if(token=='x' && space[row][column]!='x' && space[row][column]!='o')
    {
        space[row][column]='x';
        token='o';
    }
    else if(token=='o' && space[row][column]!='x' && space[row][column]!='o')
    {
        space[row][column]='o';
        token='x';
    }
    else{
        cout<<"There is no empty space!"<<endl;
        input();
    }
    display();
}

bool win()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    return true;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='x' && space[i][j]!='o')
            return false;
        }
    }

    tie=true;
    return false;
}

int main()
{

    cout<<"Player 1 will play first"<<endl;
    cout<<"Player 2 will play second"<<endl;

    while(!win())
    {
        display();
        input();
        win();
    }

    if(token=='x' && tie==false)
    cout<<"Player 2 Wins"<<endl;
    else if(token=='o' && tie==false)
    cout<<"Player 1 Wins"<<endl;

    else
    cout<<"It's a Draw"<<endl;
}