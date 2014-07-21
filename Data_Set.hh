#ifndef DATA_SET_H
#define DATA_SET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

/*******************************************************************************
                                Class: Data_Set

This class is used for analysing data sets.

The class can:
1) intake an arbitrary sized data set.
   - from a file.
   - from the user when the class is used in a program.
2) calculate the mean of the data set.
3) calculate the median of the data set.
4) calculate the mode of the data set.
5) calculate the range of the data set. 
6) calculate the random error/uncertainty in the data set. 
7) define a subset data set, based on a range of values defined by the user, from the initial input data which can be used within the class. 
*******************************************************************************/

class Data_Set {
private:
  int Rows, Columns;
public:

  Data_Set() {};
  Data_Set(int a, int b) : Columns(a), Rows(b) {};

  double** Input_Data_Set(string Input_Type) {
    int Iterator = 0;
    double Element_1 = 0, Element_2 = 0, Element_3 = 0, Element_4 = 0;
    double** Data_Array = Dynamic_Array(Columns, Rows);
    double** Set_of_Data = Set_Array(Data_Array, Columns, Rows, 0);
    
    if ((Input_Type == "File") ||
	(Input_Type == "file") ||
	(Input_Type == "FILE"))
      {
	string Line;

	ifstream Data;
	Data.open("Data.txt");
	while (getline(Data, Line))
	  {
	    stringstream ss(Line);
	    if (ss >> Element_1)
	      {
		Set_of_Data [0][Iterator] = Element_1;
		Set_of_Data [1][Iterator] = 0;
		Iterator++;
	      }
	    else if (ss >> Element_1 >> Element_2)
	      {
		Set_of_Data [0][Iterator] = Element_1;
		Set_of_Data [1][Iterator] = Element_2;
		Set_of_Data [2][Iterator] = 0;
		Iterator++;
	      }
	    else if (ss >> Element_1 >> Element_2 >> Element_3)
	      {
		Set_of_Data [0][Iterator] = Element_1;
		Set_of_Data [1][Iterator] = Element_2;
		Set_of_Data [2][Iterator] = Element_3;
		Set_of_Data [3][Iterator] = 0;
		Iterator++;
	      }
	    else if (ss >> Element_1 >> Element_2 >> Element_3 >> Element_4)
	      {
		Set_of_Data [0][Iterator] = Element_1;
		Set_of_Data [1][Iterator] = Element_2;
		Set_of_Data [2][Iterator] = Element_3;
		Set_of_Data [3][Iterator] = Element_4;
		Set_of_Data [4][Iterator] = 0;
		Iterator++;
	      }
	    else 
	      {
		cout << "ERROR: The data file cannot be used." << endl; 
	      }
	  }
      }

    else if ((Input_Type == "Manual") ||
	     (Input_Type == "manual") ||
	     (Input_Type == "MANUAL"))
      {
	double Data_Value = 0;
	for (int Column_Number = 0; Column_Number < (Columns); Column_Number++)
	  {
	    for (int Row_Number = 0; Row_Number < Rows; Row_Number++)
	      {
		cout << "State the data value you wish to be input into element " << Column_Number << Row_Number << ": ";
		cin >> Data_Value;
		Set_of_Data [Column_Number][Row_Number] = Data_Value;
	      }
	  }
      }

    else
      {
	cout << "ERROR: The input type (" << Input_Type << ") for the data set is not valid." << endl;
	cout << "Input methods for the data set are:" << endl;
	cout << "1) Text file input." << endl;
	cout << "   - File, file, FILE." << endl;
	cout << "2) Input data manually." << endl;
	cout << "   - Manual, manual, MANUAL." << endl;
      }
    return Set_of_Data;
 }


  double** Dynamic_Array(int Number_of_Columns, int Number_of_Rows) {
    double** Array = new double* [Number_of_Columns];
    for (int Iterator = 0; Iterator <= Number_of_Columns; Iterator++)
      {
	Array [Iterator] = new double [Number_of_Rows];
      }
    return Array;
  }

