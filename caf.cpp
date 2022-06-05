#include<iostream.h>
#include<string.h>
using namespace std;
struct student
{
	int ID;
	string Name;
	int average ;
    int items;
	student(){average=0;}
	student(int av){average=av;}
	student(int sID,string n,int av,int i)
	{
		ID=sID;
		Name=n;
		average=av;
		items=i;
	}
	void operator=(student item){
	ID=item.ID;
	Name=item.Name;
	average=item.average;
	items=item.items;
    }
};
const int MAX=100;
template<class t>
class Queue{
	int front,rear,count;
	t entry[MAX]; 
public: 
    Queue(){ 
	front = count = 0;
	rear=MAX-1;
	} 
	bool Append(t x){
		if(count>MAX)return 0;
		rear=(rear+1)%MAX;
		entry[rear]=x;
		count++;
		return 1;
	} 
	bool Serve(){
		if(Empty()) return 0;
		front=(front+1)%MAX;
		count --;
		return 1;
	}
	bool Retrieve(t &x){
		if(Empty()) return 0;//if (count <= 0)      
		x=entry[front];
		return 1; 
	} 
    bool Empty() {
	     return (count == 0); 
    }  
}; 

void print(Queue<student>q){
	student item;int i=1;
	while(!q.Empty()){
		q.Retrieve(item);
		cout<<"#"<<i<<": "<<endl;
        cout<<"id: "<<item.ID<<endl;
        cout<<"name: "<<item.Name<<endl;
        cout<<"average: "<<item.average<<endl;
        cout<<"#of items: "<<item.items<<endl;
        q.Serve();  
		i++;  
        cout<<endl;
	}
	cout<<endl;
	
}
template <class t>
int size(Queue	<t>q){
	int c=0;
	while(!q.Empty()){
		c++;
        q.Serve();    

	}
	return c;
}
void Sort(int a[], int n) {
   int i, j, max, temp;
   for (i = 0; i < n - 1; i++) {
      max = i;
      for (j = i + 1; j < n; j++)
      if (a[j] > a[max])
      max = j;
      temp = a[i];
      a[i] = a[max];
      a[max] = temp;
   }
}
main()
{
	Queue<student>q;
	
	int num_of_stu=4;//rand()%100İŞØ ãä ÃÌá ÇáÊÌÑíÉ ÇáãØáæÈ İí ÇáÓÄÇá 
	int num_fo_itemes=rand()%200;
	cout<<"number of items in the cafateria= "<<num_fo_itemes<<endl;
	int fnoi=num_of_stu;//first number of stu
	int av_arr[num_of_stu];
	
	for(int i=0;i<num_of_stu;i++)
		{av_arr[i]=rand()%100;}
	Sort(av_arr,num_of_stu);
	for(int i=0;i<num_of_stu;i++)
	{
		int sID;string n;int ni;
		cout<<"enter student id   ";
		cin>>sID; 
		cout<<"enter name stident  ";
		cin>>n;
		ni=rand()%4;
		student s(sID,n,av_arr[i],ni);
		q.Append(s);
		cout<<endl;	
	}
 
	print(q);
	int money=0;
	int c=0;//#of student that buying any item
	while(!q.Empty()&&num_fo_itemes>0)
	{
		student stu;
		q.Retrieve(stu);
		c++;
		if(stu.average>=90)
		{
		    if(num_fo_itemes>=stu.items)
			num_fo_itemes=num_fo_itemes-stu.items;
			else
			{
				cout<<stu.Name<<" bought only"<<num_fo_itemes<<" item/s"<<endl;
				num_fo_itemes=0;
			} 
			q.Serve();
		}
		else if(stu.average>=60&&stu.average<=89)
		{
			
			if(num_fo_itemes>=stu.items)
			{
				num_fo_itemes=num_fo_itemes-stu.items;
				money=money+(stu.items-1)*10;
			}
			
			else
			{
				cout<<stu.Name<<" bought only"<<num_fo_itemes<<" item/s"<<endl;
				money=money+(num_fo_itemes-1)*10;
				num_fo_itemes=0;
			} 
			q.Serve();
		}
		else// if(stu.average>0&&stu.average<60)
		{
			if(num_fo_itemes>=stu.items)
			{
				num_fo_itemes=num_fo_itemes-stu.items;
				money=money+stu.items*10;
			}
			
			else
			{
				cout<<stu.Name<<" bought only"<<num_fo_itemes<<" item/s"<<endl;
			    money=money+(num_fo_itemes*10);
				num_fo_itemes=0;
			} 
			q.Serve();
		}
	}
	
	cout<<"the total amount of money that the cafeteria sell= "<<money<<endl;
	cout<<"the number of students that don't buying any item= "<<fnoi-c<<endl;
}