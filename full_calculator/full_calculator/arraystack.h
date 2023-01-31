#ifndef STACK_H
#define STACK_H

using namespace std;


template <class T>
class stack
{
	private:
		T* data;
		int top;
		int size;
		void resize() {
			T* newdata = new T(2 * size);
			for (int i = 0; i < size; i++)
				newdata[i] = data[i];
			data = newdata;
			size *= 2;
		}
		bool needToResize() {
			return(top == size);
		}

	public:
	stack()
	{
		size = 5;
		data = new T[size];
		top = 0;
    }

	void push(T item) {
		if (needToResize())
			resize();

		data[top] = item;
		top++;
	}
	T peek() {
		if (top <= 0)
			cout << "stack is empty" << endl;
		else 
		return data[top - 1];
	}
	T pop() {
		if (top <= 0)
			cout << "stack is empty" << endl;
		top--;
		return data[top];
	}
	bool isEmpty() {
		return (top == 0);

	}

};
#endif
