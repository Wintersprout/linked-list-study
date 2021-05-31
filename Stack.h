#pragma once
#include <iostream>

namespace reno_ds
{
	class Stack
	{
	private:
		struct node
		{
			int data;
			node* next;
		};
		node* top;
		int size;

	public:
		Stack();
		int getSize();
		void push(int value);
		int pop();
		void show();
	};
}