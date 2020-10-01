
#include<iostream>
using namespace std;

template <class T>
class SSLLNode //This is the node
{
	public:

		T info;
		SSLLNode *next;

		SSLLNode()
		{
			info = 0;
			next = NULL;
		}

		SSLLNode(T element, SSLLNode *nxt = 0)
		{
			info = element;
			next = nxt;
		}
};

template <class T>
class SSLList //This is the list
{
	private:

		SSLLNode <T>*head;
		SSLLNode <T>*tail;

	public:

		SSLList()
		{
			head = 0;
			tail = 0;
		}

		//ADD ELEMENT IN LIST
		void insert(T element)
		{
			SSLLNode <T>*N = new SSLLNode <T>(element);

			//IF LIST IS EMPTY
			if(head == NULL)
			{
				head = N;
				tail = N;
			}

			//IF LIST HAS ONLY ONE ELEMENT
			else if(head == tail || N->info <= head->info || N->info >= tail->info)
			{
				if(N->info <= head->info)
				{
					N->next = head;
					head = N;
				}

				else if(N->info >= tail->info)
				{
					tail->next = N;
					tail = N;
				}
			}

			//IF LIST HAS MORE THAN 1 ELEMENT
			else
			{
				SSLLNode <T>* cur = head;
				SSLLNode <T>* prev;

				while(cur->info < N->info)
				{
					prev = cur;
					cur = cur->next;
				}

				prev->next = N;
				N->next = cur;
			}
		}

		//DISPLAY THE LIST
		void traverse() //for traversing the list
		{
			SSLLNode <T>*temp = head;
			while(temp != NULL)
			{
				cout << temp->info <<" ";
				temp = temp->next;
			}
		}

		//SEARCHING AN ELEMENT IN THE LIST
		int search(int element)
		{
			//IF LIST IS EMPTY
			if(head == NULL)
				return -1;

			SSLLNode <T>*temp = head;
			int i = 1;

			while(temp != NULL)
			{
				if(temp->info > element)
					return -2;

				else if(temp->info == element)
					return i;

				temp = temp->next;
				i++;	
			}

			return -2;
		}

		//DELETE ELEMENT FROM THE LIST
		int delete(T element)
		{
			//IF LIST IS EMPTY
			if(head == NULL)
				return -1;

			SSLLNode <T>*temp = head;
			



		}
		
};

template <class X>
void func(SSLList <X> &L1, X element)
{
	int ch;

	while(1)
	{
		cout<<"\n\n ***** Main Menu *****"
			<<"\n (1) Insert an Element in List"
			<<"\n (2) Traverse"
			<<"\n (3) Searching"
			<<"\n (4) Delete"
			<<"\n (5) Exit"
			<<"\n\n Enter Choice: ";
		cin >> ch;

		while(!(ch > 0 && ch < 6))
		{
			cout<<" Invalid Input, Re-Enter : ";
			cin>>ch;
		}

		switch(ch)
		{
			case 1:	cout<<"\n Enter Element to be Added: ";
					cin>>element;
					L1.insert(element);
					cout<<"\n Element Added...";
					break;

			case 2: cout<<"\n List: ";
					L1.traverse();
					break;

			case 3: {
					cout<<"\n Enter Element to be Searched: ";
					cin>>element;
					int x = L1.search(element);

					if(x == -1)
						cout<<"\n List is Empty..";

					else if(x == -2)
						cout<<"\n Element not Present..";

					else 
						cout<<"\n Element found at "<< x <<" position";
					}

					break;

			case 4: {

					cout<<"\n Enter the element to be Deleted: ";
					cin>>element;

					int x = delete(element);

					if(x == -1)
						cout<<"\n List is Empty..";


					}
					break;

			case 5: exit(0);
		}
	}
}

int main()
{
	int ch;

	cout<<"\n\n ****** Select Datatype **********\n";
	cout<<"\n (1) INT"
		<<"\n (2) FLOAT"
		<<"\n (3) CHAR"
		<<"\n\n Enter Choice: ";

	cin>>ch;
	//INPUT VALIDATION CHECK
	while(!(ch >= 1 && ch <= 3))		
	{
		cout<<" Invalid Input, Re-Enter: ";
		cin>>ch;
	}

	if(ch == 1) 	
	{
		int element ;
		SSLList <int> L1;
		func(L1, element);	
	}
	
	else if(ch == 2)
	{
		float element;
		SSLList <float> L1;
		func(L1, element);
	}
	
	else if(ch == 3)
	{
		char element;
		SSLList <char> L1;
		func(L1, element);
	}

	return 0;
}
