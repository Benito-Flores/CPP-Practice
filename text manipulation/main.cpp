#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  // read in from file
  ifstream inFile;
  inFile.open("Images.txt");

  // check if file could open
  if (inFile.fail()) {
    cout << "Could not open file" << endl;
  }

  cout << setw(30) << left << "Name" << setw(6) << left << "Type" << setw(6)
       << left << "Width" << setw(7) << left << "Height" << setw(6) << left
       << "Size(kB)" << endl;

  // size variable for end of loop calculation
  double totalSize;

  // read in lines from file
  while (!inFile.eof()) {
    string link, trash;
    double bytes;
    // read next line
    inFile >> link >> trash >> bytes;
    if (inFile.fail())
      break;

    // separate name from link
    string linkName = link;
    string::size_type linkNamePosition = linkName.find("thumbs");
    linkName.erase(0, linkNamePosition + 7);
    string::size_type nameLength = linkName.find('?');
    linkName.erase(nameLength);

    // separate file extension from link
    string extensionName = link;
    extensionName.erase(0, linkNamePosition + 7);
    string::size_type fileLength1 = extensionName.find('.');
    extensionName.erase(0, fileLength1 + 1);
    string::size_type fileLength2 = extensionName.find('?');
    extensionName.erase(fileLength2);

    // separate width from link
    string width = link;
    string::size_type widthStart = width.find('?');
    string::size_type widthEnd = width.find('x');
    width = width.substr(widthStart + 1, widthEnd - widthStart - 1);

    // seperate height from link
    string height = link;
    string::size_type heightStart = height.find('x');
    height.erase(0, heightStart + 1);

    // calculate size
    double size;
    const double KILOBYTE = 1024;
    size = bytes / KILOBYTE;
    // calculate total size
    totalSize += size;

    // print name, type, width, height, and size
    cout << setw(30) << left << linkName << setw(6) << left << extensionName
         << setw(6) << left << width << setw(7) << left << height << setw(6)
         << left << fixed << setprecision(1) << size << endl;
  }
  // print total size
  cout << setw(49) << left << "Total Size:" << totalSize << endl;

  return 0;
}