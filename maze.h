struct general;
struct general
{
 bool top;
 bool right;
 bool left;
 bool bottom;
 };

class gentree
{                                        
private:
    int* array;
    int size;
    int find(int curr);
    int num1;
    int num2;

public:
    void agentree(int);
    void UNION(int,int);
    bool differ(int,int);
};

void gentree::agentree(int size)           
{   size++;
    array=new int[size];
    for(int i =0; i<size;i++)  {
	array[i]=i;
    }
}
int gentree::find(int curr)
{ 
    if (array[curr] == curr)
    return(curr); 
    return (array[curr]=find(array[curr])); 
}
bool gentree::differ(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    return (root1 != root2);
}
void gentree::UNION(int a, int b)
{   num1=0;
    num2=0;
    int root1 = find(a);
    int root2 = find(b);
    if (root1 != root2)	 {
	if (num1 < num2)
	  array[root1]=root2;                         
	else
	  array[root2]=root1;
	 }
}