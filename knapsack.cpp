#include <iostream>
#include <string>

using namespace std;

struct link
{
	int value;
	int worth;
	int weight;
	string name;
	link *link;
};

class knapsackProblem
{
private:
	link *first;

public:
	knapsackProblem();
	void show();
	void bubble();
	int solve(int weight);
	int knapS(int itW, int itV, string itN);
};
knapsackProblem::knapsackProblem()
{
	first = NULL;
}

void knapsackProblem::show()
{
	link *temp;
	int i = 0;
	temp = first;
	cout << "\nList is as follow\n";
	while (temp != NULL)
	{
		++i;
		cout << "name: " << temp->name << "\n";
		cout << "value: " << temp->value << "\n";
		cout << "weight: " << temp->weight << "\n";
		cout << "worth: " << temp->worth << "\n\n";
		temp = temp->link;
	}
	cout << "\nTotal Number of Items=" << i << endl;
}

int knapsackProblem::knapS(int itW, int itV, string itN)
{
	link *ptr, *temp;
	if (first == NULL)
	{
		first = new link;
		first->weight = itW;
		first->value = itV;
		first->name = itN;
		first->worth = itV / itW;
		first->link = NULL;
	}
	else
	{
		ptr = first;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		temp = new link;
		temp->name = itN;
		temp->weight = itW;
		temp->value = itV;
		temp->worth = itV / itW;
		temp->link = NULL;
		ptr->link = temp;
	}
}

void knapsackProblem::bubble()
{
	int count = 0, i;
	link *start = first;
	link *curr = NULL;
	link *next = NULL;
	link *temp = NULL;

	while (start != NULL)
	{
		count++;
		start = start->link;
	}
	for (i = 0; i < count; ++i)
	{
		curr = next = first;
		while (curr->link != NULL)
		{
			if (curr->worth < curr->link->worth || (curr->worth == curr->link->worth && curr->weight > curr->link->weight))
			{

				temp = curr->link;
				curr->link = curr->link->link;
				temp->link = curr;

				if (curr == first)
					first = next = temp;
				else
					next->link = temp;
				curr = temp;
			}
			next = curr;
			curr = curr->link;
		}
	}
}

int knapsackProblem::solve(int weigh)
{
	int totalWeight = 0;
	link *temp;
	int i = 0;
	temp = first;
	while ((totalWeight + temp->weight) < weigh)
	{
		++i;
		cout << "\nname: " << temp->name << "\n";
		cout << "value: " << temp->value << "\n";
		cout << "weight: " << temp->weight << "\n";
		totalWeight = totalWeight + temp->weight;
		if (temp->link == NULL)
		{
			break;
		}
		temp = temp->link;
	}
	cout << "total weight:" << totalWeight << "\n";
	cout << "\nTotal Number of Items=" << i << endl;
}

int main()
{
	int Weight, itemW, n, itemV;
	string itemN;
	knapsackProblem k;
	cout << "Enter Weight of Knapsack?\n";
	cin >> Weight;
	cout << "Enter Total Number of Items?\n";
	cin >> n;
	cout << "Enter List of Items and their respected weight?\n\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nItem no." << (i + 1) << " Name: ";
		cin >> itemN;
		cout << "\nItem Weight: ";
		cin >> itemW;
		cout << "\nItem Value: ";
		cin >> itemV;
		k.knapS(itemW, itemV, itemN);
	}
	k.show();
	cout << "\nAfter sorting\n";
	k.bubble();
	k.show();
	k.solve(Weight);
	return 1;
}
