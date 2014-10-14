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
		chain_reaction(int n1)
        { n=n1;
		 for(i=0;i<n;i++)
        {
         for(j=0;j<n;j++)
        {
          if((i==0&&j==0)||(i==0&&j==(n-1))||(i==(n-1)&&j==0)||(i==(n-1)&&j==(n-1)))
          {
          	board[i][j].no_bubbles=2;
		    board[i][j].color='N';  
          }
          else if(i==0||i==n-1||j==0||j==n-1)
          {
          board[i][j].no_bubbles=1;
		  board[i][j].color='N';
	      }
	      else
	      {
	      	board[i][j].no_bubbles=0;
		    board[i][j].color='N';
	      }
        }
        }
        }
    
	
        int bomb(int i,int j,char c)
		{  board[i][j].color=c;
		   board[i][j].no_bubbles++;
           if(board[i][j].no_bubbles<4)
           return 0;
           else
           {
            if((i==0&&j==0)||(i==0&&j==(n-1))||(i==(n-1)&&j==0)||(i==(n-1)&&j==(n-1)))
            {
          	board[i][j].no_bubbles=2;
		    board[i][j].color='N';  
            }
            else if(i==0||i==n-1||j==0||j==n-1)
            {
            board[i][j].no_bubbles=1;
		    board[i][j].color='N';
	        }
	        else
	        {
	      	board[i][j].no_bubbles=0;
		    board[i][j].color='N';
	        }
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
               cout<<board[i][j].no_bubbles<<"("<<board[i][j].color<<")"<<" ";
             }
        	cout<<"\n";
           }
        }
        int check_game_end(int flag,char c)//checks if the all the bubbles are of same color//
        {   flag=0;
		    for(i=0;i<n;i++)
           { 
             for(j=0;j<n;j++)
             { if(board[i][j].color==c)
             { flag=1;         	
             }
             else if(board[i][j].color=='N')
             {
             	flag=2;
             }
             else
             {
             	flag=3;
             	break;
             }
             }
             if(flag==3)
             {break;
             }
             
           }
             return flag;
        }
        char color_check(int i,int j)
        {
        	return board[i][j].color;
        }
};		  
int main()
{   int no_of_players;
    int win;
    int i,j,n1;
    char color[3];
    int flag=0;
    int correct;//checks if player has entered the right value
    char check;
    cout<<"enter the size of the grid\n";
    cin>>n1;
	chain_reaction sample(n1);
	sample.display_board();
	cout<<"a)two players(2) b)three players(3)(choose 2 or 3)\n";
    cin>>no_of_players;
	if(no_of_players==2)
	{   
		color[0]='R';
		color[1]='G';
		
	}
	else if(no_of_players==3)
	{   
		color[0]='R';
		color[1]='G';
		color[2]='B';
	}
	if(no_of_players==2)
	{   
		cout<<"enter player 1 choice(RED)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		sample.bomb(i,j,color[0]);
		cout<<"...................\n";
		sample.display_board();
		cout<<"...................\n";
		do
        {
		cout<<"enter player 2 choice(GREEN)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[1])||(check=='N'))
		{
		 sample.bomb(i,j,color[1]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
	    cout<<".........................\n";
	    sample.display_board();
	    cout<<".........................\n";
	while((flag!=1)||(flag!=2))
	{
		do
		{
		cout<<"enter player 1 choice(RED)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[0])||(check=='N'))
		{sample.bomb(i,j,color[0]);
		 correct=0;
	    }
	    else
	    {
	     cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
		flag=sample.check_game_end(flag,color[0]);
		cout<<flag<<"\n";
		if(flag==1||flag==2)//to check if the bubbles are of one color//
		{
		  win=1;
		  break;
		}
		flag=0;
		cout<<"...................\n";
		sample.display_board();
		cout<<"....................\n";
        do
        {
		cout<<"enter player 2 choice(GREEN)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[1])||(check=='N'))
		{
		 sample.bomb(i,j,color[1]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
	    flag=sample.check_game_end(flag,color[1]);
		cout<<flag<<"\n";
		if(flag==1||flag==2)//to check if the bubbles are of one color//
		{
		  win=2;
		  break;
		}
		flag=0;
		cout<<"....................\n";
		sample.display_board();
		cout<<"....................\n";
	}
    }
    else
    { 
        cout<<"enter player 1 choice(RED)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		sample.bomb(i,j,color[0]);
		cout<<"...................\n";
		sample.display_board();
		cout<<"...................\n";
		do
        {
		cout<<"enter player 2 choice(GREEN)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[1])||(check=='N'))
		{
		 sample.bomb(i,j,color[1]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
        cout<<"....................\n";
		sample.display_board();
		cout<<"....................\n";
		do
        {
		cout<<"enter player 3 choice(BLUE)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[2])||(check=='N'))
		{
		 sample.bomb(i,j,color[2]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
		cout<<"....................\n";
		sample.display_board();
		cout<<"....................\n";
		
    	while(flag!=1||flag!=2)
	  {
		do
        {
		cout<<"enter player 1 choice(RED)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[0])||(check=='N'))
		{
		 sample.bomb(i,j,color[0]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
		cout<<"...................\n";
		flag=sample.check_game_end(flag,color[0]);
		cout<<flag<<"\n";
		if(flag==1||flag==2)//to check if the bubbles are of one color//
		{
		  win=1;
		  break;
		}
		flag=0;
		sample.display_board();
		cout<<"...................\n";
		do
        {
		cout<<"enter player 2 choice(GREEN)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[1])||(check=='N'))
		{
		 sample.bomb(i,j,color[1]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
		cout<<"....................\n";
		flag=sample.check_game_end(flag,color[1]);
		cout<<flag<<"\n";
		if(flag==1||flag==2)//to check if the bubbles are of one color//
		{
		  win=2;
		  break;
		}
		flag=0;
		sample.display_board();
		cout<<"....................\n";
		do
        {
		cout<<"enter player 3 choice(BLUE)\n";
		cout<<"x:\n";
		cin>>i;
		cout<<"y:\n";
		cin>>j;
		check=sample.color_check(i,j);
		if((check==color[2])||(check=='N'))
		{
		 sample.bomb(i,j,color[2]);
		 correct=0;
	    }
	    else
	    {cout<<"wrong choice!!try again\n";
	     correct=1;
	    }
	    }while(correct==1);
		cout<<"...................\n";
		flag=sample.check_game_end(flag,color[2]);
		cout<<flag<<"\n";
		if(flag==1||flag==2)//to check if the bubbles are of one color//
		{
		  win=3;
		  break;
		}
		flag=0;
		sample.display_board();
		cout<<"....................\n";
	}	
    }
    sample.display_board();
    if(win==1)
    {
    	cout<<"player one wins:)\n";
    }
    else if(win==2)
    {
    	cout<<"player two wins:)\n";
    }
    else
    {
    	cout<<"player three wins:)\n";
    }
    
}

	
