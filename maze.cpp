#include<iostream>
#include<fstream>
using namespace std;

int start_i;
int start_j;
int end_i;
int end_j;
int cost=0;
class Queue;
class DynamicSafeArray
{
  char **data;
   	int row,col;
   	public:
   	DynamicSafeArray()
   	{
   	   data=0;
		row=0;
	
		col=0;
		
	}

   DynamicSafeArray(int nrow,int ncol)
   {
   	    row=nrow;
   	    col=ncol;
   	     
   	    data=new char*[row];
   	    for(int i=0;i<row;i++)
   	    data[i]=new char[col];
   }
   

    
   friend ostream& operator <<(ostream&out,DynamicSafeArray &obj)
{

	for(int i=0;i<obj.row;i++)
	{
	
	for(int j=0;j<obj.col;j++)
	  {
	  	 out<<obj.data[i][j]<<"    ";
      }
      cout<<endl<<endl;
    }
	
	return out;
}
char &operator ()(int i,int j ) 
{

	return data[i][j];
	
	
}

friend istream& operator >>(istream&in,DynamicSafeArray &obj)
{
	
	for(int i=0;i<obj.row;i++)
	for(int j=0;j<obj.col;j++)
	 in>>obj.data[i][j];
	
	return in;
}

void print()
{
	for(int i=0;i<row;i++)
	{
	
	for(int j=0;j<col;j++)
	  {
	  	 cout<<data[i][j]<<"    ";
      }
      cout<<endl<<endl;
    }
	
	exit(1);
}

friend void start(DynamicSafeArray &maze,int i,int j);
friend void path(DynamicSafeArray &maze,DynamicSafeArray &sol,int i,int j,Queue[],Queue[]);
};

class Queue
{
	
    int *Data;
	int front;
	int rear;
	

	
	public:
	
