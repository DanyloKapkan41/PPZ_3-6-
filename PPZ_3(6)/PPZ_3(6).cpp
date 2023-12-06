#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};
void add(Node*& head, int N, int j)
{
	if (N > j)
	{
		int n;
		n = rand() % 10;
		if (n == 0 && j == 0)
		{
			add(head, N, j);
		}
		else
		{
			Node* cur = new Node(n);
			head->next = cur;
			j++;
			add(cur, N, j);
		}
	}

}
void add(Node*& head, int o)
{
	Node* cur = new Node(o);
	cur->next = head;
	head = cur;
}
void show(Node* head)
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
void deleteList(Node* head)
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
void checking(Node*& head, int N)
{
	int* arr = new int[N];
	int count = 0, i = 0;
	int m = 0;
	Node* current = head;
	for (i = 0; i < N; i++) {
		arr[i] = current->data;
		current = current->next;
	}
	deleteList(head);
	head = nullptr;
	for (i; i > 0; i--)
	{
		m += pow(10, i - 1) * arr[N - i];
	}
	m = m * 2;
	i = 0;
	delete[] arr;
	arr = new int[N + 1];
	while (m != 0) {
		arr[i] = m % 10;
		m /= 10;
		i++;
		count++;
	}
	for (i = 0; i < count; i++)
	{
		add(head, arr[i]);
	}
	show(head);
}
int main()
{
	int N = -1;
	Node* head = new Node(1);
	srand(time(NULL));
	do {
		cout << "Count of elements (1 < N < 10000): ";
		cin >> N;
	} while (N > 10000 || N < 1);
	add(head, N, 0);
	head = head->next;
	show(head);
	checking(head, N);
	deleteList(head);
	return 0;
}