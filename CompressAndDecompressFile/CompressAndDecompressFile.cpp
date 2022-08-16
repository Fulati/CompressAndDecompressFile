#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void decompress_file(string file)
{
  string line;
  string sub1;
  string sub2;
  stringstream ss;
  stringstream helper;
  int character;
  int amount = 0;
  ifstream infile(file);
  ofstream outfile("decompressed.txt");


  if (infile && outfile)
  {
    while (getline(infile, line))
    {
      ss.clear();
      //cout << line << endl;
      ss << line;

      while (ss >> character >> amount) {
        outfile << string(amount, static_cast<char>(character));
      }


      /*

      while(getline(ss,sub1 , ' ')&&getline(ss,sub2, ' '))
      {
          helper.clear();
          helper << sub1;
          helper >> character;
          helper.clear();
          helper << sub2;
          helper >> amount;
          cout << character << " " << amount << endl;


          outfile << string(amount, static_cast<char>(character));
      }

      */
      outfile << endl;
    }
  }
}

void compress_file(string file)
{
  string line;
  string compressed_line;
  ifstream infile(file);
  ofstream outfile("compressed.txt");
  int current_letter;
  int counter = 0;


  if (infile && outfile)
  {
    //current_letter = infile.peek();
    while (getline(infile, line))
    {
      current_letter = line.at(0);
      for (int i = 0; i < line.size(); i++)
      {
        if (line.at(i) == current_letter)
        {
          counter++;
        }
        else
        {
          outfile << current_letter << ' ' << counter << ' ';
          current_letter = line.at(i);
          counter = 1;
        }
      }
      outfile << current_letter << ' ' << counter << ' ';
      counter = 0;
      outfile << endl;
    }
  }

}

int main()
{
  string fname;
  cout << "Please enter a file name that you would like to compress. (include .txt)";
  cin >> fname;
  compress_file(fname);

  cout << "Please enter a file name that you would like to decompress. (include .txt)";
  cin >> fname;
  decompress_file(fname);

  return 0;
}
