// Nama : Shri Khubayan Kusuma.
// NIM  : 21300307

#include <iostream>
#include <cmath>

using namespace std;

int mainMenu(), rhombus();
int square(), rectangular(), circle(), tringular(), trapezoid();
// Utility Variables

bool operationType;
string shape;

// -------------------

// Utility Functions

bool circumferenceOrArea(string typeShape)
{
  int menuNumber;

  cout << "Pilih Menu Berikut: \n";
  cout << "\t1. Menghitung Luas " << typeShape << ".\n";
  cout << "\t2. Menghitung Keliling " << typeShape << ".\n";
  cin >> menuNumber;
  switch (menuNumber)
  {
  case 1:
    return operationType = true;
    break;

  case 2:
    return operationType = false;
    break;

  default:
    return false;
  }
}

float partShape(string typeShape, string partShape)
{
  float part;

  cout << "Masukkan Nilai " << partShape << " " << typeShape << " (cm): ";
  cin >> part;

  return part;
}

void stringContent(string typeOperation, string shape, float operationValue)
{
  string unit;
  (typeOperation == "Luas") ? unit = "cm^2" : unit = "cm";
  cout << typeOperation << " " << shape << " tersebut adalah = " << operationValue << " " << unit << "\n";
}

// -------------------

int main()
{
  cout << "Selamat Datang di Program Bangun Datar\n";
  mainMenu();
  return 0;
}

int mainMenu()
{
  int menuNumber;

  cout << "\tSilahkan Pilih Menu Berikut:\n";
  cout << "\t\t1. Persegi\n";
  cout << "\t\t2. Persegi Panjang\n";
  cout << "\t\t3. Lingkaran\n";
  cout << "\t\t4. Segitiga Sama Kaki\n";
  cout << "\t\t5. Belah Ketupat\n";
  cout << "\t\t6. Trapesium\n";
  cin >> menuNumber;

  switch (menuNumber)
  {
  case 1:
    square();
    break;

  case 2:
    rectangular();
    break;

  case 3:
    circle();
    break;

  case 4:
    tringular();
    break;

  case 5:
    rhombus();
    break;

  case 6:
    trapezoid();
    break;
  }

  return 0;
}

int square()
{
  float sisiPersegi;

  shape = "Persegi";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  sisiPersegi = partShape(shape, "Sisi");
  if (operationType)
  {
    stringContent("Luas", shape, (sisiPersegi * sisiPersegi));
  }
  else if (operationType == false)
  {
    stringContent("Keliling", shape, (sisiPersegi * 4));
  }
  return 0;
}

int rectangular()
{
  float rectL, rectW;

  shape = "Persegi Panjang";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  rectL = partShape(shape, "Panjang");
  rectW = partShape(shape, "Lebar");
  if (operationType)
  {
    stringContent("Luas", shape, (rectL * rectW));
  }
  else if (operationType == false)
  {
    cout << "Keliling " << shape << " tersebut adalah = " << 2 * (rectL + rectW) << " cm.\n";
    stringContent("Keliling", shape, (2 * (rectL + rectW)));
  }
  return 0;
}

int circle()
{
  float r;
  const float phi = 22.0F / 7.0F;

  shape = "Lingkaran";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  r = partShape(shape, "Jari-jari");
  if (operationType)
  {
    stringContent("Luas", shape, (1.0F / 4.0F * phi * pow(r * 2, 2)));
  }
  else if (operationType == false)
  {
    stringContent("Keliling", shape, (2 * phi * r));
  }
  return 0;
}

int tringular()
{
  float base, height, side;

  shape = "Segitiga Sama Kaki";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  base = partShape(shape, "Alas");
  if (operationType)
  {
    height = partShape(shape, "Tinggi");
    stringContent("Luas", shape, (1.0F / 2.0F * base * height));
  }
  else if (operationType == false)
  {
    side = partShape(shape, "Sisi");
    stringContent("Keliling", shape, (base + side * 2));
  }
  return 0;
}

int rhombus()
{
  float side, diagonal = 1;

  shape = "Belah Ketupat";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  if (operationType)
  {
    for (int i = 1; i <= 2; i++)
    {
      diagonal *= partShape(shape, "Diagonal " + to_string(i));
    }
    stringContent("Luas", shape, (diagonal / 2.0F));
  }
  else if (operationType == false)
  {
    side = partShape(shape, "Sisi");
    stringContent("Keliling", shape, (4 * side));
  }
  return 0;
}

int trapezoid()
{
  float base = 0, height, sideValue = 0;

  shape = "Trapesium";
  if (circumferenceOrArea(shape) == false) {
    return 0;
  }
  if (operationType)
  {
    for (int i = 1; i <= 2; i++)
    {
      base += partShape(shape, "Alas " + to_string(i));
    }
    height = partShape(shape, "Tinggi");
    stringContent("Luas", shape, (1.0F / 2.0F * base * height));
  }
  else if (operationType == false)
  {
    for (int i = 1; i <= 4; i++)
    {
      sideValue += partShape(shape, "sisi " + to_string(i));
    }
    stringContent("Keliling", shape, sideValue);
    cout << sideValue;
  }
  return 0;
}