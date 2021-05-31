#pragma once
namespace reno_ds 
{
	class Queue
	{
	private:
		struct node 
		{
			int data;
			node* next;
		};
		node* front;
		node* back;
		int size;

	public:
		Queue();
		int getSize();
		void enqueue(int value);
		int dequeue();
		void show();
	};
}