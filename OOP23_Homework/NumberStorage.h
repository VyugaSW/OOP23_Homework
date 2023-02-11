#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

namespace storage
{

	class NumberStorage
	{
		int* storage;
		int elementsCount;
		static int usedMemory;

	public:
		NumberStorage(int elementsCountP) :
			storage{ new int[elementsCountP] },
			elementsCount{ elementsCountP }
		{
			uint32_t used{ elementsCount * sizeof(int) };
			usedMemory += used;

			cout << "NumberStorage: additional " << used
				<< " bytes used. Total: " << usedMemory << endl;

			for (int i{ 0 }; i < elementsCount; i++) {
				storage[i] = rand() % 10;
			}
		};

		void print() {
			cout << endl;
			for (int i = 0; i < elementsCount; i++) {
				cout << storage[i] << " ";
			}
			cout << endl;
		}

		static int getUsedMemory() {
			return usedMemory;
		}

		~NumberStorage() {
			uint32_t freed{ elementsCount * sizeof(int) };
			delete[]storage;
			usedMemory -= freed;
			cout << "NumberStorage: freed " << freed
				<< " bytes. Total: " << usedMemory << endl;
		}


	};



	int NumberStorage::usedMemory = 0;

}
