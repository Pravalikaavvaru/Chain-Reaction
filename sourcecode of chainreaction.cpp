//chain reaction//
#include<iostream.h>
struct data
{
	int no_bubbles;//holds the number of bubbles//
	char color;//3 colors(red),(green),(blue)
};
class chain_reaction
{
	 data board[10][10];
	int i,j,n;
	public:
		chain_reaction(int n)
        { for(i=0;i<n;i++)
        {
         for(j=0;j<n;j++)
        {

          board[i][j].no_bubbles=0;
		  board[i][j].color='N';         	
        }
        	
        }
        }
		/*void addbubble(int i,int j)
		{
		  board[i][j].no_bubbles=board[i][j].no_bubbles+1;
		  if((i==0)&&(j==0)||(i==0)&&(j==9)||(i==9)(j==0)||(i==9)(i==9))
		  	{
		  		if(board[i][j].no_bubbles==1)
		  		{ 
		  			//call a recursive function//
		  		}
		  	}
		  else if((i==0)||(i==9)||(j==0)||(j==9))
		  	{
		  		if(board[i][j].no_bubbles==2)
		  		{  
		  			//call the recursive function//
		  		}
		  	}	
		  else
		  {
		  	if(board[i][j].no_bubbles==3)
		  	{  
		  		//call the recursive function//
		  	}
		  }
		  }*/
        int bomb(int i,int j,char c)
		{  board[i][j].color=c;
		   board[i][j].no_bubbles++;
           if(board[i][j].no_bubbles<4)
           return 0;
           else
           {
           board[i][j].no_bubbles=0;
           if(i+1<n)
           bomb(i+1,j,c);
           if(i-1>=0)
           bomb(i-1,j,c);
           if(j+1<n)
           bomb(i,j+1,c);
           if(j-1>=0)
           bomb(i,j-1,c);
           }
           return 0;
		}
		void display_board()
		{   for(i=0;i<n;i++)
           {
             for(j=0;j<n;j++)
             {
               cout<<board[i][j].no_bubbles<<" ";
			   cout<<"color is\n"<<board[i][j].color;         	
             }
        	cout<<"\n";
           }
        }
        int check_game_end(int flag,char c)//checks if the all the bubbles are of same color//
        {   char x=c;
            flag=1;
		    for(i=0;i<n;i++)
           { 
             for(j=0;j<n;j++)
             { if(x==board[i][j].color)
             { flag=1;         	
             }
             else
             {flag=2;
             }
             if(flag==2)
             {break;
             }
             }
           }
             return flag;
        }
};		  
int main()
{   int no_of_players;
    int win;
    int i,j,n;
    char color[3];
    int flag;
    cout<<"enter the size of the grid\n";
    cin>>n;
	chain_reaction sample(n);
	cout<<"1. two players(2) 2. three players(3)\n";
    cin>>no_of_players;
	if(no_of_players==2)
	{   flag=2;
		color[0]='R';
		color[1]='G';
		
	}
	else
	{   flag=3;
		color[0]='R';
		color[1]='G';
		color[2]='B';
	}
	if(no_of_players==2)
	{
		cout<<"enter player 1 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[0]);
		cout<<"...................";
		sample.display_board();
		cout<<"...................";
		cout<<"enter player 2 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[1]);
		cout<<"....................";
		sample.display_board();
	while(flag!=1)
	{
		cout<<"enter player 1 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[0]);
		flag=check_game_end(flag,color[0]);
		if(flag==1)//to check if the bubbles are of one color//
		{
		  win=1;
		}
		cout<<"...................";
		sample.display_board();
		cout<<"...................";
		cout<<"enter player 2 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[1]);
		flag=check_game_end(flag,color[1]);
		if(flag==1)//to check if the bubbles are of one color//
		{
		  win=2;
		}
	}	
    }
    else
    {
    	while(flag!=1)
	{
		cout<<"enter player 1 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[0]);
		cout<<"...................";
		sample.display_board();
		cout<<"...................";
		cout<<"enter player 2 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[1]);
		cout<<"....................";
		sample.display_board();
		cout<<"....................";
		cout<<"enter player 2 choice\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"j:\n";
		cin>>j;
		sample.bomb(i,j,color[2]);
		cout<<"...................";
		sample.display_board();
		cout<<"....................";
	}	
    }
}

	
