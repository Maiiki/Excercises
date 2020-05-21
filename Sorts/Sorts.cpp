#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bubbleSort(vector<int> &vInt);
vector<int> quickSort(vector<int> vInt);
vector<int> mergeSort(vector<int> vInt);
vector<int> merge(vector<int>leftV, vector<int>rightV);
void printVector(vector<int> vInt);
void fillVector(vector<int> &vInt, int numElements);

int main()
{
	/*///////////////////////////////*/
	/*----------Bubble Sort----------*/
	/*///////////////////////////////*/
	vector<int>vNumsBubble;
	fillVector(vNumsBubble, 100);
	
	cout << "Pre-order:" << endl;
	printVector(vNumsBubble);

	bubbleSort(vNumsBubble);

	cout << "Bubble Sort:" << endl;
	printVector(vNumsBubble);

	/*//////////////////////////////*/
	/*----------Quick Sort----------*/
	/*//////////////////////////////*/

	/*//////////////////////////////*/
	/*----------Merge Sort----------*/
	/*//////////////////////////////*/
	vector<int>vNumsMerge;
	fillVector(vNumsMerge, 20);

	cout << "Pre-order:" << endl;
	
	printVector(vNumsMerge);
	vNumsMerge = mergeSort(vNumsMerge);
	
	cout << "Merge Sort:" << endl;
	printVector(vNumsMerge);

	cin.get();
}

void bubbleSort(vector<int> &vInt)
{
	//Compruebo si la lista es mayor a 1.
	if (vInt.size() > 1)
	{
		int iTmp = 0;
		bool isChanging = true;

		//El loop continuara hasta que la lista deje de cambiar, es decir, este ordenada.
		while (isChanging)
		{
			int moves = 0;
			for (size_t i = 0; i < vInt.size() - 1; i++)
			{
				//Si el valor actual es mayor al siguiente en la lista los intercambio.
				if (vInt[i] > vInt[i + 1])
				{
					iTmp = vInt[i];
					vInt[i] = vInt[i + 1];
					vInt[i + 1] = iTmp;
					moves++;
				}
			}
			//Si no hubo cambios en este recorrido el loop termina
			if (moves == 0) { isChanging = false; }
		}
	}
	
}

vector<int> quickSort(vector<int> vInt)
{
}

vector<int> mergeSort(vector<int> vInt)
{
	vector<int>left, right, final;
	if (vInt.size() <= 1) { return vInt; }
	else
	{
		int mid = vInt.size() / 2;
		for (size_t i = 0; i <= mid-1; i++)
		{
			left.push_back(vInt[i]);
		}
		
		for (size_t i = mid; i < vInt.size(); i++)
		{
			right.push_back(vInt[i]);
		}
		
		left = mergeSort(left);
		right = mergeSort(right);
		
		if (left.back() <= right.front())
		{
			left.insert(left.end(), right.begin(), right.end());
			return left;
		}

		final = merge(left, right);
		return final;
	}
}

vector<int> merge(vector<int>leftV, vector<int>rightV)
{
	vector<int>final;
	while (leftV.size() > 0 && rightV.size() > 0)
	{
		if (leftV.front() <= rightV.front())
		{
			final.push_back(leftV.front());
			leftV.erase(leftV.begin());
		}
		else
		{
			final.push_back(rightV.front());
			rightV.erase(rightV.begin());
		}
	}

	if (leftV.size() > 0)
	{
		final.insert(final.end(), leftV.begin(), leftV.end());
	}

	if (rightV.size() > 0)
	{
		final.insert(final.end(), rightV.begin(), rightV.end());
	}

	return final;
}

void printVector(vector<int> vInt)
{
	for (size_t i = 0; i < vInt.size(); i++)
	{
		cout << vInt[i];
		if (i < vInt.size() - 1) { cout << ", "; }
		else { cout << endl << endl; }
	}
}

void fillVector(vector<int>& vInt, int numElements)
{
	srand(time(NULL));

	for (size_t i = 0; i < numElements; i++)
	{
		vInt.push_back(rand() % 1000);
	}
}