#include <iostream>
#include <fstream>
using namespace std;

int findBinary(int dec)
{
    if (dec == 0)
        return 0;
    else
        return dec % 2 + 10 * (findBinary(dec / 2));
}

int main()
{
    string filename, opfile;
    int number;
    int size;
    cin >> size;
    cin >> filename;
    cin >> opfile;
    int arr[size];
    int ct = 0;
    ifstream input_file(filename);
    ofstream output_file(opfile);
    while (input_file >> number && ct < size)
    {
        arr[ct++] = number;
    }
    cout << endl;
    input_file.close();

    int arr_bin[size];
    for (int i = 0; i < size; i++)
    {
        arr_bin[i] = findBinary(arr[i]);
        output_file << arr_bin[i] << " ";
    }

    output_file.close();

    return 0;
}