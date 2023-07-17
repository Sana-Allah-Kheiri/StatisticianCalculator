// StatisticianCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;
#define LOG cout<<'\n'<<
#define GET cin>>

std::string rankfix(int i) {
	std::string post = "th";
 if(i>9){                          
	int rightDigit = (i % 10);
	
	switch (rightDigit) {
	case(1): post = "st"; break;
	case(2): post = "nd"; break;
	case(3): post = "rd"; break;
	}
	}
	else {
	 switch (i) {
	 case(1): post = "st"; break;
	 case(2): post = "nd"; break;
	 case(3): post = "rd"; break;
	 }


	}
	return post;
}

double maxInArray(double* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return(max);
}

bool areSame(double* arr, int n) {
	int count{};
	int first = arr[count];
	for (int i = 1; i < n; i++){          
		if (arr[i] != first) return false;
	}
	return true;
}

float findMode(double* arr, int n) {
	// Sort the array 
	sort(arr, arr + n);

	//finding max frequency  
	int max_count = 1, res = arr[0], count = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])
			count++;
		else {
			if (count > max_count) {
				max_count = count;
				res = arr[i - 1];
			}
			count = 1;
		}
	}
	// when the last element is most frequent 
	if (count > max_count)
	{
		max_count = count;
		res = arr[n - 1];
	}

	return res;
}




int main()
{
	system("COLOR 71");
	long n{}; //n is number of data
	double sum{}; // sum of all entries
	double product{ 1.0 }; // product of all entries: i1 * i2 * ... * in
	double sumOfInverses{};
	double q1{}, q2{}, q3{};

	LOG "How many numeric data do you want to enter?"; // getting number of data from user
	GET n;

	double* numList = new double[n] {}; // definning array for storing numeric data


	for (int i = 0; i < n; i++) { // getting data from user
		LOG "Enter the " << i + 1 << rankfix(i+1) << " number: ";
		GET numList[i];
		sum += numList[i];
		sumOfInverses += double(1 / numList[i]);
		product *= numList[i];
	}

sort(numList, numList + n); // sorting list ascendingly
	
  LOG "Sorted List of data: ";
	for (short i = 0; i < n; i++) {
		cout << numList[i]<<", ";
	}




	LOG "*******************************";
	LOG " Central Tendency Parameters : ";
	double mean = double(sum / n);
	LOG " Arthimetic Mean = " << mean;
	LOG " Geometric Mean = " << pow(product, (1.0 / double(n)));
	LOG " Harmonic Mean = " << double(n / sumOfInverses);
	
	// calculating Q2 (Median) :
	if (n % 2 == 0) {
		q2 = double((numList[int(n / 2)-1] + numList[int((n / 2) + 1)-1]) / 2);
	}
	if (n % 2 == 1) {
		q2 = numList[int(floor(n / 2))];
	}
	LOG " Q2(Median) = " << q2;
	if(areSame(numList,n)==false) {              
	LOG " Mode = " << findMode(numList, n);
	}
	else {
		LOG " This data set has no mode! ";
	}

	LOG " **********************";
	LOG " Dispersion Parameters ";
	LOG " Range = " << numList[n - 1] - numList[0];
	// calculating Q1 :
	double indexOfQ1 = double((n + 1.0) / 4.0);
	if (floor(indexOfQ1) == indexOfQ1) {

		LOG " Q1 (1st quartile) = " << numList[int(indexOfQ1)];
	}
	else {

		int before = floor(indexOfQ1);
		int after = before + 1;

		q1 = double((numList[before - 1] + numList[after - 1]) / double(2.0));

		LOG " Q1 (1st quartile) = " << q1;
	}

	// calculating Q3 :
	double indexOfQ3 = double((3.0 * (n + 1.0)) / 4.0);
	if (floor(indexOfQ3) == indexOfQ3) {

		LOG " Q3 (3rd quartile) = " << numList[int(indexOfQ3)];
	}
	else {

		int before = floor(indexOfQ3);
		int after = before + 1;

		q3 = double((numList[before - 1] + numList[after - 1]) / double(2.0));

		LOG " Q3 (3rd/Upper quartile) = " << q3;
	}
	LOG " Interquartile Range(IQR) = " << q3 - q1;

	// calculating variance
	double var{}, vSum{};
	for (int i = 0; i < n; i++) {
		vSum += pow((numList[i] - mean), 2);
	}

	var = double(vSum / double(n)); // variance

	double sd = sqrt(var);
	LOG " Variance = " << var;
	LOG " Standard Deviation = " << sd;
	LOG "***************************";


	
	








}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
