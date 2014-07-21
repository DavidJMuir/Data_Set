#include "Data_Set.hh"

int main()
{
  // Manual input.
  Data_Set Numbers(1, 7);
  double** Data = Numbers.Input_Data_Set("Manual");
  double Mean = Numbers.Mean(Data, 0);
  double Median = Numbers.Median(Data, 0);
  double Random_Error = Numbers.Random_Uncertainty(Data, 0);
  double Mode = Numbers.Mode(Data, 0);
  Data_Set Numbers_Subset = Numbers.Data_Subset(Data, 0, 3, 6);
  double** Subset = Numbers.Input_Data_Subset(Data, 0, 3.0, 6.0);
  cout << Mean << endl;
  cout << Median << endl;
  cout << Random_Error << endl;
  cout << Mode << endl;

  Mean = Numbers_Subset.Mean(Subset, 0);
  cout << Mean << endl;

  // File input.
/*
  cout << "File information:" << endl;

  Data_Set Numbers_File(1, 7);
  double** Data_2 = Numbers_File.Input_Data_Set("File");
  Mean = Numbers_File.Mean(Data_2, 0);
  Median = Numbers_File.Median(Data_2, 0);
  Random_Error = Numbers_File.Random_Uncertainty(Data_2, 0);
  cout << Mean << endl;
  cout << Median << endl;
  cout << Random_Error << endl;*/

  // Array input.

  return 0;
}
