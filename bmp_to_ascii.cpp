// By JimmyRcom
// Program to turn a bitmap into an ASCII image
#pragma pack(1)
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

//http://msdn.microsoft.com/en-us/library/cc230305.aspx
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef long LONG;

//http://msdn.microsoft.com/en-us/library/dd183374%28v=VS.85%29.aspx
typedef struct tagBITMAPFILEHEADER {
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

//http://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx
typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

//http://msdn.microsoft.com/en-us/library/dd162938(v=vs.85).aspx
typedef struct tagRGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} RGBQUAD;

//http://msdn.microsoft.com/en-us/library/dd183375(v=vs.85).aspx
typedef struct tagBITMAPINFO {
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD          bmiColors[1];
} BITMAPINFO, *PBITMAPINFO;

vector<char> buffer;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

// turn average color into a ascii char
char ascii(unsigned char c){
  if (c>246) return '.';
  else if (c>230) return '`';
  else if (c>220) return ',';
  else if (c>210) return '\'';
  else if (c>200) return '-';
  else if (c>190) return '_';
  else if (c>180) return '"';
  else if (c>170) return ':';
  else if (c>160) return '|';
  else if (c>150) return 'l';
  else if (c>140) return '}';
  else if (c>130) return ']';
  else if (c>120) return '7';
  else if (c>110) return '?';
  else if (c>100) return '2';
  else if (c>90) return 'F';
  else if (c>80) return '9';
  else if (c>70) return '3';
  else if (c>60) return 'E';
  else if (c>40) return 'H';
  else if (c>30) return 'B';
  else if (c>20) return '$';
  else if (c>10) return '&';
  else return '@';
}

int main() {
  ifstream file("will.bmp", ios::binary);
  ofstream output("ascii_art.txt");
  if (!file) return 1;

  //get file size in cross platform way
  file.seekg(0,ios::end);
  streampos length = file.tellg();
  file.seekg(0,ios::beg);
  cout << "length"<< hex <<length <<endl;
  
  // copy file contents into buffer
  buffer.reserve(length); // this is actually more than we need. we
                          // could subtract header sizes
  buffer.assign(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());

  // fill file header structs from buffer
  file_header = (PBITMAPFILEHEADER)(&buffer[0]);
  info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));

  // set width padding
  const int padding = info_header->biWidth % 4;
  cout << "padding" << padding << endl;

  for (unsigned int width=0, height=info_header->biHeight-1;;){
    unsigned int offset=(height*(info_header->biWidth*3)+(height * padding)+ width)+file_header->bfOffBits;
    unsigned char red, green, blue, average;

    blue =buffer[offset];
    green =buffer[offset+1];
    red =buffer[offset+2];
    average = (red+green+blue) / 3;
    
    output << ascii(average);
    width+=3;
    //    cout<< "width " <<width<<" height " <<height<< " offset " << hex <<offset <<" startdata "<<file_header->bfOffBits<< hex <<endl;
    //    printf("%x %x %x average%x %u\n\n",red,green,blue, average,width/3);
    if (width == (info_header->biWidth*3)){
      if (height==0) break;
      width=0;
      height--;
      output << endl;
    }
  }
  return 0;
}



  // cout << buffer[0] << buffer[1] << endl;
  // cout << file_header->bfSize << endl;
  // cout << info_header->biWidth << " " << info_header->biHeight << endl;

  //  cout << endl << "PIXEL: " <<  (static_cast<unsigned char>(buffer[0x2a0a]) & 0xFF) << endl;