  double** Set_Array(double** Array, int Number_of_Columns, int Number_of_Rows, double Set_Value) {
    for (int Column_Iterator = 0; Column_Iterator <= Number_of_Columns; Column_Iterator++)
      {
	for (int Row_Iterator = 0; Row_Iterator < Number_of_Rows; Row_Iterator++)
	  {
	    Array [Column_Iterator][Row_Iterator] = Set_Value;
	  }
      }
    return Array;
  }

  // Calculates the mean of a data set.
  double Mean(double** Set_of_Data, int Column_Number) {
    int Number_of_Values = 0;
    double Total_Sum = 0;
    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	Total_Sum += Set_of_Data [Column_Number][Row_Iterator];
	Number_of_Values++;
      }
    return Total_Sum/Number_of_Values;
  }

  // Calculates the median of a data set.
  double Median(double** Set_of_Data, int Column_Number) {
    int Row_Number = 0;
    double Value = 0, Minimum_Value = 0, Median_Value = 0, Sum = 0;

    double** Ordered_Data_Set = Dynamic_Array(1, Rows);

    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	Value = Set_of_Data [Column_Number][Row_Iterator];
	Sum += Value;
      }

    for (int Number_of_Iterations = 0; Number_of_Iterations < Rows; Number_of_Iterations++)
      {
	Minimum_Value = Sum;  
	for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
	  {
	    Value = Set_of_Data [Column_Number][Row_Iterator];
	    if ((Value < Minimum_Value) &&
		(Set_of_Data [Columns][Row_Iterator] == 0))
	      {
		Ordered_Data_Set [Column_Number][Number_of_Iterations] = Value;
		Minimum_Value = Value;
	      }
	    if (Row_Iterator == (Rows - 1))
	      {
		for (int Iterator = 0; Iterator < Rows; Iterator++)
		  {
		    Value = Set_of_Data [Column_Number][Iterator];
		    if ((Value == Minimum_Value) &&
			(Set_of_Data [Columns][Iterator] == 0))
		      {
			Set_of_Data [Columns][Iterator] = 1;
			break;
		      }
		  }
	      }
	  }
      }
    if (Rows/2.0 == floor(Rows/2.0))
      {
	Row_Number = floor(Rows/2);
	Median_Value = (Ordered_Data_Set [Column_Number][Row_Number - 1] + Ordered_Data_Set [Column_Number][Row_Number])/2.0;
      }
    else
      {
	Row_Number = floor(Rows/2.0);
	Median_Value = Ordered_Data_Set [Column_Number][Row_Number];
      }

    return Median_Value;
  }

  // Mode needs to be expanded if there is more than one mode. Possibly return the mode array instead of a single value.
  // This function calculates the mode of a data set.
  double Mode(double** Set_of_Data, int Column_Number) {
    int Mode_Array_Iterator = 0, Maximum_Recurrence = 0;
    double Data_Value = 0, Mode_Value = 0;

    double** Array = Dynamic_Array(2, Rows);
    double** Mode_Array = Set_Array(Array, 2, Rows, 0);

    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	Data_Value = Set_of_Data [Column_Number][Row_Iterator];
	for (int Iterator = 0; Iterator <= Rows; Iterator++)
	  {
	    cout << "DV = " << Data_Value << endl;
	    if (Mode_Array [0][Iterator] == Data_Value)
	    {
	      Mode_Array [1][Iterator] = Mode_Array [1][Iterator] + 1;
	      cout << "Yes 1" << endl;
	    }
	    else if (Iterator == Rows)
	      {
		Mode_Array [0][Mode_Array_Iterator] = Data_Value;
		Mode_Array [1][Mode_Array_Iterator] = Mode_Array [1][Mode_Array_Iterator] + 1;
		Mode_Array_Iterator++;
		cout << "Yes 2" << endl;
	      }
	  }
      }
    for (int Iterator = 0; Iterator < Mode_Array_Iterator; Iterator++)
      {
	if (Iterator == 0)
	  {
	    Maximum_Recurrence = Mode_Array [1][Iterator];
	    Mode_Value = Mode_Array [0][Iterator];
	    cout << "Yes 3" << endl;
	  }
	if (Mode_Array [1][Iterator] > Maximum_Recurrence)
	  {
	    Maximum_Recurrence = Mode_Array [1][Iterator];
	    Mode_Value = Mode_Array [0][Iterator];
	    cout << "Yes 4" << endl;
	  }
      }
    cout << "The mode value was repeated " << Maximum_Recurrence << " times." << endl;
    return Mode_Value;
  }

  double Range(double** Set_of_Data, int Column_Number) {
    double Minimum_Value = 0, Maximum_Value = 0, Value = 0;
    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	if (Row_Iterator == 0)
	  {
	    Value = Set_of_Data [Column_Number][Row_Iterator];
	    Minimum_Value = Value;
	    Maximum_Value = Value;
	  }
	else
	  {
	    if (Set_of_Data [Column_Number][Row_Iterator] < Minimum_Value)
	      {
		Minimum_Value = Set_of_Data [Column_Number][Row_Iterator];
	      }
	    if (Set_of_Data [Column_Number][Row_Iterator] > Maximum_Value)
	      {
		Maximum_Value = Set_of_Data [Column_Number][Row_Iterator];
	      }
	  }
      }
    return (Maximum_Value - Minimum_Value);
}

  //double Standard_Deviation() {};
  //double Standard_Error() {};
  // Other possibilities.
  // chi-squared test
  // Spearmans_Rank
  // Pearsons_Product_Coefficient.

  double Random_Uncertainty(double** Set_of_Data, int Column_Number) {
    int Total_Number_of_Values = 0;
    double Minimum_Value = 0, Maximum_Value = 0, Value = 0;
    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	if (Row_Iterator == 0)
	  {
	    Value = Set_of_Data [Column_Number][Row_Iterator];
	    Minimum_Value = Value;
	    Maximum_Value = Value;
	  }
	else
	  {
	    if (Set_of_Data [Column_Number][Row_Iterator] < Minimum_Value)
	      {
		Minimum_Value = Set_of_Data [Column_Number][Row_Iterator];
	      }
	    if (Set_of_Data [Column_Number][Row_Iterator] > Maximum_Value)
	      {
		Maximum_Value = Set_of_Data [Column_Number][Row_Iterator];
	      }
	  }
	Total_Number_of_Values++;
      }
    return (Maximum_Value - Minimum_Value)/Total_Number_of_Values;
  }

  // Create a subset of data.

  Data_Set Data_Subset(double** Set_of_Data, int Column_Number, double Lower_Bound, double Upper_Bound)
  {
    int Row_Counter = 0, Iterator = 0; 

    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	if ((Set_of_Data [Column_Number][Row_Iterator] >= Lower_Bound) &&
	    (Set_of_Data [Column_Number][Row_Iterator] <= Upper_Bound))
	  {
	    Row_Counter++;
	  } 
      }
    Data_Set Subset (1, Row_Counter);
    return Subset;
  }

  double** Input_Data_Subset(double** Set_of_Data, int Column_Number, double Lower_Bound, double Upper_Bound)
  {
    int Row_Counter = 0, Iterator = 0; 
    
    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	if ((Set_of_Data [Column_Number][Row_Iterator] >= Lower_Bound) &&
	    (Set_of_Data [Column_Number][Row_Iterator] <= Upper_Bound))
	  {
	    Row_Counter++;
	  } 
      }

    double** Array = Dynamic_Array(1, Row_Counter);
    double** Data_Subset_Array = Set_Array(Array, 1, Row_Counter, 0);

    for (int Row_Iterator = 0; Row_Iterator < Rows; Row_Iterator++)
      {
	if ((Set_of_Data [Column_Number][Row_Iterator] >= Lower_Bound) &&
	    (Set_of_Data [Column_Number][Row_Iterator] <= Upper_Bound))
	  {
	    //cout << "***********" << endl;
	    //cout << Set_of_Data [Column_Number][Row_Iterator] << endl;
	    Data_Subset_Array [0][Iterator] = Set_of_Data [Column_Number][Row_Iterator];
	    cout << "**********" << endl;
	    cout << Data_Subset_Array [0][Iterator] << endl;
	    Iterator++;
	  }
      }
    return Data_Subset_Array;
  }

  //double All_Analysis() {};
};

#endif
