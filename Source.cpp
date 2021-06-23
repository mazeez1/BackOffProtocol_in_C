
#include<iostream>
#include<cstdio>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm> 
#include<array>
#include <cmath>
#include <math.h>
#include<limits>
#include <fstream>  // library to generate txt file
using namespace std;

void linearFunction();
void logarithmFunction();
void exponentialFunction();

void main()
{
  cout << "\n Please wait,,,,,,,\n";
  exponentialFunction();
  cout << "\n Exponential Finished \n";
  logarithmFunction();
  cout << "\n Logarithm Finished \n";
  linearFunction();
  cout << "\n Linear Finished \n";
  cout << "\n Please See The Txt Files.\n";
  system("pause");
}
//------------------ Linear Function Definition--------------
void linearFunction()
{
	srand((unsigned)time(NULL));
	float *finalResult=new float[60];
	int size = 60;
	int finalResultIndex = 0;
	for (int N = 100; N <= 6000; N += 100)
	{
		float averageWeight = 0;
		for (int i = 0; i < 10; i++)
		{
			int wasteSlots = 0;
			int *Array = new int[N];
			int arraySize = N;
			int lastIndex = arraySize - 1;
			for (int i = 0; i < arraySize; i++)
			{
				Array[i] = rand() % 100 + 1;
			}
			int *unique = new int[arraySize];
			int uniqueIndex = 0;
			int *notUnique = new int[arraySize];
			int notUniqueIndex = 0;
			bool foo = true;
			for (int i = 0; i < arraySize; i++)
			{
				for (int j = 0; j < arraySize; j++)
				{
					if (i == j)
					{
						continue;
					}
					else if (Array[i] == Array[j])
					{
						foo = false;
					}
					else
					{
						continue;
					}

				} // inner for loop ends
				if (foo == true)
				{
					unique[uniqueIndex] = Array[i];
					uniqueIndex++;
				}
				else
				{
					foo = true;
					notUnique[notUniqueIndex] = Array[i];
					notUniqueIndex++;
				}
			} // for loop end
			 // Just generating randomizedArray of similar numbers
			double value = pow(2, notUniqueIndex) - 1;
			int *randomizedArray = new int[notUniqueIndex];
			int randomizedIndex = 0;
			for (int i = 0; i < notUniqueIndex; i++)
			{
				randomizedArray[i] = rand() % int(value);
				randomizedIndex++;
			}
			int randomizedLastIndex = randomizedIndex - 1;
			// Utilize unique numbers
			int lastUnique = uniqueIndex - 1;
			double *result = new double[lastIndex];
			int resultIndex = 0;
			int windowIncrease = 2;
			while (lastUnique >= 0)
			{
				int windowSize = windowIncrease;
				int resultCount = 0;
				while (windowSize > 0 && lastUnique >= 0)
				{
					int smallest = unique[0];
					int smallestIndex = 0;
					for (int i = 0; i <= lastUnique; i++)
					{
						if (unique[i] < smallest)
						{
							smallest = unique[i];
							smallestIndex = i;
						}
					}
					unique[smallestIndex] = unique[lastUnique];
					unique[lastUnique] = -1;
					lastUnique -= 1;
					windowSize -= 1;
					uniqueIndex -= 1;
					resultCount++;
				} // while loop ends
				result[resultIndex] = resultCount;
				resultIndex++;
				windowIncrease++;
			} // outer while loop ends
			 // working on randomized numbers 
			int currentWindow;
			int remainingCurrentWindow;
			if (resultIndex > 0)
			{
				currentWindow = windowIncrease;
				remainingCurrentWindow = currentWindow - result[resultIndex - 1] - 1;
				wasteSlots += remainingCurrentWindow;
			}
			else
			{
				currentWindow = windowIncrease;
				remainingCurrentWindow = 0;
			}
			// randomizedArray, randomizedIndex
			windowIncrease = 2;
			while (randomizedIndex > 0)
			{
				int shugal = windowIncrease;
				int innerwhile = windowIncrease;
				int outerWhile = windowIncrease;
				int windowArrayManage = randomizedIndex;
				int *randomUnique = new int[windowArrayManage];
				int *randomNotUnique = new int[windowArrayManage];
				int randomUniqueIndex = 0;
				int randomNotUniqueIndex = 0;

				int weight = 0;
				while (outerWhile > 0 && windowArrayManage > 0)
				{

					int *windowArray = new int[windowArrayManage];
					int windowIndex = 0;
					int localRandomUniqueIndex = 0;
					int localrandomNotUniqueIndex = 0;
					while (innerwhile > 0 && randomizedLastIndex >= 0)
					{
						int smallest = randomizedArray[0];
						int smallestIndex = 0;
						for (int i = 0; i <= randomizedLastIndex; i++)
						{
							if (randomizedArray[i] < smallest)
							{
								smallest = randomizedArray[i];
								smallestIndex = i;
							}
						}
						windowArray[windowIndex] = smallest;
						windowIndex++;
						randomizedArray[smallestIndex] = randomizedArray[randomizedLastIndex];
						randomizedArray[randomizedLastIndex] = -1;
						randomizedLastIndex -= 1;
						randomizedIndex--;
						innerwhile -= 1;
					} // while loop ends

					bool foo1 = true;
					for (int i = 0; i < windowIndex; i++)
					{
						for (int j = 0; j < windowIndex; j++)
						{
							if (i == j)
							{
								continue;
							}
							else if (windowArray[i] == windowArray[j])
							{
								foo1 = false;
							}
							else
							{
								continue;
							}

						} // inner for loop ends

						if (foo1 == true)
						{
							randomUnique[randomUniqueIndex] = windowArray[i];
							randomUniqueIndex++;
							localRandomUniqueIndex++;
							weight++;
						}
						else
						{
							foo1 = true;
							randomNotUnique[randomNotUniqueIndex] = windowArray[i];
							randomNotUniqueIndex++;
							localrandomNotUniqueIndex++;
						}
					} // for loop end
					if (localrandomNotUniqueIndex == 0)
					{
						currentWindow = 0;
						outerWhile = 0;
						delete[]windowArray;
						continue;
					}
					currentWindow = localrandomNotUniqueIndex;
					outerWhile = localrandomNotUniqueIndex;
					delete []windowArray;
				} // OuterWhileLoopEnd;
				bool check = false;
				if (randomNotUniqueIndex > 0)
				{
					check = true;
					double value1 = pow(2, randomNotUniqueIndex) - 1;
					for (int i = 0; i < randomNotUniqueIndex; i++)
					{
						randomizedLastIndex += 1;
						randomizedArray[randomizedLastIndex] = rand() % int(value);
						randomizedIndex++;
					}

				}
				result[resultIndex] = weight;
				resultIndex++;
				if (weight != shugal &&  randomizedIndex > 0)
				{
					wasteSlots += (shugal - weight);
				}
				weight = 0;
				if (check == false)
				{
					windowIncrease++;
				}
				else if (check == true)
				{
					windowIncrease = 2;
				}
				delete []randomUnique;
				delete[]randomNotUnique;
			}
			int total = 0;
			// Resulting window is ";
			for (int i = 0; i < resultIndex; i++)
			{
				total += result[i];
			}
			averageWeight += resultIndex;
			delete[]Array;
			delete[]unique;
			delete[]notUnique;
			delete[]result;
			delete[]randomizedArray;
		}
	finalResult[finalResultIndex] = averageWeight/10;
	finalResultIndex++;
   
 } // end N loop

   // Writing in File

 ofstream fout;
 float line;
 int arrayIndex = 0;
 fout.open("Linear.txt");

 //Execute a loop If file successfully opened 
 while (fout) {
	 line = finalResult[arrayIndex];
	 arrayIndex += 1;
	 fout << line << endl;
	 if (arrayIndex == size)
		 break;
 }
 // Close the File 
 fout.close();
 delete []finalResult;
  size = 0;
}
//------------------ Logarithm Function Definition--------------
void logarithmFunction()
{

	srand((unsigned)time(NULL));
	float *finalResult=new float[60];
	int size = 60;
	int finalResultIndex = 0;
	for (int N = 100; N <= 6000; N += 100)
	{
		float averageWeight = 0;
		for (int i = 0; i < 10; i++)
		{
			int wasteSlots = 0;
			int *Array = new int[N];
			int arraySize = N;

			int lastIndex = arraySize - 1;
			for (int i = 0; i < arraySize; i++)
			{
				Array[i] = rand() % 100 + 1;
			}

			int *unique = new int[arraySize];
			int uniqueIndex = 0;
			int *notUnique = new int[arraySize];
			int notUniqueIndex = 0;
			bool foo = true;
			for (int i = 0; i < arraySize; i++)
			{
				for (int j = 0; j < arraySize; j++)
				{
					if (i == j)
					{
						continue;
					}
					else if (Array[i] == Array[j])
					{
						foo = false;
					}
					else
					{
						continue;
					}

				} // inner for loop ends
				if (foo == true)
				{
					unique[uniqueIndex] = Array[i];
					uniqueIndex++;
				}
				else
				{
					foo = true;
					notUnique[notUniqueIndex] = Array[i];
					notUniqueIndex++;
				}
			} // for loop end
			  // Just generating randomizedArray of similar numbers
			double value = pow(2, notUniqueIndex) - 1;
			int *randomizedArray = new int[notUniqueIndex];
			int randomizedIndex = 0;
			for (int i = 0; i < notUniqueIndex; i++)
			{
				randomizedArray[i] = rand() % int(value);
				randomizedIndex++;
			}
			int randomizedLastIndex = randomizedIndex - 1;
			// Utilize unique numbers
			int lastUnique = uniqueIndex - 1;
			int *result = new int[lastIndex];
			int resultIndex = 0;
			int windowIncrease = 2;
			int temp = 2;
			while (lastUnique >= 0)
			{
				int windowSize = windowIncrease;
				int resultCount = 0;
				while (windowSize > 0 && lastUnique >= 0)
				{
					int smallest = unique[0];
					int smallestIndex = 0;
					for (int i = 0; i <= lastUnique; i++)
					{
						if (unique[i] < smallest)
						{
							smallest = unique[i];
							smallestIndex = i;
						}
					}
					unique[smallestIndex] = unique[lastUnique];
					unique[lastUnique] = -1;
					lastUnique -= 1;
					windowSize -= 1;
					uniqueIndex -= 1;
					resultCount++;
				} // while loop ends
				result[resultIndex] = resultCount;
				resultIndex++;
				temp = windowIncrease;
				windowIncrease = floor((1 + (1 / (log(windowIncrease) / log(2))))*windowIncrease);
			} // outer while loop ends
			// working on randomized numbers 
			int currentWindow;
			int remainingCurrentWindow;
			if (resultIndex > 0)
			{
				currentWindow = temp;
				remainingCurrentWindow = currentWindow - result[resultIndex - 1];
				wasteSlots += remainingCurrentWindow;
			}
			else
			{
				currentWindow = windowIncrease;
				remainingCurrentWindow = 0;
			}
			// randomizedArray, randomizedIndex
			windowIncrease = 2;
			while (randomizedIndex > 0)
			{
				int shugal = windowIncrease;
				int innerwhile = windowIncrease;
				int outerWhile = windowIncrease;
				int windowArrayManage = randomizedIndex;
				int *randomUnique = new int[windowArrayManage];
				int *randomNotUnique = new int[windowArrayManage];
				int randomUniqueIndex = 0;
				int randomNotUniqueIndex = 0;

				int weight = 0;
				while (outerWhile > 0 && windowArrayManage > 0)
				{
					int *windowArray = new int[windowArrayManage];
					int windowIndex = 0;
					int localRandomUniqueIndex = 0;
					int localrandomNotUniqueIndex = 0;
					while (innerwhile > 0 && randomizedLastIndex >= 0)
					{
						int smallest = randomizedArray[0];
						int smallestIndex = 0;
						for (int i = 0; i <= randomizedLastIndex; i++)
						{
							if (randomizedArray[i] < smallest)
							{
								smallest = randomizedArray[i];
								smallestIndex = i;
							}
						}
						windowArray[windowIndex] = smallest;
						windowIndex++;
						randomizedArray[smallestIndex] = randomizedArray[randomizedLastIndex];
						randomizedArray[randomizedLastIndex] = -1;
						randomizedLastIndex -= 1;
						randomizedIndex--;
						innerwhile -= 1;
						//cout << "\n WindowSize While Loop\n";
					} // while loop ends

					bool foo1 = true;
					for (int i = 0; i < windowIndex; i++)
					{
						for (int j = 0; j < windowIndex; j++)
						{
							if (i == j)
							{
								continue;
							}
							else if (windowArray[i] == windowArray[j])
							{
								foo1 = false;
							}
							else
							{
								continue;
							}

						} // inner for loop ends

						if (foo1 == true)
						{
							randomUnique[randomUniqueIndex] = windowArray[i];
							randomUniqueIndex++;
							localRandomUniqueIndex++;
							weight++;
						}
						else
						{
							foo1 = true;
							randomNotUnique[randomNotUniqueIndex] = windowArray[i];
							randomNotUniqueIndex++;
							localrandomNotUniqueIndex++;
						}
					} // for loop end
					if (localrandomNotUniqueIndex == 0)
					{
						currentWindow = 0;
						outerWhile = 0;
						delete[]windowArray;
						continue;
					}
					currentWindow = localrandomNotUniqueIndex;
					outerWhile = localrandomNotUniqueIndex;
					delete[]windowArray;
				} // OuterWhileLoopEnd;
				bool check = false;
				if (randomNotUniqueIndex > 0)
				{
					check = true;
					double value1 = pow(2, randomNotUniqueIndex) - 1;
					for (int i = 0; i < randomNotUniqueIndex; i++)
					{
						randomizedLastIndex += 1;
						randomizedArray[randomizedLastIndex] = rand() % int(value);
						randomizedIndex++;
					}

				}

				result[resultIndex] = weight;
				resultIndex++;
				if (weight != shugal && randomizedIndex > 0)
				{
					wasteSlots += (shugal - weight);
				}
				weight = 0;
				if (check == false)
				{
					windowIncrease = floor((1 + (1 / (log(windowIncrease) / log(2))))*windowIncrease);
				}
				else if (check == true)
				{
					windowIncrease = 2;
				}
				delete[]randomUnique;
				delete[]randomNotUnique;
			}
			int total = 0;
			// Resulting window ;
			for (int i = 0; i < resultIndex; i++)
			{
				total += result[i];
			}
			averageWeight += resultIndex;
			delete[]Array;
			delete[]unique;
			delete[]notUnique;
			delete[]result;
			delete[]randomizedArray;
		}

			  finalResult[finalResultIndex] = averageWeight/10;
			  finalResultIndex++;
  } // end N loop

// Writing in the file
	ofstream fout;
	float line;
	int arrayIndex = 0;
	fout.open("Logarithm.txt");

	//Execute a loop If file successfully opened 
	while (fout) {
		line = finalResult[arrayIndex];
		arrayIndex += 1;
		fout << line << endl;
		if (arrayIndex == size)
			break;
	}
	// Close the File 
	fout.close();
	delete[]finalResult;
	size = 0;
}
//------------------ Exponential Function Definition--------------
void exponentialFunction()
{
	srand((unsigned)time(NULL));
    float *finalResult=new float[60];
	int size = 60;
	int finalIndex = 0;
	for (int N = 100; N <= 6000; N += 100)
	{
		float averageWeight = 0;
		for (int i = 0; i < 10; i++)
		{

			int wasteSlots = 0;
			int *Array = new int[N];
			int arraySize = N;

			int lastIndex = arraySize - 1;
			for (int i = 0; i < arraySize; i++)
			{
				Array[i] = rand() % 100 + 1;
			}
			int *unique = new int[arraySize];
			int uniqueIndex = 0;
			int *notUnique = new int[arraySize];
			int notUniqueIndex = 0;
			bool foo = true;
			for (int i = 0; i < arraySize; i++)
			{
				for (int j = 0; j < arraySize; j++)
				{
					if (i == j)
					{
						continue;
					}
					else if (Array[i] == Array[j])
					{
						foo = false;
					}
					else
					{
						continue;
					}

				} // inner for loop ends
				if (foo == true)
				{
					unique[uniqueIndex] = Array[i];
					uniqueIndex++;
				}
				else
				{
					foo = true;
					notUnique[notUniqueIndex] = Array[i];
					notUniqueIndex++;
				}
			} // for loop end

			  // Just generating randomizedArray of similar numbers
			double value = pow(2, notUniqueIndex) - 1;
			int *randomizedArray = new int[notUniqueIndex];
			int randomizedIndex = 0;
			// Randomized Array is ";
			for (int i = 0; i < notUniqueIndex; i++)
			{
				randomizedArray[i] = rand() % int(value);
				randomizedIndex++;
			}
			int randomizedLastIndex = randomizedIndex - 1;
			// Utilize unique numbers

			int lastUnique = uniqueIndex - 1;
			int *result = new int[lastIndex];
			int resultIndex = 0;
			int windowIncrease = 2;
			int windowIncreaseControl = 1;
			windowIncrease = pow(2, windowIncreaseControl);
			while (lastUnique >= 0)
			{
				int windowSize = windowIncrease;
				int resultCount = 0;
				while (windowSize > 0 && lastUnique >= 0)
				{
					int smallest = unique[0];
					int smallestIndex = 0;
					for (int i = 0; i <= lastUnique; i++)
					{
						if (unique[i] < smallest)
						{
							smallest = unique[i];
							smallestIndex = i;
						}
					}
					unique[smallestIndex] = unique[lastUnique];
					unique[lastUnique] = -1;
					lastUnique -= 1;
					windowSize -= 1;
					uniqueIndex -= 1;
					resultCount++;
				} // while loop ends
				result[resultIndex] = resultCount;
				resultIndex++;
				windowIncreaseControl += 1;
				windowIncrease = pow(2, windowIncreaseControl);

			} // outer while loop ends
			// working on randomized numbers 
			int currentWindow;
			int remainingCurrentWindow;
			if (resultIndex > 0 && randomizedIndex >= 0)
			{
				windowIncreaseControl -= 1;
				windowIncrease = pow(2, windowIncreaseControl);
				currentWindow = windowIncrease;
				remainingCurrentWindow = currentWindow - result[resultIndex - 1];
				wasteSlots += remainingCurrentWindow;
				windowIncreaseControl += 1;
				windowIncrease = pow(2, windowIncreaseControl);
			}
			else
			{
				currentWindow = windowIncrease;
				remainingCurrentWindow = 0;
			}
			// Use randomizedArray and randomizedIndex
			windowIncrease = 2;
			windowIncreaseControl = 1;
			while (randomizedIndex > 0)
			{
				int shugal = windowIncrease;
				int innerwhile = windowIncrease;
				int outerWhile = windowIncrease;
				int windowArrayManage = randomizedIndex;
				int *randomUnique = new int[windowArrayManage];
				int *randomNotUnique = new int[windowArrayManage];
				int randomUniqueIndex = 0;
				int randomNotUniqueIndex = 0;

				int weight = 0;
				while (outerWhile > 0 && windowArrayManage > 0)
				{

					int *windowArray = new int[windowArrayManage];
					int windowIndex = 0;
					int localRandomUniqueIndex = 0;
					int localrandomNotUniqueIndex = 0;
					while (innerwhile > 0 && randomizedLastIndex >= 0)
					{
						int smallest = randomizedArray[0];
						int smallestIndex = 0;
						for (int i = 0; i <= randomizedLastIndex; i++)
						{
							if (randomizedArray[i] < smallest)
							{
								smallest = randomizedArray[i];
								smallestIndex = i;
							}
						}
						windowArray[windowIndex] = smallest;
						windowIndex++;
						randomizedArray[smallestIndex] = randomizedArray[randomizedLastIndex];
						randomizedArray[randomizedLastIndex] = -1;
						randomizedLastIndex -= 1;
						randomizedIndex--;
						innerwhile -= 1;
					} // while loop ends
					bool foo1 = true;
					for (int i = 0; i < windowIndex; i++)
					{
						for (int j = 0; j < windowIndex; j++)
						{
							if (i == j)
							{
								continue;
							}
							else if (windowArray[i] == windowArray[j])
							{
								foo1 = false;
							}
							else
							{
								continue;
							}

						} // inner for loop ends

						if (foo1 == true)
						{
							randomUnique[randomUniqueIndex] = windowArray[i];
							randomUniqueIndex++;
							localRandomUniqueIndex++;
							weight++;
						}
						else
						{
							foo1 = true;
							randomNotUnique[randomNotUniqueIndex] = windowArray[i];
							randomNotUniqueIndex++;
							localrandomNotUniqueIndex++;
						}
					} // for loop end
					if (localrandomNotUniqueIndex == 0)
					{
						currentWindow = 0;
						outerWhile = 0;
						delete[]windowArray;
						continue;
					}
					currentWindow = localrandomNotUniqueIndex;
					outerWhile = localrandomNotUniqueIndex;
					delete[]windowArray;
				} // OuterWhileLoopEnd;

				//---------------------
				bool check = false;
				if (randomNotUniqueIndex > 0)
				{
					check = true;
					double value1 = pow(2, randomNotUniqueIndex) - 1;
					for (int i = 0; i < randomNotUniqueIndex; i++)
					{
						randomizedLastIndex += 1;
						randomizedArray[randomizedLastIndex] = rand() % int(value);
						randomizedIndex++;
					}

				}

				//---------------------
				result[resultIndex] = weight;
				resultIndex++;
				if (weight != shugal && randomizedIndex > 0)
				{
					wasteSlots += (shugal - weight);
				}
				weight = 0;
				if (check == false)
				{
					windowIncreaseControl += 1;
					windowIncrease = pow(2, windowIncreaseControl);
				}
				else if (check == true)
				{
					windowIncrease = 2;
					windowIncreaseControl = 1;
				}
				delete[]randomUnique;
				delete[]randomNotUnique;

			}
			int total = 0;
			// Resulting window is ";
			for (int i = 0; i < resultIndex; i++)
			{
				total += result[i];
			}
			averageWeight += resultIndex;

			delete[]Array;
			delete[]unique;
			delete[]notUnique;
			delete[]result;
			delete[]randomizedArray;

		}
		finalResult[finalIndex] = averageWeight/10;
		finalIndex++;
} // end N loop
// Writing in File
 
  ofstream fout;
   float line;
   int arrayIndex = 0;
   fout.open("Exponential.txt");

//Execute a loop If file successfully opened 
   while (fout) {
	line = finalResult[arrayIndex];
	arrayIndex += 1;
	fout << line << endl;
	if (arrayIndex == size)
		break;
   }
// Close the File 
   fout.close();
   delete[]finalResult;
   size = 0;
}
