#include <iostream>
#include "ArrList.hpp"
#include <random>
using namespace std;

// Konstruktor klasy ArrList
ArrList::ArrList(int capacity) : capacity(capacity), size(0) {
	array = new Node[capacity];
}


// Destruktor klasy ArrList
ArrList::~ArrList()
{
	delete[] array;
}

ArrList::ArrList(const ArrList& other) : capacity(other.capacity), size(other.size) {
	array = new Node[capacity];
	for (int i = 0; i < size; ++i) {
		array[i].data = other.array[i].data;
		array[i].priority = other.array[i].priority;
	}
}

ArrList& ArrList::operator=(const ArrList& other) {
	if (this != &other) {
		delete[] array;

		capacity = other.capacity;
		size = other.size;

		array = new Node[capacity];
		for (int i = 0; i < size; ++i) {
			array[i].data = other.array[i].data;
			array[i].priority = other.array[i].priority;
		}
	}
	return *this;
}


//Metoda do dodania nowego elementu o okreslonym priorytecie
void ArrList::insert(int data, int priority)
{
	if (size == capacity)
	{
		cout << "Kolejka jest pe�na" << endl;
		return;
	}

	int index = size;
	size++;
	array[index].data = data;
	array[index].priority = priority;


	//Naprawa kolejnosci po wstawieniu
	while (index > 0 and array[index].priority > array[index - 1].priority)
	{
		swap(array[index], array[index - 1]);
		index--;
	}
}

//Metoda do usuwania i zwracania elementu o najwyzszym priorytecie
int ArrList::extractMax()
{
	if (size == 0) {
		cout << "Kolejka jest pusta" << endl;
		exit(1);;
	}

	int maxData = array[0].data;

	// Przesuwanie tablicy w lewo
	for (int i = 1; i < size; i++) {
		array[i - 1].data = array[i].data;
	}
	size--;

	return maxData;
}




//Metoda do zwracania elementu o najwiekszym priorytecie
int ArrList::peek()
{
	if (size == 0)
	{
		cout << "Kolejka jest pusta" << endl;
		return(-1);
	}
	return array[0].data;
}

//Metoda do zmiany priorytetu
void ArrList::modifyKey(int data, int newPriority) {
	for (int i = 0; i < size; i++) {
		if (array[i].data == data) {
			int oldPriority = array[i].priority;
			array[i].priority = newPriority;

			// Naprawa kolejnosci w kolejce po zmianie priorytetu
			if (newPriority > oldPriority) {
				int index = i;
				while (index > 0 && array[index].priority > array[(index - 1) / 2].priority) {
					swap(array[index], array[(index - 1) / 2]);
					index = (index - 1) / 2;
				}
			}
			else if (newPriority < oldPriority) {
				int index = i;
				while (index < size - 1 && array[index].priority < array[index + 1].priority) {
					swap(array[index], array[index + 1]);
					index++;
				}
			}
			return;
		}
	}
	cout << "Nie znaleziono podanej wartosci." << endl;
}

//Metoda zwracajaca wielkosc kolejki
int ArrList::getSize()
{
	return size;
}

void ArrList::generateRandomNumbers(int count)
{
	// Inicjalizacja generatora liczb losowych
	mt19937 rng(time(nullptr));
	uniform_int_distribution<int> distribution(1, 100); // Zakres priorytetow

	// Generowanie danych i dodawanie ich do struktury
	for (int i = 0; i < count; ++i) {
		int data = rng() % 1000000 + 1; // Generowanie losowej liczby z zakresu 1-1000000
		int priority = distribution(rng); // Losowy priorytet z zakresu 1-100
		insert(data, priority); // Wstawienie danych do struktury (wywolanie metody insert klasy ArrList)
	}
}
