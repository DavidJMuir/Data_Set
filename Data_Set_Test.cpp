#include "Data_Set.hh"

int main()
{
  const char* Name;

  /****************************************************************************/
  // Manual input.
  /****************************************************************************/

  Data_Set Numbers(1, 7);
  double** Data = Numbers.Input_Data_Set("Manual", "Nothing");
  double Mean = Numbers.Mean(Data, 1);
  double Median = Numbers.Median(Data, 1);
  double Random_Error = Numbers.Random_Uncertainty(Data, 1);
  double Mode = Numbers.Mode(Data, 1);
  Data_Set Numbers_Subset = Numbers.Data_Subset(Data, 1, 3, 6);
  double** Subset = Numbers.Input_Data_Subset(Data, 1, 3.0, 6.0);
  double Population_Variance = Numbers.Population_Variance(Numbers, Data, 1);
  double Sample_Variance = Numbers.Sample_Variance(Numbers, Data, 1);
  double Population_Standard_Deviation = Numbers.Population_Standard_Deviation(Numbers, Data, 1);
  double Sample_Standard_Deviation = Numbers.Sample_Standard_Deviation(Numbers, Data, 1);

  cout << "Manual Input" << endl;
  cout << "Mean: " << Mean << endl;
  cout << "Median: " << Median << endl;
  cout << "Random Uncertainty: " << Random_Error << endl;
  cout << "Mode: " << Mode << endl;
  cout << "Population Variance: " << Population_Variance << endl;
  cout << "Population Standard Deviation: " << Population_Standard_Deviation << endl;
  cout << "Sample Variance: " << Sample_Variance << endl;
  cout << "Sample Standard Deviation: " << Sample_Standard_Deviation << endl;

  Mean = Numbers_Subset.Mean(Subset, 1);
  cout << "Mean Subset: " << Mean << endl;

  Name = "Numbers.txt";
  Numbers.All_Analysis(Numbers, Data, 1, Name);
  
  /****************************************************************************/
  // File input.
  /****************************************************************************/
  
  Data_Set Numbers_File(4, 7);
  double** Data_2 = Numbers_File.Input_Data_Set("File", "File_Input.txt");
  Mean = Numbers_File.Mean(Data_2, 4);
  Median = Numbers_File.Median(Data_2, 4);
  Random_Error = Numbers_File.Random_Uncertainty(Data_2, 4);
  // Mode = Numbers_File.Mode(Data_2, 1);

  cout << "File Input" << endl;
  cout << "Mean: " << Mean << endl;
  cout << "Median: " << Median << endl;
  cout << "Random Uncertainty: " << Random_Error << endl;
  //cout << "Mode: " << Mode << endl;

  // Array input.

  return 0;
}
