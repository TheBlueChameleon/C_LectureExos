// Endian

#include <stdio.h>
#include <stdint.h>

#pragma pack ( 1 )

typedef struct {
  char     bfType[2];
  uint32_t bfSize;
  uint32_t bfReserved;
  uint32_t bfOffBits;
  
  uint32_t biSize;
   int32_t biWidth;
   int32_t biHeight;
  uint16_t biPlanes;
  uint16_t biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
   int32_t biXPelsPerMeter;
   int32_t biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
} bmp_header_t;


int main () {
  FILE * hFile = fopen("bitmap.bmp", "r");
  
  printf("%ld\n", sizeof(bmp_header_t) );
  
  bmp_header_t header;
  
  fread(&header, sizeof(bmp_header_t), 1, hFile);
  
  printf("Signature   : %c%c\n", header.bfType[0], header.bfType[1]);
  printf("File Size   : %d\n"  , header.bfSize);
  printf("Offset Bytes: %d\n"  , header.bfOffBits);
  printf("(Reserved)  : %d\n"  , header.bfReserved);
  printf("\n");
  
  printf("Size        : %d\n"  , header.biSize);
  printf("Width       : %d\n"  , header.biWidth);
  printf("Height      : %d\n"  , header.biHeight);
  printf("Planes      : %d\n"  , header.biPlanes);
  printf("BitCount    : %d\n"  , header.biBitCount);
  printf("Compression : %d\n"  , header.biCompression);
  printf("SizeImage   : %d\n"  , header.biSizeImage);
  printf("X_Pix/Meter : %d\n"  , header.biXPelsPerMeter);
  printf("Y_Pix/Meter : %d\n"  , header.biYPelsPerMeter);
  printf("Used Colours: %d\n"  , header.biClrUsed);
  printf("Importatnt C: %d\n"  , header.biClrImportant);
  
  fclose(hFile);
}