	int cost;
	



Queue()
{
	
	Data=new int[100];
    front =-1;
	rear=-1;	
	cost=0;
	
	
}


void enqueue(int n)
{
	rear++;
	
	
	if(front=-1)
	front++;

		Data[rear]=n;
		

	
}

int dequeue()
{
	int var;

	
		var=Data[front];
		front++;
	    return var;
		

	
}


int size()
{
	return((rear-front)+1);
	
	
}
bool isempty()
{
	if(front==rear)
	return true;
	else
	return false;
	
}

int Front()
{
		if(front==-1)
	{
	cout<<"\n\nQueue is empty\n\n";
       
   }
   else
   return Data[front];
	
	
}

void print()
{
	
	for(int i=front;i<=rear;i++)
	{
		cout<<Data[i]<<" ";
	}
	
	cout<<endl;
	
}
};

 void start( DynamicSafeArray&maze,int i,int j)
{
	bool  S=false;
	bool  E=false;
	
	
	for(int k=0,l=0;l<j;l++)
	{
		if(maze.data[k][l]=='s')
		{
			S=true;
			start_i=k;
			start_j=l;

		}
		else if(maze.data[k][l]=='e')
		{
			E=true;
			end_i=k;
			end_j=l;

			
			
		}
	}
		for(int k=0,l=0;k<i;k++)
	{
		if(maze.data[k][l]=='s')
		{
		   S=true;
			start_i=k;
			start_j=l;

		}
		else if(maze.data[k][l]=='e')
		{
			E=true;
			end_i=k;
			end_j=l;
	
			
			
		}
	}
	
		for(int k=i-1,l=0;l<j;l++)
	{
		if(maze.data[k][l]=='s')
		{
			S=true;
			start_i=k;
			start_j=l;
		
		}
		else if(maze.data[k][l]=='e')
		{
			E=true;
			end_i=k;
			end_j=l;
			
			
			
		}
	}
		
		for(int k=0,l=j-1;k<i;k++)
	{
		if(maze.data[k][l]=='s')
		{
			S=true;
			start_i=k;
			start_j=l;
			
		}
		else if(maze.data[k][l]=='e')
		{
			E=true;
			end_i=k;
			end_j=l;
		
			
			
		}
	}
	 if(!(S&&E))
	 {
	cout<<"\nStart or end point not at boundary !!!\n";
      exit(1);
     }
}
 void path(DynamicSafeArray &maze,DynamicSafeArray &sol,int i,int j,Queue qi[],Queue qj[])
{

 
static int m=0;
 
	if(i<0||i>maze.row-1||j<0||j>maze.col-1||maze.data[i][j]=='0')
	{
	
	   return;
	}
	


	if(i==end_i&&j==end_j)
	{
		
	 sol.data[i][j]='1';

	 int k=start_i,l=start_j;
	 qi[m].enqueue(k);
	 qj[m].enqueue(l);
	 while(1)
	 {
	 

	 
	 	if(l-1>=0)
	 	{
	 		if(sol.data[k][l-1]=='1')
	 		{
	 		sol.data[k][l]='x';
	 			l=l-1;
				qi[m].enqueue(k);
	            qj[m].enqueue(l);
	 			
	 			
	 		}
	 		
	 	}
	 	
	 	  if(k==end_i&&l==end_j)
	 	  break;
	 	
	 	 if(k-1>=0)
	 	{
	 		if(sol.data[k-1][l]=='1')
	 		{
	 			sol.data[k][l]='x';
	 			k=k-1;
	 			 	 qi[m].enqueue(k);
	                qj[m].enqueue(l);
	 		
	 			
	 		}
	 		
	 	}
	 	 if(k==end_i&&l==end_j)
	 	  break;
	 		 if(k+1<=maze.row-1)
	 	{
	 		if(sol.data[k+1][l]=='1')
	 		{
	 			sol.data[k][l]='x';
	 			k=k+1;
	 			 	 qi[m].enqueue(k);
	               qj[m].enqueue(l);
	 		
	 		}
	 		
	 	}
	 	if(k==end_i&&l==end_j)
	 	  break;
	 ;
	 	 		if(l+1<=maze.col-1)
	 	{
	 		if(sol.data[k][l+1]=='1')
	 		{
	 			sol.data[k][l]='x';
	 			l=l+1;
	 		qi[m].enqueue(k);
	        qj[m].enqueue(l);
	 		
	 		}
	 		
	 	}
	 	 if(k==end_i&&l==end_j)
	 	  break;

	 }
	 qi[m].cost=cost+1;
	 qj[m].cost=cost+1;
	  for(k=0;k<sol.row;k++)
	  for(l=0;l<sol.col;l++)
	  if(sol.data[k][l]=='x')
	   sol.data[k][l]='1';
	   
	  
          m++;
	  
	}
	else
	{
		
	  maze.data[i][j]='0';
       	sol.data[i][j]='1';
	  cost++;
	  path(maze,sol,i,j+1,qi,qj);
      path(maze,sol,i,j-1,qi,qj);
	  path(maze,sol,i+1,j,qi,qj);
	  path(maze,sol,i-1,j,qi,qj);
    
	  maze.data[i][j]='1';
	  	 sol.data[i][j]='0';
	  
	   
	  cost--;
   }


	

	
	
	
	
	
}
void correct(Queue qi[],Queue qj[])	
{
	
  for(int i=0;qi[i].cost!=0;i++)
	{

		for(int j=i+1;qj[j].cost!=0;j++)
		{
			if(qi[i].cost>qj[j].cost)
			{
				Queue tempi,tempj;
			
			   tempi=qi[i];
			   qi[i]=qi[j];
			   qi[j]=tempi;
			   
			   tempj=qj[i];
			   qj[i]=qj[j];
			   qj[j]=tempj;
		      }
		}
	
	
}
}
	
	
	
	


int main()
{
	ifstream outfile("A2P1-in-01.txt"); //input
	int i,j;
	outfile>>i>>j;
	DynamicSafeArray maze(i,j);
	DynamicSafeArray sol(i,j);
	outfile>>maze;
    maze.print();
    for(int k=0;k<i;k++)
    for(int l=0;l<j;l++)
    sol(k,l)='0';
	outfile.close();
	start(maze,i,j);

    Queue qi[100];
    Queue qj[100];
	path(maze,sol,start_i,start_j,qi,qj);
	correct(qi,qj);
  
	ofstream writefile("output.txt");
		int var1;
		int var2;
		
		for(int i=0;qi[i].cost!=0;i++)
		{
			writefile<<"Path#"<<i+1<<"={";
		while(!(qi[i].isempty()))
		{
			var1=qi[i].dequeue();
			var2=qj[i].dequeue();
		   	writefile<<"("<<var1<<","<<var2<<"),";
		   	
		}
		 writefile<<"("<<end_i<<","<<end_j<<")";
		writefile<<"} Cost="<<qi[i].cost<<endl;
	    }
		
		writefile.close();
		return 0;

	}
   
   

    
	

