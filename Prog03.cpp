/* Aaron Grant CSC 375
   Union/Find using General Trees
   Maze Program #3   */


#include <iostream.h>
#include <time.h>
#include <stdlib.h>
// btC++ #include <a:bool.h>
#include <a:maze.h>

int main(int argc, char *argv[]) {
  general *node;
  if (argc != 3) {
      cout << "usage:  " << argv[0] << " rows columns \n";
      return 0;
  }
    
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  long seed = time(0);
  int index= ( rows * cols ) + 1;
  node = new general[index];
  gentree GT;
  GT.agentree(index);
  int c = 1;
  for (int i = 0; i < rows; i++)  {
    for (int j = 0; j < cols; j++) {
      	  node[c].top=1;
		  node[c].bottom=1;
		  node[c].left=1;
		  node[c].right=1;
	  c++; 
    }
  }
  int random;
  int tree = c-1;
  int side = 0;
  int newnode = 0;
  bool flag=1;
  srand(seed);
	while ((tree) > 0) { 
                flag=1;
		random = rand() % index;
		side = rand() % 4;
	 
        if (((random % cols) == 0) && (side == 2)) {
		while (side == 2)
		side = rand()%4;
		 }
	if (random == 1) {
		while ((side == 0) || (side == 1))
		side = rand()%4;
		 }
	if (random == cols ) {
		while ((side == 1) || (side == 2))
		side = rand()%4;
		 }
        if (((random % cols) == 1) && (side == 0)) {
		while (side == 0)
		side = rand()%4;
		 }
	if ((random > (cols * rows - cols)) && (side == 3)) {
		while (side == 3)
		side = rand()%4;
		 }
	if (random == (index - cols)) {
		while ((side == 3) || (side == 0))
		side = rand()%4;
		 }
	if ((random <cols) && (side == 1)) {
		while (side == 1)
		side = rand()%4;
		 }
        if (random == index) {
		while ((side == 3) || (side == 2))
		side = rand() % 4;
		 }
        if (random == 0)
		 flag = 0;
		 switch (side) {
		     case 0 : {
			 if ((random - 1) > 0)
				 newnode = random-1;
			 else
			  	 flag=0;
			 } break;
			 
			 case 1 : {
			 if ((random - cols) > 0)
				 newnode = random-cols;
			 else
				 flag=0;
			 } break;

			 case 2: {
			 if ((random + 1) <= index)
				 newnode = random+1;
			 else
				 flag=0;
			 } break;

			 case 3: {
			 if ((random + cols) <= index)
				 newnode = random+cols;
			 else
				 flag=0;
			 } break;	
		 }
          if (flag == 1)  {    
			 flag=GT.differ(random,newnode);
			 if (flag) {
				  GT.UNION(random,newnode); 
				  switch (side)
				  {
		           case 0 : {
				  node[random].left =0;
				  node[newnode].right=0;
				} break;
			 
		           case 1 : {
				  node[random].top =0;
				  node[newnode].bottom =0;
				} break;

			   case 2: {
				  node[random].right =0;
				  node[newnode].left=0;
				} break;

	                   case 3: {
				  node[random].bottom =0;
				  node[newnode].top=0;
				} break;
		         }
	  tree--;
			 }}}
	  int ct = 1;
 cout << endl << endl << endl;
 cout << "  |"; 
        for (i = 0; i < cols; i++) 
	cout << "-|" << endl;
 c=1;
 for (i= 0; i < rows; i++)
	{
            if (!i == 0)
		cout << "  |";
            else 
                cout << "   ";
	    ct=c;
		for (int j = 0; j < cols; j++) {
		   if (node[c].right)
			   cout << " |";
		   else
			   cout << "  ";
		   c++;
		}
	   cout << endl;
	   cout << "  |";
           for (j = 0; j < cols; j++)	{
            if (node[ct].bottom)
		 cout << "-|";
	    else
		 cout << " |"; 
	    ct++;
		}
        cout << endl;
	}
 return 0;	
 }
